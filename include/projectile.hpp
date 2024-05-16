#pragma once

#include "global.hpp"

enum Projectile_Type {
  Pea,
  Snowpea,
};

class Projectile{
public:
    Projectile(Vector2f pos, Projectile_Type input_type, Setting* s);
    ~Projectile();
    void render(RenderWindow &window);
    void update();
    int output_damage();
    FloatRect get_rect();
    bool is_out();
    Projectile_Type type;
private:
    Setting* setting;
    int damage;
    int speed;
    void setup();
    Vector2f pos;
    Texture texture;
    Sprite sprite;
    void set_projectile_texture();
};