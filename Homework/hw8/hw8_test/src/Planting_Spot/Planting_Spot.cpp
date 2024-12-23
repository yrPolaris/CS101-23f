#include "Planting_Spot.hpp"


Planting_Spot::Planting_Spot(int x, int y, pGameWorld world)
    : GameObject(IMGID_NONE,x,y,LAYER_UI,60,80,ANIMID_NO_ANIMATION,world,1,0){}

void Planting_Spot::Update(){}

void Planting_Spot::OnClick()
{
    // switch(GetWorld()->get_click())
    // {
    //     case GameObject::Seed_type::IMGID_NONE:
    //         break;
    //     case  GameObject::Seed_type::IMGID_SEED_SUNFLOWER:
    //         GetWorld()->Add(std::make_shared<Sunflower>(GetX(),GetY(),GetWorld()));
    //         GetWorld()->set_click(GameObject::Seed_type::IMGID_NONE);
    //         break;
    //     case  GameObject::Seed_type::IMGID_SEED_PEASHOOTER:
    //         GetWorld()->Add(std::make_shared<Peashooter>(GetX(),GetY(),GetWorld()));
    //         GetWorld()->set_click(GameObject::Seed_type::IMGID_NONE);
    //         break;
    //     case  GameObject::Seed_type::IMGID_SEED_WALLNUT:
    //         GetWorld()->Add(std::make_shared<Wallnut>(GetX(),GetY(),GetWorld()));
    //         GetWorld()->set_click(GameObject::Seed_type::IMGID_NONE);
    //         break;
    //     case  GameObject::Seed_type::IMGID_SEED_CHERRY_BOMB:
    //         GetWorld()->Add(std::make_shared<Cherrybomb>(GetX(),GetY(),GetWorld()));
    //         GetWorld()->set_click(GameObject::Seed_type::IMGID_NONE);
    //         break;
    //     case  GameObject::Seed_type::IMGID_SEED_REPEATER:
    //         GetWorld()->Add(std::make_shared<Repeater>(GetX(),GetY(),GetWorld()));
    //         GetWorld()->set_click(GameObject::Seed_type::IMGID_NONE);
    //         break;
    // }
}





