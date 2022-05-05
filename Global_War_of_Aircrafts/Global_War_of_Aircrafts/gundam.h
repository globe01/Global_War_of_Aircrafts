#ifndef GUNDAM_H
#define GUNDAM_H
#include<QPixmap>
#include<QRect>
#include"golden_ball.h"

class Gundam
{
public:
    Gundam();

    //发射激光
    void shoot();

public:
    //高达对象
    QPixmap m_gundam;

    //高达坐标
    int m_X;
    int m_Y;

    //包围高达外部的矩形边框
    QRect m_Rect;

    //金球对象
    Golden_ball m_goldenball_specific;

    //空闲状态
    bool m_Free;

};

#endif // GUNDAM_H
