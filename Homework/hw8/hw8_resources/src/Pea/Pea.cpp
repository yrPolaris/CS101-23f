#include "Pea.hpp"

Pea::Pea(int x, int y,pGameWorld world)
    : GameObject(IMGID_PEA,x,y,LAYER_PROJECTILES,28,28,ANIMID_NO_ANIMATION,world,1,20)
{
    SetType(GameObject::Type::PEA);
}

void Pea::Update()
{
    if(GetHP() > 0 && GetY() < WINDOW_WIDTH)
    {
        MoveTo(GetX()+8,GetY());
    }

    else if(GetX() >= WINDOW_WIDTH)
    {
        SetHP(0);
    }
}

void Pea::OnClick(){}




