#pragma once

#include "global.hpp"
#include "projectile.hpp"

enum Plant_Type {
  PeaShooter,
  SnowpeaShooter,
  EmptyPlant,
  SelectedPlant,
  SunFlower,
  
};

class Plant{
  public:
    Plant(int x, int y);
    ~Plant();
    void render(RenderWindow &window);
    void update(Vector2i mousePos);
    bool handle_mouse_press(Vector2i mousePos, Plant_Type input_type);
    Vector2f get_projectile_pos();
    Projectile_Type get_projectile_type();
    void set_action();
    bool action;
    Plant_Type type;
  private:
    Clock animationclock;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    int cur_rect = 2;
    void set_plant_texture();
    void handel_animation();
    void handel_action_animation();
    void handel_idle_animation();
};
