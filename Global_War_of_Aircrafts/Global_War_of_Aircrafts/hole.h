#ifndef HOLE_H
#define HOLE_H
#include"config.h"
#include<QPixmap>

class Hole
{
public:
    Hole();

public:
    //洞对象
    QPixmap m_hole;

    //洞坐标
    int m_X;
    int m_Y;

    //包围洞外部的矩形边框
    QRect m_Rect;


    //空闲状态
    bool m_Free;

};

#endif // HOLE_H
