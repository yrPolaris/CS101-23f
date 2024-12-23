#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "ObjectBase.hpp"
#include "utils.hpp"



// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject>
{
public:
  using std::enable_shared_from_this<GameObject>::shared_from_this; // Use shared_from_this() instead of "this".
  GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID,pGameWorld world,int hp,int damage);

  virtual void Update() = 0;
  virtual void OnClick() = 0;

  enum class Seed_type
  {
      IMGID_NONE,
      IMGID_SEED_PEASHOOTER,
      IMGID_SEED_REPEATER,
      IMGID_SEED_CHERRY_BOMB,
      IMGID_SEED_SUNFLOWER,
      IMGID_SEED_WALLNUT,
  };

  void SetHP(int hp)
  {
    m_hp = hp;
  }

  int GetHP()
  {
    return m_hp;
  }


  pGameWorld GetWorld()
  {
    return m_world;
  }



private:
  pGameWorld m_world;
  int m_hp;
  int m_damage;
};

#include "GameWorld.hpp"
#endif // !GAMEOBJECT_HPP__
