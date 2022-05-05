#ifndef GUNDAM_REVERSE_H
#define GUNDAM_REVERSE_H
#include<QPixmap>
#include<QRect>

class Gundam_reverse
{
public:
    Gundam_reverse();

public:
    //高达对象
    QPixmap m_gundam_reverse;

    //高达坐标
    int m_X;
    int m_Y;

    //包围高达外部的矩形边框
    QRect m_Rect;



    //空闲状态
    bool m_Free;
};

#endif // GUNDAM_REVERSE_H
