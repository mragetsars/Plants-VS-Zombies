#pragma once

#include "global.hpp"
#include "projectile.hpp"

enum Plant_Type {
  EmptyPlant,
  SelectedPlant,
  // KernelPult,
  PeaShooter,
  SnowpeaShooter,
  SunFlower,
  Wallnut,
};

class Plant{
  public:
    Plant(int x, int y, Setting* s);
    ~Plant();
    void render(RenderWindow &window);
    void update(Vector2i mousePos);
    bool handle_mouse_press(Vector2i mousePos, Plant_Type input_type);
    void input_damage(int input_damage);
    Projectile* get_projectile();
    FloatRect get_rect();
    Plant_Type type;
    bool action;
  private:
    Setting* setting;
    int health;
    void setup();
    Vector2f pos;
    Texture texture;
    Sprite sprite;
    void set_plant_texture();
    Clock animationclock;
    int cur_rect = 2;
    void handel_animation();
};
