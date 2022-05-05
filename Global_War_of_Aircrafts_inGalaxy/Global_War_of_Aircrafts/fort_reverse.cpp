#include "fort_reverse.h"
#include"config.h"

fort_reverse::fort_reverse()
{
    //初始化加载炮台（反）
    m_fort_reverse.load(FORTREVERSE_PATH);

    //初始化坐标
    m_X=GAME_WIDTH*0.5;
    m_Y=0;

    //初始化矩形边框
    m_Rect.setWidth(m_fort_reverse.width());
    m_Rect.setHeight(m_fort_reverse.height());
    m_Rect.moveTo(m_X,m_Y);

    //空闲状态
    m_Free=false;
}

