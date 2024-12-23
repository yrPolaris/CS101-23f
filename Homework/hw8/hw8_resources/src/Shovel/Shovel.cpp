#include "Shovel.hpp"

Shovel::Shovel(pGameWorld world)
    : GameObject(IMGID_SHOVEL,600,WINDOW_HEIGHT-40,LAYER_UI,50,50,ANIMID_NO_ANIMATION,world,1,0){}

void Shovel::Update(){}

void Shovel::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::SHOVEL)
    {
        GetWorld()->set_click(GameObject::Seed_type::NONE);
    }
    else if(GetWorld()->get_click() == GameObject::Seed_type::NONE)
    {
        GetWorld()->set_click(GameObject::Seed_type::SHOVEL);
    }
}







