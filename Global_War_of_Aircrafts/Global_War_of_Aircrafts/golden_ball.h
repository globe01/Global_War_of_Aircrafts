#ifndef GOLDEN_BALL_H
#define GOLDEN_BALL_H

#include"config.h"
#include<QPixmap>


class Golden_ball
{
public:
    Golden_ball();

    //金球坐标一直在变化，更新坐标
    void updatePosition();

public:
    //金球对象
    QPixmap m_goldenball;

    //坐标
    int m_X;
    int m_Y;

    //移速
    int m_SpeedX;
    int m_SpeedY;

    //方向
    bool m_Direction;


    //是否闲置
    bool m_Free;

    //外围矩形边框,是否击中目标可用边框来检测
    QRect m_Rect;

};

#endif // GOLDEN_BALL_H
