#pragma once

#include "global.hpp"

class Projectile{
public:
    Projectile(Vector2f pos);
    ~Projectile();
    void render(RenderWindow &window);
    void update();
    bool is_out();
    FloatRect get_rect();
private:
    const int speed = 4;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};