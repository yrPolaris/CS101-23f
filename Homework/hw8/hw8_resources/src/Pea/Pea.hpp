#ifndef PEA_HPP__
#define PEA_HPP__

#include "GameObject.hpp"


class Pea : public GameObject
{
public:
    Pea(int x, int y, pGameWorld world);
    void Update() override;
    void OnClick() override;
};



#endif // !PEA_HPP__