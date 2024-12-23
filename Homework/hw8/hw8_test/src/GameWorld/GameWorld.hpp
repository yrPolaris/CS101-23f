#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "Background.hpp"
#include "WorldBase.hpp"
#include "Sun.hpp"
#include "utils.hpp"
#include "GameObject.hpp"

class GameObject;
class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld>
{
public:
  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;


  GameObject::Seed_type get_click()
  {
    return m_click;
  }

  void set_click(GameObject::Seed_type something)
  {
    m_click = something;
  }

  void SetTime(int t)
  {
    time = t;
  }

  void count()
  {
    time++;
  }

  int GetTime()
  {
    return time;
  }

  void Add(std::shared_ptr<GameObject> object)
  {
    container.push_back(object);
  }

private:
  std::list<std::shared_ptr<GameObject>> container;
  int time;
  GameObject::Seed_type m_click;
};

#endif // !GAMEWORLD_HPP__
