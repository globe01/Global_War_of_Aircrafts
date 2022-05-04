#ifndef FORT_H
#define FORT_H
#include<QPixmap>
#include<QRect>

class Fort
{
public:
    Fort();


    //发射激光
    void shoot();

public:
    //炮台对象
    QPixmap m_fort;

    //炮台坐标
    int m_X;
    int m_Y;

    //包围炮台外部的矩形边框
    QRect m_Rect;

    //空闲状态
    bool m_Free;


};

#endif // FORT_H
