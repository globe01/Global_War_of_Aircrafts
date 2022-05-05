#include "gundam.h"
#include "config.h"
#include "golden_ball.h"

Gundam::Gundam()
{
    //初始化加载高达
    m_gundam.load(GUNDAM_PATH);

    //初始化坐标
    m_X=0;
    m_Y=GAME_HEIGHT-m_gundam.height();

    //初始化矩形边框
    m_Rect.setWidth(m_gundam.width());
    m_Rect.setHeight(m_gundam.height());
    m_Rect.moveTo(m_X,m_Y);

    //空闲状态
    m_Free=false;


}

void Gundam::shoot()
{
    if(m_Free==true){
        return;
    }
    else{
        //发射
        m_goldenball_specific.updatePosition();
    }
}
