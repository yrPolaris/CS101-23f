#include "GameWorld.hpp"
#include "Seed.hpp"
#include "Planting_Spot.hpp"


GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init()
{
  SetTime(0);
  SetWave(0);
  SetSun(500);
  set_click(GameObject::Seed_type::IMGID_NONE);
  container.push_back(std::make_shared<Background>(shared_from_this()));
  for(int y = FIRST_ROW_CENTER; y<=FIRST_ROW_CENTER+LAWN_GRID_HEIGHT*4; y+=LAWN_GRID_HEIGHT)
  {
    for(int x= FIRST_COL_CENTER; x<=FIRST_COL_CENTER+LAWN_GRID_WIDTH*8; x+=LAWN_GRID_HEIGHT)
    { 
      container.push_back(std::make_shared<Planting_Spot>(x,y,shared_from_this()));
    }
  }

  container.push_back(std::make_shared<Sunflowerseed>(shared_from_this()));
  container.push_back(std::make_shared<Peashooterseed>(shared_from_this()));
  container.push_back(std::make_shared<Wallnutseed>(shared_from_this()));
  container.push_back(std::make_shared<Cherrybombseed>(shared_from_this()));
  container.push_back(std::make_shared<Repeaterseed>(shared_from_this()));
}

LevelStatus GameWorld::Update()
{
  count();
  if(GetTime()%300 == 180)
  {
    container.push_back(std::make_shared<Sun>(randInt(75, WINDOW_WIDTH - 75),WINDOW_HEIGHT-1,shared_from_this(),Sun::Fall_type::WORLD)); 
  }
  for(auto i : container)
  {
    i->Update();
    // if(i->GetHP() <= 0)
    // {
    //   i = container.erase(i);
    // }
  }
  // if (GetWave() <= 22)
  // {
  //   if(GetTime() == 1200)
  //   {
  //     container.push_back(std::make_shared<Zombie>(shared_from_this()));
  //     SetWave(GetWave()+1);
  //   }
  //   if(GetTime()-1200-((580+600-20*GetWave())/2)*GetWave()==0)
  //   {
  //     container.push_back(std::make_shared<Zombie>(shared_from_this()));
  //   }
  // }


  // YOUR CODE HERE

  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
  container.clear();
}
