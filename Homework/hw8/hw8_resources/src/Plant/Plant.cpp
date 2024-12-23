#include "Plant.hpp"
#include "Pea.hpp"
#include "Explosion.hpp"


Sunflower::Sunflower(int x, int y,pGameWorld world)
    : GameObject(IMGID_SUNFLOWER,x,y,LAYER_PLANTS,60,80,ANIMID_IDLE_ANIM,world,300,0),first_time(randInt(30,600)),time(0)
{
    SetType(GameObject::Type::PLANT);
}

void Sunflower::Update()
{
    time++;
    if((time-first_time) % (600) == 0)
    {
        if(GetHP() > 0)
        {
            GetWorld()->Add(std::make_shared<Sun>(GetX(),GetY(),GetWorld(),Sun::Fall_type::FLOWER));
        }
    }
}

void Sunflower::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::SHOVEL)
    {
        SetHP(0);
        GetWorld()->set_click(GameObject::Seed_type::NONE);
    }
}



Peashooter::Peashooter(int x, int y,pGameWorld world)
    : GameObject(IMGID_PEASHOOTER,x,y,LAYER_PLANTS,60,80,ANIMID_IDLE_ANIM,world,300,0),time(30)
{
    SetType(GameObject::Type::PLANT);
}

void Peashooter::Update()
{
    if (GetHP() > 0)
    {
        if (time < 30)
        {
            time++;
        }
        if(checktime(time))
        {
            if(GetWorld()->existZombie(GetX(),GetY()))
            {
                GetWorld()->Add(std::make_shared<Pea>(GetX()+30,GetY()+20,GetWorld()));
                time = 0;
            }
        }
    }
}

void Peashooter::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::SHOVEL)
    {
        SetHP(0);
        GetWorld()->set_click(GameObject::Seed_type::NONE);
    }
}




Wallnut::Wallnut(int x, int y,pGameWorld world)
    : GameObject(IMGID_WALLNUT,x,y,LAYER_PLANTS,60,80,ANIMID_IDLE_ANIM,world,4000,0)
{
    SetType(GameObject::Type::PLANT);
}

void Wallnut::Update()
{
    if(GetHP() < 4000/3 && GetHP() > 0)
    {
        ChangeImage(IMGID_WALLNUT_CRACKED);
    }
}

void Wallnut::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::SHOVEL)
    {
        SetHP(0);
        GetWorld()->set_click(GameObject::Seed_type::NONE);
    }
}



Cherrybomb::Cherrybomb(int x, int y,pGameWorld world)
    : GameObject(IMGID_CHERRY_BOMB,x,y,LAYER_PLANTS,60,80,ANIMID_IDLE_ANIM,world,4000,0),time(0)
{
    SetType(GameObject::Type::PLANT);
}

void Cherrybomb::Update()
{
    if(GetHP()>0)
    {
        time++;
        if(time == 15)
        {
            SetHP(0);
            reset_time(time);
            GetWorld()->Add(std::make_shared<Explosion>(GetX(),GetY(),GetWorld()));
        }
    }

}

void Cherrybomb::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::SHOVEL)
    {
        SetHP(0);
        GetWorld()->set_click(GameObject::Seed_type::NONE);
    }
}



Repeater::Repeater(int x, int y,pGameWorld world)
    : GameObject(IMGID_REPEATER,x,y,LAYER_PLANTS,60,80,ANIMID_IDLE_ANIM,world,300,0),time(0)
{
    SetType(GameObject::Type::PLANT);
}

void Repeater::Update()
{

    if (GetHP() > 0)
    {
        time++;
        if(time == 25)
        {
            if(GetWorld()->existZombie(GetX(),GetY()))
            {
                GetWorld()->Add(std::make_shared<Pea>(GetX()+30,GetY()+20,GetWorld()));
            }
        }
        if(time == 30)
        {
            if(GetWorld()->existZombie(GetX(),GetY()))
            {
                GetWorld()->Add(std::make_shared<Pea>(GetX()+30,GetY()+20,GetWorld()));
                time = 0;
            }
        }
    }
}

void Repeater::OnClick()
{
    if(GetWorld()->get_click() == GameObject::Seed_type::SHOVEL)
    {
        SetHP(0);
        GetWorld()->set_click(GameObject::Seed_type::NONE);
    }
}


