#ifndef PLANT_HPP__
#define PLANT_HPP__

#include "GameObject.hpp"


class Sunflower : public GameObject
{
public:
    Sunflower(int x, int y, pGameWorld world);
    void Update() override;
    void OnClick() override;

private:
    int first_time;
    int time;
    int num;
};

class Peashooter : public GameObject
{
public:
    Peashooter(int x, int y, pGameWorld world);
    void Update() override;
    void OnClick() override;

    bool checktime(int time)
    {
        return time == 30;
    }
private:
    int time;
};

class Wallnut : public GameObject
{
public:
    Wallnut(int x, int y, pGameWorld world);
    void Update() override;
    void OnClick() override;



private:
    int m_state;
};


class Cherrybomb : public GameObject
{
public:
    Cherrybomb(int x, int y, pGameWorld world);
    void Update() override;
    void OnClick() override;

    void reset_time(int t)
    {
        t = 0;
    }

private:
    int time;
};

class Repeater : public GameObject
{
public:
    Repeater(int x, int y, pGameWorld world);
    void Update() override;
    void OnClick() override;

private:
    int time;
};





#endif // !PLANT_HPP__