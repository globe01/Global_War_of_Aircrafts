#ifndef BULLET_H
#define BULLET_H

#include"config.h"
#include<QPixmap>

class Bullet
{
public:
    Bullet();

    //子弹坐标一直在变化，更新坐标
    void updatePosition();

public:
    //子弹对象
    QPixmap m_Bullet;

    //坐标
    int m_X;
    int m_Y;

    //移速
    int m_Speed;

    //是否闲置
    bool m_Free;

    //外围矩形边框,是否击中目标可用边框来检测
    QRect m_Rect;

};

#endif // BULLET_H
