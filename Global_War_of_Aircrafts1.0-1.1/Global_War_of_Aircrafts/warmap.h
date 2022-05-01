#ifndef WARMAP_H
#define WARMAP_H
#include<QPixmap>

class WarMap
{
public:
    WarMap();

    //背景地图滚动坐标计算
    void mapPosition();

public:

    //背景地图
    QPixmap m_map1;
    QPixmap m_map2;

    //背景地图X轴坐标
    int m_map1_posX;
    int m_map2_posX;

    //背景地图滚动速度
    int m_scoll_speed;

};

#endif // WARMAP_H
