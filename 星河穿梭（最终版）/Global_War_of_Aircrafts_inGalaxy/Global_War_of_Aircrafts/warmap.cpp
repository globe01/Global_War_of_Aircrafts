#include "warmap.h"
#include "config.h"

WarMap::WarMap()
{
    //初始化背景地图
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);
    m_map3.load(":/scene/resources/background(1).jpg");
    m_map4.load(":/scene/resources/victory_background(1).jpg");

    //初始化X轴坐标
    m_map1_posX=-GAME_WIDTH;
    m_map2_posX=0;
    m_map3_posX=0;
    m_map4_posX=0;

    //背景地图滚动速度
    m_scoll_speed=MAP_SCOLL_SPEED;



}

void WarMap::mapPosition()
{
    //第一张
    m_map1_posX+=m_scoll_speed;
    if(m_map1_posX>=0)
    {
        m_map1_posX=-GAME_WIDTH;
    }
    //第二张
    m_map2_posX+=m_scoll_speed;
    if(m_map2_posX>=GAME_WIDTH)
    {
        m_map2_posX=0;
    }
}
