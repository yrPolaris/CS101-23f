#include "Background.hpp"

Background::Background(pGameWorld world)
    : GameObject(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION,world,1,0) {}

void Background::Update() {}
void Background::OnClick() {}
