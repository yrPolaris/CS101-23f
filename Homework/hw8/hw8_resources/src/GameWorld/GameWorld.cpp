#include "GameWorld.hpp"
#include "Seed.hpp"
#include "Planting_Spot.hpp"
#include "Zombie.hpp"
#include "Shovel.hpp"



GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init()
{
  SetTime(0);
  SetWave(0);
  SetSun(20000);
  set_click(GameObject::Seed_type::NONE);
  container.push_back(std::make_shared<Background>(shared_from_this()));
  for(int y = FIRST_ROW_CENTER; y<=FIRST_ROW_CENTER+LAWN_GRID_HEIGHT*4; y+=LAWN_GRID_HEIGHT)
  {
    for(int x= FIRST_COL_CENTER; x<=FIRST_COL_CENTER+LAWN_GRID_WIDTH*8; x+=LAWN_GRID_WIDTH)
    { 
      container.push_back(std::make_shared<Planting_Spot>(x,y,shared_from_this()));
    }
  }

  container.push_back(std::make_shared<Sunflowerseed>(shared_from_this()));
  container.push_back(std::make_shared<Peashooterseed>(shared_from_this()));
  container.push_back(std::make_shared<Wallnutseed>(shared_from_this()));
  container.push_back(std::make_shared<Cherrybombseed>(shared_from_this()));
  container.push_back(std::make_shared<Repeaterseed>(shared_from_this()));
  container.push_back(std::make_shared<Shovel>(shared_from_this()));
}

LevelStatus GameWorld::Update()
{
  count();
  P1 = 20;
  P2 = 0;
  Zombie_num = (15+GetWave())/10;
  if(GetTime()%300 == 180)
  {
    container.push_back(std::make_shared<Sun>(randInt(75, WINDOW_WIDTH - 75),WINDOW_HEIGHT-1,shared_from_this(),Sun::Fall_type::WORLD)); 
  }
  

  if (GetWave() <= 22)
  {
    if(GetWave() == 0 && GetTime() == 1200)
    {
      for(int i=0; i<Zombie_num; i++)
      {
        container.push_back(std::make_shared<Regular_Zombie>(randInt(WINDOW_WIDTH-40,WINDOW_WIDTH-1),FIRST_ROW_CENTER+randInt(0,4)*LAWN_GRID_HEIGHT,shared_from_this()));
      }
      SetWave(GetWave()+1);
      SetTime(0);
    }
    else if(GetWave() > 0 && GetTime() == 600-20*GetWave() && GetWave() <= 8)
    {
      for(int i=0; i<Zombie_num; i++)
      {
        container.push_back(std::make_shared<Regular_Zombie>(randInt(WINDOW_WIDTH-40,WINDOW_WIDTH-1),FIRST_ROW_CENTER+randInt(0,4)*LAWN_GRID_HEIGHT,shared_from_this()));
      }
      SetWave(GetWave()+1);
      SetTime(0);
    }
    else if(GetWave() > 8 && GetTime() == 600-20*GetWave())
    {
      P2 = 2*(GetWave()-8);
      for(int i=0; i<Zombie_num; i++)
      {
        if(randInt(0,(P1+P2)-1)<P1)
        {
          container.push_back(std::make_shared<Regular_Zombie>(randInt(WINDOW_WIDTH-40,WINDOW_WIDTH-1),FIRST_ROW_CENTER+randInt(0,4)*LAWN_GRID_HEIGHT,shared_from_this()));
        }
        else if(randInt(0,(P1+P2)-1)>=P1)
        {
          container.push_back(std::make_shared<Bucket_Head_Zombie>(randInt(WINDOW_WIDTH-40,WINDOW_WIDTH-1),FIRST_ROW_CENTER+randInt(0,4)*LAWN_GRID_HEIGHT,shared_from_this()));
        }
      }
      SetWave(GetWave()+1);
      SetTime(0);
    }
  }
  else if(GetWave() >= 23)
  {
    if(GetTime() == 150)
    {
      P2 = 2*(GetWave()-8);
      for(int i=0; i<Zombie_num; i++)
      {
        if(randInt(0,(P1+P2)-1)<P1)
        {
          container.push_back(std::make_shared<Regular_Zombie>(randInt(WINDOW_WIDTH-40,WINDOW_WIDTH-1),FIRST_ROW_CENTER+randInt(0,4)*LAWN_GRID_HEIGHT,shared_from_this()));
        }
        else if(randInt(0,(P1+P2)-1)>=P1)
        {
          container.push_back(std::make_shared<Bucket_Head_Zombie>(randInt(WINDOW_WIDTH-40,WINDOW_WIDTH-1),FIRST_ROW_CENTER+randInt(0,4)*LAWN_GRID_HEIGHT,shared_from_this()));
        }
      }
      SetWave(GetWave()+1);
      SetTime(0);
    } 
  }

  for(auto &it1 : container)
  {
    if(it1->GetType() == GameObject::Type::PLANT)
    {
      for(auto &it2 : container)
      {
        if(it2->GetType() == GameObject::Type::ZOMBIE && it1->GetY() == it2->GetY() && it2->GetX()-(it2->GetWidth())/2 <= it1->GetX()+(it1->GetWidth())/2 && it2->GetX()+(it2->GetWidth())/2 >= it1->GetX()-(it1->GetWidth())/2)
        {
          if(it2->GetCurrentAnimation() == ANIMID_WALK_ANIM)
          {
            it2->PlayAnimation(ANIMID_EAT_ANIM);
          }
          it1->SetHP(it1->GetHP()-3);
        }
      }
    }
  }

  for(auto &it1 : container)
  {
    if(it1->GetType() == GameObject::Type::ZOMBIE)
    {
      for(auto &it2 : container)
      {
        if(it2->GetType() == GameObject::Type::PEA && it1->GetY() == it2->GetY()-20 && it1->GetX()-(it1->GetWidth())/2 <= it2->GetX()+(it2->GetWidth())/2 && it1->GetX()+(it1->GetWidth())/2 >= it2->GetX()-(it2->GetWidth())/2)
        {
          it1->SetHP(it1->GetHP()-20);
          it2->SetHP(0);
        }
      }
    }
  }

  for(auto &it1 : container)
  {
    if(it1->GetType() == GameObject::Type::ZOMBIE)
    {
      for(auto &it2 :container)
      {
        if(it2->GetType() == GameObject::Type::EXPLOSION && it1->GetY()+(it1->GetHeight())/2 >= it2->GetY()-(3*LAWN_GRID_HEIGHT)/2 && it1->GetY()-(it1->GetHeight())/2 <= it2->GetY()+(3*LAWN_GRID_HEIGHT)/2 && it1->GetX()+(it1->GetWidth())/2 >= it2->GetX()-(3*LAWN_GRID_WIDTH)/2 && it1->GetX()-(it1->GetWidth())/2 <= it2->GetX()+(3*LAWN_GRID_WIDTH)/2)
        {
          it1->SetHP(0);
        }
      }
    }
  }



  for(auto it = container.begin(); it != container.end();)
  {
    (*it)->Update();
    if((*it)->GetHP() <= 0)
    {
      it = container.erase(it);
    }
    else
    {
      it++;
    }
  }

  for(auto &it : container)
  {
    if(it->GetType() == GameObject::Type::ZOMBIE)
    {
      if(!(existPlant(it->GetX(),it->GetY())) && it->GetCurrentAnimation() == ANIMID_EAT_ANIM)
      {
        it->PlayAnimation(ANIMID_WALK_ANIM);
      }
    }
  }






  for(auto &it : container)
  {
    if(it->GetType() == GameObject::Type::ZOMBIE && it->GetX() < 0)
    {
      return LevelStatus::LOSING;
    }
  }

  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
  container.clear();
}
