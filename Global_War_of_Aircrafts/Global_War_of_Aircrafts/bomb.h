#ifndef BOMB_H
#define BOMB_H

#include"config.h"
#include<QPixmap>
#include<QVector>


class Bomb
{
public:
    Bomb();

    //更新图片
    void updateInfo();

public:
    //爆炸资源
    QVector<QPixmap> m_pixArr;

    //爆炸位置
    int m_X;
    int m_Y;

    //爆炸状态
    bool m_Free;

    //切换间隔
    int m_Recorder;

    //加载图片的下标
    int m_index;


};

#endif // BOMB_H
