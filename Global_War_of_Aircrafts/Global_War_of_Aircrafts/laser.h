#ifndef LASER_H
#define LASER_H

#include"config.h"
#include<QPixmap>


class Laser
{
public:
    Laser();


    //激光坐标一直在变化，更新坐标
    void updatePosition();

public:
    //激光对象
    QPixmap m_Laser;

    //坐标
    int m_X;
    int m_Y;

    //移速
    int m_Speed;

    //是否闲置
    bool m_Direction;

    //外围矩形边框,是否击中目标可用边框来检测
    QRect m_Rect;

};

#endif // LASER_H
