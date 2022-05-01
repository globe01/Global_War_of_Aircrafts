#ifndef UFO_AIRCRAFT_H
#define UFO_AIRCRAFT_H
#include<QPixmap>
#include<QRect>
#include"bullet.h"

class UFO_aircraft
{
public:
    UFO_aircraft();


    //发射子弹
    void shoot();

    //设置飞机位置
    void setPosition(int x,int y);

public:
    //飞机对象
    QPixmap m_aircraft;
    //飞机坐标
    int m_X;
    int m_Y;

    //包围飞机外部的矩形边框
    QRect m_Rect;

    //弹匣
    Bullet m_bullets[BULLET_NUM];

    //发射间隔
    int m_recorder;

    //防御值
    int m_life;

    //空闲状态
    bool m_Free;

};

#endif // UFO_AIRCRAFT_H
