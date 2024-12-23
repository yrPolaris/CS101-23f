#include "Seed.hpp"

Sunflowerseed::Sunflowerseed(pGameWorld world)
    : GameObject(IMGID_SEED_SUNFLOWER,130,WINDOW_HEIGHT - 44,LAYER_UI,50,70,ANIMID_NO_ANIMATION,world,1,0),price(50),cooltime(0),seed_type(Seed_type::SEED_SUNFLOWER){}

void Sunflowerseed::Update()
{
    if(getcooltime()>0)
    {
        cooling();
    }
}

void Sunflowerseed::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::NONE)
    {
        if(GetWorld()->GetSun() >= 50 && getcooltime() == 0)
        {
            GetWorld()->set_click(GameObject::Seed_type::SEED_SUNFLOWER);
            cooltime = 240;
            GetWorld()->SetSun(GetWorld()->GetSun()-50);
            GetWorld()->Add(std::make_shared<Cooldownmask>(GetX(),GetY(),cooltime,GetWorld()));
        }
    }
}



Peashooterseed::Peashooterseed(pGameWorld world)
    : GameObject(IMGID_SEED_PEASHOOTER,190,WINDOW_HEIGHT - 44,LAYER_UI,50,70,ANIMID_NO_ANIMATION,world,1,0),price(100),cooltime(0),seed_type(Seed_type::SEED_PEASHOOTER){}

void Peashooterseed::Update()
{
    if(getcooltime()>0)
    {
        cooling();
    }    
}

void Peashooterseed::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::NONE)
    {
        if(GetWorld()->GetSun() >= 100 && getcooltime() == 0)
        {
            GetWorld()->set_click(GameObject::Seed_type::SEED_PEASHOOTER);
            cooltime = 240;
            GetWorld()->SetSun(GetWorld()->GetSun()-100);
            GetWorld()->Add(std::make_shared<Cooldownmask>(GetX(),GetY(),cooltime,GetWorld()));
        }
    }
}



Wallnutseed::Wallnutseed(pGameWorld world)
    : GameObject(IMGID_SEED_WALLNUT,250,WINDOW_HEIGHT - 44,LAYER_UI,50,70,ANIMID_NO_ANIMATION,world,1,0),price(50),cooltime(0),seed_type(Seed_type::SEED_WALLNUT){}

void Wallnutseed::Update()
{
    if(getcooltime()>0)
    {
        cooling();
    }
}

void Wallnutseed::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::NONE)
    {
        if(GetWorld()->GetSun() >= 50 && getcooltime() == 0)
        {
            GetWorld()->set_click(GameObject::Seed_type::SEED_WALLNUT);
            cooltime = 900;
            GetWorld()->SetSun(GetWorld()->GetSun()-50);
            GetWorld()->Add(std::make_shared<Cooldownmask>(GetX(),GetY(),cooltime,GetWorld()));
        }
    }
}



Cherrybombseed::Cherrybombseed(pGameWorld world)
    : GameObject(IMGID_SEED_CHERRY_BOMB,310,WINDOW_HEIGHT - 44,LAYER_UI,50,70,ANIMID_NO_ANIMATION,world,1,0),price(150),cooltime(0),seed_type(Seed_type::SEED_CHERRY_BOMB){}

void Cherrybombseed::Update()
{
    if(getcooltime()>0)
    {
        cooling();
    }
}

void Cherrybombseed::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::NONE)
    {
        if(GetWorld()->GetSun() >= 150 && getcooltime() == 0)
        {
            GetWorld()->set_click(GameObject::Seed_type::SEED_CHERRY_BOMB);
            cooltime = 1200;
            GetWorld()->SetSun(GetWorld()->GetSun()-150);
            GetWorld()->Add(std::make_shared<Cooldownmask>(GetX(),GetY(),cooltime,GetWorld()));
        }
    }
}




Repeaterseed::Repeaterseed(pGameWorld world)
    : GameObject(IMGID_SEED_REPEATER,370,WINDOW_HEIGHT - 44,LAYER_UI,50,70,ANIMID_NO_ANIMATION,world,1,0),price(200),cooltime(0),seed_type(Seed_type::SEED_REPEATER){}

void Repeaterseed::Update()
{
    if(getcooltime()>0)
    {
        cooling();
    }
}

void Repeaterseed::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::NONE)
    {
        if(GetWorld()->GetSun() >= 200 && getcooltime() == 0)
        {
            GetWorld()->set_click(GameObject::Seed_type::SEED_REPEATER);
            cooltime = 240;
            GetWorld()->SetSun(GetWorld()->GetSun()-200);
            GetWorld()->Add(std::make_shared<Cooldownmask>(GetX(),GetY(),cooltime,GetWorld()));
        }
    }
}