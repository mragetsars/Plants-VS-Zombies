#include "handler.hpp"

Handler::Handler (Player* p){
    player = p;
}

Handler::~Handler(){
    for(auto p : projectiles){
        delete p;
    }
    for(auto z : zombies){
        delete z;
    }
}

void Handler::update(){
    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 600){
        clock.restart();
        add_projectile();
    }
    Time zelapsed = zombie_clock.getElapsedTime();
    if(zelapsed.asMilliseconds() >= 700){
        zombie_clock.restart();
        add_zombie();
    }
    for(auto p : projectiles){
        p->update();
    }
    for(auto z : zombies){
        z->update();
    }
    delete_out_of_bounds();
    handle_collision();
}

void Handler::delete_out_of_bounds(){
    vector <Projectile*> trash;
    for(auto p : projectiles){
        if(p->is_out()){
            trash.push_back(p);
        }
    }
    projectiles.erase(remove_if(projectiles.begin(), projectiles.end(), 
        [](auto p){ return p->is_out(); }), projectiles.end());
    for (auto p : trash){
        delete p;
    }
}

void Handler::render(RenderWindow &window){
    for(auto p : projectiles){
        p->render(window);
    }
    for(auto z : zombies){
        z->render(window);
    }
}

void Handler::add_projectile(){
    Projectile* p = new Projectile(player->get_projectile_pos());
    projectiles.push_back(p);
}   

void Handler::add_zombie(){
    Zombie* z = new Zombie(Vector2f(WIDTH, rng()%HEIGHT - 30));
    zombies.push_back(z);
}

void Handler::handle_collision(){
    vector <Projectile*> trashp;
    vector <Zombie*> trashz;
    for(auto p : projectiles){
        for(auto z : zombies){
            FloatRect z_rect = z->get_rect();
            FloatRect p_rect = p->get_rect();
            if(z_rect.intersects(p_rect)){
                trashp.push_back(p);
                trashz.push_back(z);
            }
        }   
    }
    for(auto p : trashp){
        projectiles.erase(remove(projectiles.begin(), projectiles.end(), p), projectiles.end());   
        delete p;
    }
    for(auto z : trashz){
        zombies.erase(remove(zombies.begin(), zombies.end(), z), zombies.end());   
        delete z;
    }
}