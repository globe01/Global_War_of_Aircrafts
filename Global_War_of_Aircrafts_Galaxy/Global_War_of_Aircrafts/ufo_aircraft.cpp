#include "ufo_aircraft.h"
#include "config.h"


UFO_aircraft::UFO_aircraft()
{
    //初始化加载飞行器
    m_aircraft.load(UFO_PATH);

    //初始化坐标
    m_X=(GAME_WIDTH-m_aircraft.width());
    m_Y=((GAME_HEIGHT-m_aircraft.height())*0.5);

    //初始化矩形边框
    m_Rect.setWidth(m_aircraft.width());
    m_Rect.setHeight(m_aircraft.height());
    m_Rect.moveTo(m_X,m_Y);

    //防御值
    m_life=UFO_LIFE;

    //空闲状态
    m_Free=false;

    m_Victory=false;

}


void UFO_aircraft::setPosition(int x, int y)
{
    m_X=x;
    m_Y=y;
    m_Rect.moveTo(m_X,m_Y);
}

void UFO_aircraft::shoot()
{

    //累加时间间隔
    m_recorder++;

    //记录数字未达到发射子弹时间间隔，不发射
   if( m_recorder<BULLET_INTERVAL){
       return;
   }

   //达到发射时间
   m_recorder=0;
   //发射
   for(int i=0;i<BULLET_NUM;i++){
       //若为闲置子弹则发射
       if(m_bullets[i].m_Free){
           m_bullets[i].m_Free=false;//状态改为发射
           //设置子弹坐标
           m_bullets[i].m_X=m_X;
           m_bullets[i].m_Y=m_Y+m_Rect.height()*0.5;
           break;               //发射出一颗子弹之后退出循环
       }
   }
}
