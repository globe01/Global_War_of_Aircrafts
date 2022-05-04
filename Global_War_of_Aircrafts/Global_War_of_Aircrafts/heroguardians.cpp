#include "heroguardians.h"
#include"config.h"

HeroGuardians::HeroGuardians()
{
    //英雄守护者资源加载
    m_guardian.load(GUARDIAN_PATH);

    //位置
    m_X=0;
    m_Y=0;

    //状态
    m_Free=true;

    //移速
    m_Speed=GUARDIAN_SPEED;

    //矩形框
    m_Rect.setWidth(m_guardian.width());
    m_Rect.setHeight(m_guardian.height());
    m_Rect.moveTo(m_X,m_Y);


}

void HeroGuardians::updatePosition()
{
    //空闲时不动，不用算坐标
    if(m_Free){
        return;
    }
    m_X+=m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    //如果超出屏幕，重置
    if(m_X>=GAME_WIDTH){
        m_Free=true;
    }

}
