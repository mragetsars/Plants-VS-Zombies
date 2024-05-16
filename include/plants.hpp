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
    void update(Vector2i pos);
    void handle_mouse_press(Vector2i pos, Plant_Type input_type);
    void handle_mouse_release(Vector2i mousePos);
    Vector2f get_projectile_pos();
    Projectile_Type get_projectile_type();
    vector < Projectile* > projectiles;
    Plant_Type type;
private:
Clock projectileclock;
    Clock animationclock;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    int abnormal_animation_rect[3] = {2, 86, 170};
    int cur_rect = 2;
    bool is_fixed = false;
    void fix_position();
    void set_plant_texture();
    void handel_animation();
};
