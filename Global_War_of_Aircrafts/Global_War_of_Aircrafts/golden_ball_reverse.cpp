#include "golden_ball_reverse.h"
#include"golden_ball_reverse.h"

Golden_ball_reverse::Golden_ball_reverse()
{
    //加载金球
    m_goldenballreverse.load(GOLDEN_PATH);

    //金球坐标
    m_X=550;
    m_Y=238;

    //金球方向
    m_Direction= true;  //默认向下


    //金球移速
    m_SpeedX=GOLDEN_SPEEDX;
    m_SpeedY=GOLDEN_SPEEDY;

    //金球边框
    m_Rect.setWidth(m_goldenballreverse.width());
    m_Rect.setHeight(m_goldenballreverse.height());
    m_Rect.moveTo(m_X,m_Y);

    //闲置状态
    m_Free=false; //默认不闲置
}

void Golden_ball_reverse::updatePosition()
{
    if(m_Free==true){       //闲置时，无需计算坐标
        return;
    }

    else{

        if(m_Direction==true){
            m_Y+=m_SpeedY;
            m_X+=m_SpeedX;
            m_Rect.moveTo(m_X,m_Y);
        }
        else if(m_Direction==false){
            m_Y-=m_SpeedY;
            m_X-=m_SpeedX;
            m_Rect.moveTo(m_X,m_Y);
        }


        //激光碰到地图右边后改成第2路径
        if(m_X>=1400 ){
            m_Direction=false; //改成第2路径
        }

        if(m_X<=0 ){
            m_Direction=true;  //改成第1路径
        }

    }
}
