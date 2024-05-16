#pragma once

#include "global.hpp"

class Zombie{
public:
    Zombie(Vector2f pos);
    ~Zombie();
    void render(RenderWindow &window);
    void update();
    FloatRect get_rect();
private: 
    Clock clock;
    const float speed = 1.2;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    int poses[4] = {0, 50, 102, 152};
    int cur_rect = 0;
};