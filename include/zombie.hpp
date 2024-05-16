#pragma once

#include "global.hpp"

enum Zombie_Type {
  Normal1,
  Normal2,
};

class Zombie{
public:
    Zombie(Vector2f pos, Zombie_Type input_type);
    ~Zombie();
    void render(RenderWindow &window);
    void update();
    FloatRect get_rect();
    int get_line();
private: 
    Zombie_Type type;
    Clock animationclock;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    const float speed = 0.50;
    int cur_rect = 0;
    void set_zombie_texture();
    void handel_animation();
};
