#pragma once

#include "global.hpp"
#include "card.hpp"
#include "sun.hpp"
#include "plant.hpp"
#include "projectile.hpp"
#include "zombie.hpp"

enum Handler_Type{
    Nothing,
    Choosing,
};

class Game_Handler{
public:
    Game_Handler ();
    ~Game_Handler();
    void update(Vector2i mousePos);
    void render(RenderWindow &window);
    void handle_mouse_press(Vector2i mousePos);
    bool check_gameover();
private:
    Setting* setting;
    int clamed_suns;
    Handler_Type type;
    Plant_Type new_plant_type;
    mt19937 rng;
    Clock sunclock, projectileclock, zombieclock;
    Clock zombie_attack;
    Clock sunflower_action;
    Card* peashootercard;
    Card* snowpeashootercard;
    Card* sunflowercard;
    Card* wallnutcard;
    SunSign* sunsign;
    vector < Sun* > Suns;
    vector < Plant* > Plants;
    vector < Projectile* > Projectiles;
    vector < Zombie* > Zombies;
    void add_sun();
    void add_projectile();
    void add_zombie();
    void delete_out_of_bounds();
    void handle_collision();
    void handle_detection();
    void handle_contention();
};