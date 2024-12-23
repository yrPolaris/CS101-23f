#include "Seed.hpp"

Sunflowerseed::Sunflowerseed(pGameWorld world)
    : GameObject(IMGID_SEED_SUNFLOWER,130,WINDOW_HEIGHT - 44,LAYER_UI,50,70,ANIMID_NO_ANIMATION,world,1,0),price(50),cooltime(240),seed_type(Seed_type::IMGID_SEED_SUNFLOWER){}

void Sunflowerseed::Update(){cooling();}

void Sunflowerseed::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::IMGID_NONE)
    {
        if(GetWorld()->GetSun() >= 50 && getcooltime() == 240)
        {
            GetWorld()->set_click(GameObject::Seed_type::IMGID_SEED_SUNFLOWER);
            cooltime = 0;
            GetWorld()->SetSun(GetWorld()->GetSun()-50);
        }
    }
}

Peashooterseed::Peashooterseed(pGameWorld world)
    : GameObject(IMGID_SEED_PEASHOOTER,190,WINDOW_HEIGHT - 44,LAYER_UI,50,70,ANIMID_NO_ANIMATION,world,1,0),price(100),cooltime(240),seed_type(Seed_type::IMGID_SEED_PEASHOOTER){}

void Peashooterseed::Update(){cooling();}

void Peashooterseed::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::IMGID_NONE)
    {
        if(GetWorld()->GetSun() >= 100 && getcooltime() == 240)
        {
            GetWorld()->set_click(GameObject::Seed_type::IMGID_SEED_PEASHOOTER);
            cooltime = 0;
            GetWorld()->SetSun(GetWorld()->GetSun()-100);
        }
    }
}

Wallnutseed::Wallnutseed(pGameWorld world)
    : GameObject( IMGID_SEED_WALLNUT,250,WINDOW_HEIGHT - 44,LAYER_UI,50,70,ANIMID_NO_ANIMATION,world,1,0),price(50),cooltime(900),seed_type(Seed_type::IMGID_SEED_WALLNUT){}

void Wallnutseed::Update(){cooling();}

void Wallnutseed::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::IMGID_NONE)
    {
        if(GetWorld()->GetSun() >= 50 && getcooltime() == 900)
        {
            GetWorld()->set_click(GameObject::Seed_type::IMGID_SEED_WALLNUT);
            cooltime = 0;
            GetWorld()->SetSun(GetWorld()->GetSun()-50);
        }
    }
}

Cherrybombseed::Cherrybombseed(pGameWorld world)
    : GameObject(IMGID_SEED_CHERRY_BOMB,310,WINDOW_HEIGHT - 44,LAYER_UI,50,70,ANIMID_NO_ANIMATION,world,1,0),price(150),cooltime(1200),seed_type(Seed_type::IMGID_SEED_CHERRY_BOMB){}

void Cherrybombseed::Update(){cooling();}

void Cherrybombseed::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::IMGID_NONE)
    {
        if(GetWorld()->GetSun() >= 150 && getcooltime() == 1200)
        {
            GetWorld()->set_click(GameObject::Seed_type::IMGID_SEED_CHERRY_BOMB);
            cooltime = 0;
            GetWorld()->SetSun(GetWorld()->GetSun()-150);
        }
    }
}

Repeaterseed::Repeaterseed(pGameWorld world)
    : GameObject(IMGID_SEED_REPEATER,370,WINDOW_HEIGHT - 44,LAYER_UI,50,70,ANIMID_NO_ANIMATION,world,1,0),price(200),cooltime(240),seed_type(Seed_type::IMGID_SEED_REPEATER){}

void Repeaterseed::Update(){cooling();}

void Repeaterseed::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::IMGID_NONE)
    {
        if(GetWorld()->GetSun() >= 200 && getcooltime() == 240)
        {
            GetWorld()->set_click(GameObject::Seed_type::IMGID_SEED_REPEATER);
            cooltime = 0;
            GetWorld()->SetSun(GetWorld()->GetSun()-200);
        }
    }
}