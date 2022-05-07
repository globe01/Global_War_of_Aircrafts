#ifndef FORT_REVERSE_H
#define FORT_REVERSE_H
#include<QPixmap>
#include<QRect>

class fort_reverse
{
public:
    fort_reverse();



public:
    //炮台对象
    QPixmap m_fort_reverse;

    //炮台坐标
    int m_X;
    int m_Y;

    //包围炮台外部的矩形边框
    QRect m_Rect;



    //空闲状态
    bool m_Free;


};

#endif // FORT_REVERSE_H
