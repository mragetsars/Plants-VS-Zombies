#pragma once

#include "global.hpp"
#include "player.hpp"
#include "projectile.hpp"
#include "zombie.hpp"

class Handler{
public:
    Handler (Player* player);
    ~Handler();
    void update();
    void render(RenderWindow &window);
private:
    mt19937 rng;
    Clock clock, zombie_clock;
    Player* player;
    vector < Projectile* > projectiles;
    vector < Zombie* > zombies;
    void add_projectile();
    void delete_out_of_bounds();
    void add_zombie();
    void handle_collision();
};