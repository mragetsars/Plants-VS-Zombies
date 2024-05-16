#include "handler.hpp"

Handler::Handler (){
    peashootercard= new Card(Vector2f(10,10), PeaShooterCard);
    snowpeashootercard= new Card(Vector2f(10,88), SnowpeaShooterCard);
    sunflowercard= new Card(Vector2f(10,166), SunFlowerCard);
    for(int i=0; i < 9; i++)
        for(int j=0; j < 5; j++)
            Plants.push_back(new Plant(FARM_COLUMNs[i], FARM_LINES[j]));
}

Handler::~Handler(){
    for(auto p : projectiles){
        delete p;
    }
    for(auto z : zombies){
        delete z;
    }
}

void Handler::update(Vector2i pos){
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
    for(auto p : Plants)
        p->update(pos);
    for(auto p : projectiles)
        p->update();
    for(auto z : zombies)
        z->update();
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
    peashootercard->render(window);
    snowpeashootercard->render(window);
    sunflowercard->render(window);
    for(auto p : Plants)
        p->render(window);
    for(auto v : projectiles)
        v->render(window);
    for(auto z : zombies)
        z->render(window);
}

void Handler::add_projectile(){
    Projectile* p_temp;
    for(auto p : Plants){
        if(!((p->type == EmptyPlant) || (p->type == SelectedPlant))){
            p_temp = new Projectile(p->get_projectile_pos(), p->get_projectile_type());
            projectiles.push_back(p_temp);
        }
    }
}   

void Handler::add_zombie(){
    int i = rand()%2;
    Zombie* z;
    if(i == 1)
        z = new Zombie(Vector2f(WIDTH, ((rng()%6)*100)-35), Normal1);
    else
        z = new Zombie(Vector2f(WIDTH, ((rng()%6)*100)-35), Normal2);
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


void Handler::handle_mouse_press(Vector2i pos){
    for(auto p : Plants)
        p->handle_mouse_press(pos, SnowpeaShooter);
}
void Handler::handle_mouse_release(Vector2i pos){
    for(auto p : Plants)
        p->handle_mouse_release(pos);
}
