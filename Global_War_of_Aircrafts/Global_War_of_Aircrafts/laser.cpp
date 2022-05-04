#include "laser.h"

Laser::Laser()
{
    //加载激光
    m_Laser.load(LASER_PATH);

    //激光坐标
    m_X=GAME_WIDTH*0.5;
    m_Y=125;

    //激光方向
    m_Direction= true;  //默认向下 true向下 false向上

    //激光移速
    m_Speed=LASER_SPEED;

    //激光边框
    m_Rect.setWidth(m_Laser.width());
    m_Rect.setHeight(m_Laser.height());
    m_Rect.moveTo(m_X,m_Y);
}

void Laser::updatePosition()
{
    if(m_Direction==true){       //向下时，无需计算坐标
        //激光向下移动
        m_Y+=m_Speed;
        m_Rect.moveTo(m_X,m_Y);
    }
    else{
        //激光向上移动
        m_Y-=m_Speed;
        m_Rect.moveTo(m_X,m_Y);
    }
    //激光碰到下面的炮台后改为向上
    if(m_Y>=GAME_WIDTH-800){
        m_Direction=false; //改为向上
    }
    if(m_Y<100){
        m_Direction=true;
    }

}
