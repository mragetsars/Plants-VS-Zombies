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

class Shooter{
public:
    Shooter(int x, int y, Plant_Type input_type);
    ~Shooter();
    void render(RenderWindow &window);
    void update(Vector2i pos);
    void handle_mouse_press(Vector2i pos);
    void handle_mouse_release(Vector2i mousePos);
    Vector2f get_projectile_pos();
    vector < Projectile* > projectiles;
private:
    Clock projectileclock;
    Clock animationclock;
    Plant_Type type;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    int animation_rect[3] = {2, 86, 170};
    int cur_rect = 1;
    bool is_tagged = false;
    bool is_fixed = false;
    void fix_position();
    void add_projectile();
    void delete_out_of_bounds();
    void set_plant_texture();
    void handel_animation();
    void handel_projectile();
};
