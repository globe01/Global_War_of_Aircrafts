#include "gundam_reverse.h"
#include "config.h"

Gundam_reverse::Gundam_reverse()
{
    //初始化加载高达
    m_gundam_reverse.load(GUNDAMREVERSE_PATH);

    //初始化坐标
    m_X=0;
    m_Y=0;

    //初始化矩形边框
    m_Rect.setWidth(m_gundam_reverse.width());
    m_Rect.setHeight(m_gundam_reverse.height());
    m_Rect.moveTo(m_X,m_Y);

    //空闲状态
    m_Free=false;
}

void Gundam_reverse::shoot()
{
    if(m_Free==true){
        return;
    }
    else{
        //发射
        m_goldenballreverse_specific.updatePosition();
    }
}
