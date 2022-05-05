#ifndef GUNDAM_REVERSE_H
#define GUNDAM_REVERSE_H
#include<QPixmap>
#include<QRect>
#include"golden_ball_reverse.h"

class Gundam_reverse
{
public:
    Gundam_reverse();

    //发射激光
    void shoot();

public:
    //高达对象
    QPixmap m_gundam_reverse;

    //高达坐标
    int m_X;
    int m_Y;

    //包围高达外部的矩形边框
    QRect m_Rect;

    //金球对象
    Golden_ball_reverse m_goldenballreverse_specific;


    //空闲状态
    bool m_Free;
};

#endif // GUNDAM_REVERSE_H
