#ifndef EXPLOSION_HPP__
#define EXPLOSION_HPP__

#include "GameObject.hpp"

class Explosion : public GameObject
{
public:
    Explosion(int x, int y, pGameWorld world);
    void Update() override;
    void OnClick() override;

private:
    int exist_time;
};



#endif // !EXPLOSION_HPP__