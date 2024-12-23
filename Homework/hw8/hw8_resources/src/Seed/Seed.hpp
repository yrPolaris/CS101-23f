#ifndef SEED_HPP__
#define SEED_HPP__

#include "GameObject.hpp"
#include "Cooldownmask.hpp"


class Sunflowerseed : public GameObject
{
public:

    Sunflowerseed(pGameWorld world);
    void Update() override;
    void OnClick() override;


int getcooltime()
{
    return cooltime;
}

void cooling()
{
    cooltime--;
}

private:
    int price;
    int cooltime;
    Seed_type seed_type;
};

class Peashooterseed : public GameObject
{
public:
    Peashooterseed(pGameWorld world);
    void Update() override;
    void OnClick() override;

int getcooltime()
{
    return cooltime;
}

void cooling()
{
    cooltime--;
}

private:
    int price;
    int cooltime;
    Seed_type seed_type;
};

class Wallnutseed : public GameObject
{
public:

    Wallnutseed(pGameWorld world);
    void Update() override;
    void OnClick() override;

int getcooltime()
{
    return cooltime;
}

void cooling()
{
    cooltime--;
}

private:
    int price;
    int cooltime;
    Seed_type seed_type;
};

class Cherrybombseed : public GameObject
{
public:

    Cherrybombseed(pGameWorld world);
    void Update() override;
    void OnClick() override;

int getcooltime()
{
    return cooltime;
}

void cooling()
{
    cooltime--;
}

private:
    int price;
    int cooltime;
    Seed_type seed_type;
};

class Repeaterseed : public GameObject
{
public:

    Repeaterseed(pGameWorld world);
    void Update() override;
    void OnClick() override;

int getcooltime()
{
    return cooltime;
}

void cooling()
{
    cooltime--;
}

private:
    int price;
    int cooltime;
    Seed_type seed_type;
};

#endif // !SEED_HPP__