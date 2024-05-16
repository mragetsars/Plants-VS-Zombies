#include "handler.hpp"

PeashooterHandler::PeashooterHandler (Shooter* p){
    player = p;
}

PeashooterHandler::~PeashooterHandler(){
    for(auto p : projectiles){
        delete p;
    }
    for(auto z : zombies){
        delete z;
    }
}

void PeashooterHandler::update(){
    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 600){
        clock.restart();
        add_projectile();
    }
    Time zelapsed = zombie_clock.getElapsedTime();
    if(zelapsed.asMilliseconds() >= 2000){
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

void PeashooterHandler::delete_out_of_bounds(){
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

void PeashooterHandler::render(RenderWindow &window){
    for(auto p : projectiles){
        p->render(window);
    }
    for(auto z : zombies){
        z->render(window);
    }
}

void PeashooterHandler::add_projectile(){
    Projectile* p = new Projectile(player->get_projectile_pos(), Icepea);
    projectiles.push_back(p);
}   

void PeashooterHandler::add_zombie(){
    int i = rand()%2;
    Zombie* z;
    if(i == 1)
        z = new Zombie(Vector2f(WIDTH, ((rng()%6)*100)-35), Normal1);
    else
        z = new Zombie(Vector2f(WIDTH, ((rng()%6)*100)-35), Normal2);
    zombies.push_back(z);
}

void PeashooterHandler::handle_collision(){
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