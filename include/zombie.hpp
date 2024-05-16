#pragma once

#include "global.hpp"

enum Zombie_Type {
  Regular,
  Gargantuar,
};

class Zombie{
public:
    Zombie(Vector2f pos, Zombie_Type input_type, Setting* s);
    ~Zombie();
    void render(RenderWindow &window);
    void update();
    int output_damage();
    bool input_damage(int input_damage);
    FloatRect get_rect();
    int get_line();
    void reduce_speed();
    bool action;
private:
    Setting* setting;
    Zombie_Type type;
    int health;
    int damage;
    int speed;
    void setup();
    Vector2f pos;
    Texture texture;
    Sprite sprite;
    void set_zombie_texture();
    Clock animationclock;
    int cur_rect = 0;
    void handel_animation();
};
