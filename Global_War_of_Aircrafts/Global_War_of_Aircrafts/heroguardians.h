#ifndef HEROGUARDIANS_H
#define HEROGUARDIANS_H

#include<QPixmap>

class HeroGuardians
{
public:
    HeroGuardians();

    //更新坐标
    void updatePosition();
public:
    //英雄守护者对象
    QPixmap m_guardian;

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

#endif // HEROGUARDIANS_H
