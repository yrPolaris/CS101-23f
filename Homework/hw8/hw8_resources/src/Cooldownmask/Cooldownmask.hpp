#ifndef COOLDOWNMASK_HPP__
#define COOLDOWNMASK_HPP__

#include "GameObject.hpp"

class Cooldownmask : public GameObject
{
public:
    Cooldownmask(int x,int y,int time,pGameWorld world);
    void Update() override;
    void OnClick() override;

    int getmaskcooltime()
    {
        return maskcooltime;
    }

private:
    int maskcooltime;
};



#endif // !COOLDOWNMASK_HPP__