#include "Sun.hpp"
#include "GameObject.hpp"

Sun::Sun(int x, int y, pGameWorld world,Fall_type fall_type)
    : GameObject(IMGID_SUN,x,y,LAYER_SUN,80,80,ANIMID_IDLE_ANIM,world,1,0),m_exist_time(10),m_delete_time(0),m_fall_type(fall_type),m_speed(4)
    {
        if(m_fall_type == Fall_type::WORLD)
        {
            m_exist_time = randInt(63,263);
        }
        else
        {
            m_exist_time = 12;
        }
    }

void Sun::Update()
{
    m_exist_time--;
    if(m_exist_time >= 0)
    {
        if(m_fall_type == Fall_type::WORLD)
        {
            MoveTo(GetX(),GetY()-2);
        }
        else
        {
            MoveTo(GetX()-1,GetY()+m_speed);
            m_speed--;
        }
    }
    else
    {
        m_delete_time++;
        if(m_delete_time == 300)
        {
            SetHP(0);
        }
    }
}
void Sun::OnClick()
{
    SetHP(0);
    GetWorld()->SetSun(GetWorld()->GetSun()+25);
}