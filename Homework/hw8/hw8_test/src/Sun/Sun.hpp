#ifndef SUN_HPP__
#define SUN_HPP__

#include "GameObject.hpp"

class Sun : public GameObject
{
public:
    enum class Fall_type
    {
        WORLD,FLOWER
    };
    Sun(int x, int y, pGameWorld world,Fall_type fall_type);
    void Update() override;
    void OnClick() override;

private:
    int m_exist_time;
    int m_delete_time;
    Fall_type m_fall_type;
    int m_speed;
};

#endif // !SUN_HPP__