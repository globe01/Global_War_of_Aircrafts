#ifndef FORT_H
#define FORT_H
#include<QPixmap>
#include<QRect>

class Fort
{
public:
    Fort();

public:
    //炮台对象
    QPixmap m_fort;

    //炮台坐标
    int m_X;
    int m_Y;

    //包围炮台外部的矩形边框
    QRect m_Rect;


};

#endif // FORT_H
