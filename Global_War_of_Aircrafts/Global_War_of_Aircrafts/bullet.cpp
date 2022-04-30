#include "bullet.h"

Bullet::Bullet()
{
    //加载子弹
    m_Bullet.load(BULLET_PATH);

    //子弹坐标
    m_X=GAME_WIDTH;
    m_X=GAME_HEIGHT*0.5-m_Bullet.height()*0.5;

    //子弹状态
    m_Free= true;//默认闲置

    //子弹移速
    m_Speed=BULLET_SPEED;

    //子弹边框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);
}


void Bullet::updatePosition()
{

    if(m_Free==true){       //闲置时，无需计算坐标
        return;
    }

    //子弹向左移动
    m_X-=m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    //子弹射出屏幕后刷新为闲置状态
    if(m_X<=-m_Bullet.width()){
        m_Free=true;
    }

}
