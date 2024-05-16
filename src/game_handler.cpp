#include "game_handler.hpp"

Game_Handler::Game_Handler (){
    type = Nothing;
    peashootercard= new Card(Vector2f(10,10), PeaShooterCard);
    snowpeashootercard= new Card(Vector2f(10,88), SnowpeaShooterCard);
    sunflowercard= new Card(Vector2f(10,166), SunFlowerCard);
    for(int i=0; i < 9; i++)
        for(int j=0; j < 5; j++)
            Plants.push_back(new Plant(FARM_COLUMNs[i], FARM_LINES[j]));
}

Game_Handler::~Game_Handler(){
    for(auto v : projectiles){
        delete v;
    }
    for(auto z : zombies){
        delete z;
    }
}

void Game_Handler::update(Vector2i pos){
    Time projectileelapsed = projectileclock.getElapsedTime();
    if(projectileelapsed.asMilliseconds() >= 600){
        projectileclock.restart();
        add_projectile();
    }
    Time zombieelapsed = zombieclock.getElapsedTime();
    if(zombieelapsed.asMilliseconds() >= 2000){
        zombieclock.restart();
        add_zombie();
    }
    for(auto p : Plants)
        if(!((p->type == EmptyPlant)&&(type == Nothing)))
            p->update(pos);
    for(auto v : projectiles)
        v->update();
    for(auto z : zombies)
        z->update();
    delete_out_of_bounds();
    handle_collision();
    handle_detection();
}

void Game_Handler::render(RenderWindow &window){
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

void Game_Handler::handle_mouse_press(Vector2i pos){
    if(type == Nothing){
        if(peashootercard->handle_mouse_press(pos)){
            type = Choosing;
            new_plant_type = PeaShooter;
        }
        if(snowpeashootercard->handle_mouse_press(pos)){
            type = Choosing;
            new_plant_type = SnowpeaShooter;
        }
        if(sunflowercard->handle_mouse_press(pos)){
            type = Choosing;
            new_plant_type = SunFlower;
        }
    }
    if(type == Choosing)
        for(auto p : Plants)
            if(p->handle_mouse_press(pos, new_plant_type))
                type = Nothing;
}

void Game_Handler::add_projectile(){
    Projectile* p_temp;
    for(auto p : Plants){
        if((p->action)&&((p->type == PeaShooter) || (p->type == SnowpeaShooter))){
            p_temp = new Projectile(p->get_projectile_pos(), p->get_projectile_type());
            projectiles.push_back(p_temp);
        }
    }
}

void Game_Handler::add_zombie(){
    int i = rand()%2;
    Zombie* z;
    if(i == 1)
        z = new Zombie(Vector2f(WIDTH, ((rng()%5)*100)+65), Normal1);
    else
        z = new Zombie(Vector2f(WIDTH, ((rng()%5)*100)+65), Normal2);
    zombies.push_back(z);
}

void Game_Handler::delete_out_of_bounds(){
    vector <Projectile*> trash;
    for(auto v : projectiles){
        if(v->is_out()){
            trash.push_back(v);
        }
    }
    projectiles.erase(remove_if(projectiles.begin(), projectiles.end(), 
        [](auto p){ return p->is_out(); }), projectiles.end());
    for (auto p : trash){
        delete p;
    }
}

void Game_Handler::handle_collision(){
    vector <Projectile*> trashv;
    vector <Zombie*> trashz;
    for(auto v : projectiles){
        for(auto z : zombies){
            FloatRect z_rect = z->get_rect();
            FloatRect v_rect = v->get_rect();
            if(z_rect.intersects(v_rect)){
                trashv.push_back(v);
                trashz.push_back(z);
            }
        }
    }
    for(auto v : trashv){
        projectiles.erase(remove(projectiles.begin(), projectiles.end(), v), projectiles.end());   
        delete v;
    }
    for(auto z : trashz){
        zombies.erase(remove(zombies.begin(), zombies.end(), z), zombies.end());   
        delete z;
    }
}

void Game_Handler::handle_detection(){
    for(auto z : zombies){
        if(z->get_rect().left < 900)
            switch (z->get_line())
            {
            case (1):
                for(int k = 0; k < 9; k++)
                    Plants[5*k]->set_action();
                break;
            case (2):
                for(int k = 0; k < 9; k++)
                    Plants[(5*k)+1]->set_action();
                break;
            case (3):
                for(int k = 0; k < 9; k++)
                    Plants[(5*k)+2]->set_action();
                break;
            case (4):
                for(int k = 0; k < 9; k++)
                    Plants[(5*k)+3]->set_action();
                break;
            case (5):
                for(int k = 0; k < 9; k++)
                    Plants[(5*k)+4]->set_action();
                break;
            default:
                break;
            }
    }
}
