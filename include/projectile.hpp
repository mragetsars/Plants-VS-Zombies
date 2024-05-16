#pragma once

#include "global.hpp"

enum Projectile_Type {
  Pea,
  Icepea,
};

class Projectile{
public:
    Projectile(Vector2f pos, Projectile_Type input_type);
    ~Projectile();
    void render(RenderWindow &window);
    void update();
    bool is_out();
    FloatRect get_rect();
private:
    Projectile_Type type;
    const int speed = 4;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    void set_projectile_texture();
};