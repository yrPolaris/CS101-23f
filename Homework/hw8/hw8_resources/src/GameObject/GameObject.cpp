#include "GameObject.hpp"


GameObject::GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID,pGameWorld world,int hp,int damage)
    : ObjectBase(imageID, x, y, layer, width, height, animID) ,m_world(world),m_hp(hp),m_damage(damage)
{
    SetType(GameObject::Type::OTHER);
}





