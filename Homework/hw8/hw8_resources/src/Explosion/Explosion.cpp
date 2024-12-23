#include "Explosion.hpp"


Explosion::Explosion(int x,int y,pGameWorld world)
    : GameObject(IMGID_EXPLOSION,x,y,LAYER_SUN,3 * LAWN_GRID_WIDTH,3 * LAWN_GRID_HEIGHT,ANIMID_NO_ANIMATION,world,1,2000),exist_time(3)
{
    SetType(GameObject::Type::EXPLOSION);
}

void Explosion::Update()
{
    exist_time--;
    if(exist_time == 0)
    {
        SetHP(0);
    }
}

void Explosion::OnClick(){}








