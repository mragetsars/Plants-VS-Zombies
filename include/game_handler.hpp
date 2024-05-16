#pragma once

#include "global.hpp"
#include "card.hpp"
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
    void update(Vector2i pos);
    void render(RenderWindow &window);
    void handle_mouse_press(Vector2i pos);
private:
    Handler_Type type;
    Plant_Type new_plant_type;
    mt19937 rng;
    Clock projectileclock, zombieclock;
    Card* peashootercard;
    Card* snowpeashootercard;
    Card* sunflowercard;
    vector < Plant* > Plants;
    vector < Projectile* > projectiles;
    vector < Zombie* > zombies;
    void add_projectile();
    void add_zombie();
    void delete_out_of_bounds();
    void handle_collision();
    void handle_detection();
};