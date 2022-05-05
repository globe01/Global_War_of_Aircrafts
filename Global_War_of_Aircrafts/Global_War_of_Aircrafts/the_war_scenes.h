#ifndef THE_WAR_SCENES_H
#define THE_WAR_SCENES_H

#include <QWidget>
#include<QTimer>
#include"warmap.h"
#include"ufo_aircraft.h"
#include"bullet.h"
#include"heroguardians.h"
#include"bomb.h"
#include"fort.h"
#include"fort_reverse.h"
#include"laser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class The_War_Scenes; }
QT_END_NAMESPACE

class The_War_Scenes : public QWidget
{
    Q_OBJECT

public:
    The_War_Scenes(QWidget *parent = nullptr);
    ~The_War_Scenes();


    //初始化场景
    void initScene();

    //启动游戏
    void playgame();

    //更新所有元素坐标
    void updateEveryPosition();

    //绘制到屏幕上
    void paintEvent(QPaintEvent *);

    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *);


    //英雄守护者出场
    void guardianToScene();

    //英雄守护者数组
    HeroGuardians m_guardians[GUARDIAN_NUM];

    //英雄守护者出场间隔
    int m_recorder;

    //碰撞检测
    void collisionDetection();


    //背景地图对象
    WarMap m_warmap;

    //飞行器对象
    UFO_aircraft m_UFO;

    //炮台对象
    Fort m_fortspecific;

    //炮台对象（反）
    fort_reverse m_fortreversespecific;


    //定时器
    QTimer m_Timer;

    //爆炸数组
    Bomb m_bombs[BOMB_NUM];








private:
    Ui::The_War_Scenes *ui;
};
#endif // THE_WAR_SCENES_H
