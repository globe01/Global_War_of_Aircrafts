#include "fort.h"
#include "config.h"


Fort::Fort()
{
    //初始化加载炮台
    m_fort.load(FORT_PATH);

    //初始化坐标
    m_X=GAME_WIDTH*0.5;
    m_Y=GAME_HEIGHT-m_fort.height();

    //初始化矩形边框
    m_Rect.setWidth(m_fort.width());
    m_Rect.setHeight(m_fort.height());
    m_Rect.moveTo(m_X,m_Y);

    //空闲状态
    m_Free=false;

}

void Fort::shoot()
{

}



