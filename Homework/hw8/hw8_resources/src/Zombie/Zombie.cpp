#include "Zombie.hpp"

Regular_Zombie::Regular_Zombie(int x, int y, pGameWorld world)
    : GameObject(IMGID_REGULAR_ZOMBIE,x,y,LAYER_ZOMBIES,20,80,ANIMID_WALK_ANIM,world,200,3)
{
    SetType(GameObject::Type::ZOMBIE);
}

void Regular_Zombie::Update()
{

    if(GetHP() > 0 && GetCurrentAnimation() == ANIMID_WALK_ANIM)
    {
        MoveTo(GetX()-1,GetY());
    }
}

void Regular_Zombie::OnClick(){}



Bucket_Head_Zombie::Bucket_Head_Zombie(int x, int y, pGameWorld world)
    : GameObject(IMGID_BUCKET_HEAD_ZOMBIE,x,y,LAYER_ZOMBIES,20,80,ANIMID_WALK_ANIM,world,1300,3)
{
    SetType(GameObject::Type::ZOMBIE);
}

void Bucket_Head_Zombie::Update()
{

    if(GetHP()>0)
    {
        if (GetHP()<=200)
        {
            ChangeImage(IMGID_REGULAR_ZOMBIE);
        }

        if(GetCurrentAnimation() == ANIMID_WALK_ANIM)
        {
            MoveTo(GetX()-1,GetY());
        } 
    }
}

void Bucket_Head_Zombie::OnClick(){}



Pole_Vaulting_Zombie::Pole_Vaulting_Zombie(int x, int y, pGameWorld world)
    : GameObject(IMGID_POLE_VAULTING_ZOMBIE,x,y,LAYER_ZOMBIES,20,80,ANIMID_RUN_ANIM,world,200,3)
{
    SetType(GameObject::Type::ZOMBIE);
}

void Pole_Vaulting_Zombie::Update(){}

void Pole_Vaulting_Zombie::OnClick(){}









