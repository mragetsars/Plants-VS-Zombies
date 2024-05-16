#pragma once

#include "global.hpp"
#include "card.hpp"
#include "plants.hpp"
#include "projectile.hpp"
#include "zombie.hpp"

class Handler{
public:
    Handler ();
    ~Handler();
    void update(Vector2i pos);
    void render(RenderWindow &window);
    void handle_mouse_press(Vector2i pos);
    void handle_mouse_release(Vector2i pos);
private:
    mt19937 rng;
    Clock clock, zombie_clock;
    Card* peashootercard;
    Card* snowpeashootercard;
    Card* sunflowercard;
    vector < Plant* > Plants;
    vector < Projectile* > projectiles;
    vector < Zombie* > zombies;
    void add_projectile();
    void delete_out_of_bounds();
    void add_zombie();
    void handle_collision();
};