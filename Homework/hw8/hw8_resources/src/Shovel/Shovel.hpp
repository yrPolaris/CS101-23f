#ifndef SHOVEL_HPP__
#define SHOVEL_HPP__

#include "GameObject.hpp"

class Shovel : public GameObject
{
public:
    Shovel(pGameWorld world);
    void Update() override;
    void OnClick() override;

};



#endif // !SHOVEL_HPP__