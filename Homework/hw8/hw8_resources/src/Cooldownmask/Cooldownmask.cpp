#include "Cooldownmask.hpp"


Cooldownmask::Cooldownmask(int x,int y, int time,pGameWorld world)
    :   GameObject(IMGID_COOLDOWN_MASK,x,y,LAYER_COOLDOWN_MASK,50,70,ANIMID_NO_ANIMATION,world,1,0),maskcooltime(time){}

void Cooldownmask::Update()
{
    maskcooltime--;
    if(getmaskcooltime() == 0)
    {
        SetHP(0);
    }
}

void Cooldownmask::OnClick(){}