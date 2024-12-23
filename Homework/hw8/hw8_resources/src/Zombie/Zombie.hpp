#ifndef Zombie_HPP__
#define Zombie_HPP__

#include "GameObject.hpp"


class Regular_Zombie : public GameObject
{
public:
    Regular_Zombie(int x, int y, pGameWorld world);
    void Update() override;
    void OnClick() override;

};


class Bucket_Head_Zombie : public GameObject
{
public:
    Bucket_Head_Zombie(int x, int y, pGameWorld world);
    void Update() override;
    void OnClick() override;

};



class Pole_Vaulting_Zombie : public GameObject
{
public:
    Pole_Vaulting_Zombie(int x, int y, pGameWorld world);
    void Update() override;
    void OnClick() override;

};







#endif // !Zombie_HPP__