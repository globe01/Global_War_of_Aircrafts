#ifndef HEROGUARDIAN2_H
#define HEROGUARDIAN2_H

#include<QPixmap>

class heroguardian2
{
public:
    heroguardian2();

    //更新坐标
    void updatePosition();
public:
    //英雄守护者对象
    QPixmap m_guardian2;

    //位置
    int m_X;
    int m_Y;

    //英雄守护者的外围矩形边框（用于和子弹碰撞的检测）
    QRect  m_Rect;

    //状态
    bool m_Free;

    //移速
    int m_Speed;

};

#endif // HEROGUARDIAN2_H
