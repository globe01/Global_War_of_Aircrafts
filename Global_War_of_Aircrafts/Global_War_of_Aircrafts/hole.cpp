#include "hole.h"
#include"config.h"

Hole::Hole()
{
    //初始化加载高达
    m_hole.load(HOLE_PATH);

    //初始化坐标
    m_X=0;
    m_Y=(GAME_HEIGHT-m_hole.height())*0.5;

    //初始化矩形边框
    m_Rect.setWidth(m_hole.width());
    m_Rect.setHeight(m_hole.height());
    m_Rect.moveTo(m_X,m_Y);

    //空闲状态
    m_Free=false;
}
