#include "the_war_scenes.h"
#include "ui_the_war_scenes.h"
#include "config.h"
#include <QIcon>
#include<QPainter>
#include<QMouseEvent>
#include<ctime>
#include<QSound>

The_War_Scenes::The_War_Scenes(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::The_War_Scenes)
{
    ui->setupUi(this);
    //调用初始化场景
    initScene();

    //启动游戏
    playgame();

}

The_War_Scenes::~The_War_Scenes()
{
    delete ui;
}

void The_War_Scenes::initScene()
{
    //窗口尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //标题
    setWindowTitle(GAME_TITLE);

    //图标
    setWindowIcon(QIcon(GAME_ICON));

    //定时器
    m_Timer.setInterval(GAME_RATE);

    //英雄守护者出场时间间隔初始化
    m_recorder=0;

    //随机数种子
    srand((unsigned int )time(NULL));


}

void The_War_Scenes::playgame()
{
    //bgm
    if(m_UFO.m_Free==false){
        QSound::play(SOUND_BACKGROUND);
    }

    //启动定时器
    m_Timer.start();

    //监听定时器发送的信号
    connect(&m_Timer,&QTimer::timeout,[=](){
        //英雄守护者出场
        guardianToScene();

        //更新所有元素的坐标
        updateEveryPosition();

        //绘制到屏幕上
        update();

        //碰撞检测调用
        collisionDetection();
    });
}

void The_War_Scenes::updateEveryPosition()
{
    //更新背景地图坐标
    m_warmap.mapPosition();

    //发射子弹
    m_UFO.shoot();

    //发射激光
    m_fortspecific.shoot();

    //发射金球
    m_gundamspecific.shoot();


    //计算所有发出子弹的坐标
    for(int i=0;i<BULLET_NUM;i++){
        if(m_UFO.m_bullets[i].m_Free==false){
            m_UFO.m_bullets[i].updatePosition();
        }
    }



    //英雄守护者出场
    for(int i=0;i<GUARDIAN_NUM;i++){
        if(m_guardians[i].m_Free==false){
            m_guardians[i].updatePosition();
        }
    }

    //爆炸播放计算
    for(int i=0;i<BOMB_NUM;i++){
        if(m_bombs[i].m_Free==false){
            m_bombs[i].updateInfo();
        }
    }

}

void The_War_Scenes::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(m_warmap.m_map1_posX,0,m_warmap.m_map1);
    painter.drawPixmap(m_warmap.m_map2_posX,0,m_warmap.m_map2);
    //如果飞行器炸毁，绘制游戏结束
    if(m_UFO.m_Free==true){
        painter.drawPixmap(m_warmap.m_map3_posX,0,m_warmap.m_map3);
        //所有守护者变为空闲
        for(int i=0;i<GUARDIAN_NUM;i++){
            m_guardians[i].m_Free=true;
        }

    }

    //绘制飞行器
    if(m_UFO.m_Free==false){
        painter.drawPixmap(m_UFO.m_X,m_UFO.m_Y,m_UFO.m_aircraft);
    }

    //绘制子弹
    for(int i=0;i<BULLET_NUM;i++){
        if(m_UFO.m_bullets[i].m_Free==false && m_UFO.m_Free==false){
            painter.drawPixmap(m_UFO.m_bullets[i].m_X,m_UFO.m_bullets[i].m_Y,m_UFO.m_bullets[i].m_Bullet);
        }
    }

    //绘制激光
    if(m_fortspecific.m_laser_specific.m_Free==false){
        painter.drawPixmap(m_fortspecific.m_laser_specific.m_X,m_fortspecific.m_laser_specific.m_Y,m_fortspecific.m_laser_specific.m_Laser);
    }

    //绘制金球
    if(m_gundamspecific.m_goldenball_specific.m_Free==false){
        painter.drawPixmap(m_gundamspecific.m_goldenball_specific.m_X,m_gundamspecific.m_goldenball_specific.m_Y,m_gundamspecific.m_goldenball_specific.m_goldenball);
    }


    //绘制炮台
    if(m_fortspecific.m_Free==false)
        painter.drawPixmap(m_fortspecific.m_X,m_fortspecific.m_Y,m_fortspecific.m_fort);

    //绘制炮台（反）
    if(m_fortreversespecific.m_Free==false)
        painter.drawPixmap(m_fortreversespecific.m_X,m_fortreversespecific.m_Y,m_fortreversespecific.m_fort_reverse);

    //绘制高达（下）
    if(m_gundamspecific.m_Free==false)
        painter.drawPixmap(m_gundamspecific.m_X,m_gundamspecific.m_Y,m_gundamspecific.m_gundam);

    //绘制高达（上）
    if(m_gundam_reversespecific.m_Free==false)
        painter.drawPixmap(m_gundam_reversespecific.m_X,m_gundam_reversespecific.m_Y,m_gundam_reversespecific.m_gundam_reverse);


    //绘制英雄守护者
    for(int i=0;i<GUARDIAN_NUM;i++){
        if(m_guardians[i].m_Free==false){
            painter.drawPixmap(m_guardians[i].m_X,m_guardians[i].m_Y,m_guardians[i].m_guardian);
        }
    }


    //绘制爆炸
    for(int i=0;i<BOMB_NUM;i++){
        if(m_bombs[i].m_Free==false){
            painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }


}

void The_War_Scenes::mouseMoveEvent(QMouseEvent *event)
{
    int x= event->x()-m_UFO.m_Rect.width()*0.5;
    int y= event->y()-m_UFO.m_Rect.height()*0.5;

    //边界检测
    if(x<=0){
        x=0;
    }

    if(x>=GAME_WIDTH-m_UFO.m_Rect.width()){
        x=GAME_WIDTH-m_UFO.m_Rect.width();
    }
    if(y<=0){
        y=0;
    }
    if(y>=GAME_HEIGHT-m_UFO.m_Rect.height()){
        y=GAME_HEIGHT-m_UFO.m_Rect.height();
    }



    m_UFO.setPosition(x,y);
}

void The_War_Scenes::guardianToScene()
{
    m_recorder++;
    if(m_recorder<GUARDIAN_INTERVAL){
        return;
    }
    m_recorder=0;
    for(int i=0;i<GUARDIAN_NUM;i++){
        //空闲守护者，出场
        if(m_guardians[i].m_Free){
            m_guardians[i].m_Free=false;
            //坐标
            m_guardians[i].m_X=-m_guardians[i].m_Rect.width();
            m_guardians[i].m_Y=rand()%(GAME_HEIGHT-m_guardians[i].m_Rect.height());
            break;      //出来一个就退出循环
        }
    }
}

void The_War_Scenes::collisionDetection()
{
    for(int i=0;i<GUARDIAN_NUM;i++){
        //空闲的，不用管，继续下一次循环
        if(m_guardians[i].m_Free){
            continue;
        }

        //嵌套子弹的遍历
        for(int j=0;j<BULLET_NUM;j++){
            //空闲的子弹，不用管，继续下一次循环
            if(m_UFO.m_bullets[j].m_Free){
                continue;
            }


            //若碰撞，都转化为空闲，消失
            if(m_guardians[i].m_Rect.intersects(m_UFO.m_bullets[j].m_Rect)){
                m_guardians[i].m_Free=true;
                m_UFO.m_bullets[j].m_Free=true;

                //碰撞后爆炸
                for(int k=0;k<BOMB_NUM;k++){
                    if(m_bombs[k].m_Free){
                        //播放音效1
                        QSound::play(SOUND_BOMB1);

                        m_bombs[k].m_Free=false;

                        //坐标更新
                        m_bombs[k].m_X=m_guardians[i].m_X;
                        m_bombs[k].m_Y=m_guardians[i].m_Y;
                        break;

                    }
                }


            }

            //如果UFO_aircrafts和guardian碰撞,UFO_aircrafts减一点防御
            if(m_guardians[i].m_Rect.intersects(m_UFO.m_Rect)){
                m_guardians[i].m_Free=true;
                m_fortspecific.m_laser_specific.m_Free=true;
                m_fortspecific.m_Free=true;
                m_fortreversespecific.m_Free=true;
                m_UFO.m_life=m_UFO.m_life-1;

                //碰撞后播放爆炸2音效
                for(int k=0;k<BOMB_NUM;k++){
                    if(m_bombs[k].m_Free){
                        //播放音效2
                        QSound::play(SOUND_BOMB2);
                        //播放GAMEOVER音效
                        QSound::play(":/scene/resources/gameover.wav");
                        m_bombs[k].m_Free=false;
                        //坐标更新
                        m_bombs[k].m_X=m_UFO.m_X;
                        m_bombs[k].m_Y=m_UFO.m_Y;
                        break;
                    }
                }
                //判断如果防御值变为0，则UFO_Aircrafts消失
                if(m_UFO.m_life<0){
                    m_UFO.m_Free=true;
                }
            }
        }
    }
    //如果UFO_aircrafts和laser激光球碰撞,UFO_aircrafts减一点防御
    if(m_fortspecific.m_laser_specific.m_Rect.intersects(m_UFO.m_Rect)){
        m_fortspecific.m_Free=true;
        m_fortreversespecific.m_Free=true;
        m_fortspecific.m_laser_specific.m_Free=true;
        m_UFO.m_life=m_UFO.m_life-1;

        //碰撞后播放爆炸2音效
        for(int k=0;k<BOMB_NUM;k++){
            if(m_bombs[k].m_Free){
                //播放音效2
                QSound::play(SOUND_BOMB2);
                //播放GAMEOVER音效
                QSound::play(":/scene/resources/gameover.wav");
                m_bombs[k].m_Free=false;
                //坐标更新
                m_bombs[k].m_X=m_UFO.m_X;
                m_bombs[k].m_Y=m_UFO.m_Y;
                break;
            }
        }
        //判断如果防御值变为0，则UFO_Aircrafts消失
        if(m_UFO.m_life<0){
            m_UFO.m_Free=true;
        }
    }


}

