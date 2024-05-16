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
private: 
    Zombie_Type type;
    Clock animationclock;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    const float speed = 0.25;
    int animation_rect[5] = {3, 107, 159, 211, 315};
    int cur_rect = 0;
    void set_zombie_texture();
    void handel_animation();
};
