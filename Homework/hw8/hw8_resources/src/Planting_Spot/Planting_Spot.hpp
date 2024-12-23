#ifndef PLANTING_SPOT_HPP__
#define PLANTING_SPOT_HPP__

#include "GameObject.hpp"
#include "Plant.hpp"

class Planting_Spot : public GameObject
{
public:
    Planting_Spot(int x, int y, pGameWorld world);
    void Update() override;
    void OnClick() override;

private:
    

};

#endif // !PLANTING_SPOT_HPP__