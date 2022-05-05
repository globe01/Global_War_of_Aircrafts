#include "bomb.h"

Bomb::Bomb()
{
    //所有图放到数组里
    for(int i=0;i<=BOMB_MAX;i++){
        QString str=QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }

    //坐标
    m_X=0;
    m_Y=0;

    //空闲状态
    m_Free=true;

    //当前图片下标
    m_index=0;

    //播放间隔
    m_Recorder=0;



}

void Bomb::updateInfo()
{
    //空闲时不爆炸
    if(m_Free){
        return;
    }
    m_Recorder++;
    //未到达间隔时不切换
    if(m_Recorder<BOMB_INTERVAL){
        return;
    }

    //重置间隔
    m_Recorder=0;

    //切换图片
    m_index++;


    //数组下标大于6，重置
    if(m_index>BOMB_MAX-1){
        m_index=0;
        m_Free=true;
    }
}
