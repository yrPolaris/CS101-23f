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
    NONE,
    SEED_PEASHOOTER,
    SEED_REPEATER,
    SEED_CHERRY_BOMB,
    SEED_SUNFLOWER,
    SEED_WALLNUT,
    SHOVEL
  };

  void SetHP(int hp)
  {
    m_hp = hp;
  }

  int GetHP()
  {
    return m_hp;
  }

  int Getdamage()
  {
    return m_damage;
  }

  pGameWorld GetWorld()
  {
    return m_world;
  }

  enum class Type
  {
    ZOMBIE,
    PLANT,
    OTHER,
    PEA,
    EXPLOSION
  };

  Type GetType()
  {
    return m_type;
  }

  void SetType(Type type)
  {
    m_type = type;
  }


private:
  pGameWorld m_world;
  int m_hp;
  int m_damage;
  Type m_type;
};

#include "GameWorld.hpp"
#endif // !GAMEOBJECT_HPP__
