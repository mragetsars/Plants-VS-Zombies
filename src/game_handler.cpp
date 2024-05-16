#include "game_handler.hpp"

Game_Handler::Game_Handler (){
    clamed_suns = 500;
    type = Nothing;
    peashootercard= new Card(Vector2f(10,10), PeaShooterCard);
    snowpeashootercard= new Card(Vector2f(10,88), SnowpeaShooterCard);
    sunflowercard= new Card(Vector2f(10,166), SunFlowerCard);
    wallnutcard= new Card(Vector2f(10,244), WallnutCard);
    for(int i=0; i < 9; i++)
        for(int j=0; j < 5; j++)
            Plants.push_back(new Plant(FARM_COLUMNs[i], FARM_LINES[j]));
}

Game_Handler::~Game_Handler(){
    for(auto v : Projectiles){
        delete v;
    }
    for(auto z : Zombies){
        delete z;
    }
}

void Game_Handler::update(Vector2i mousePos){
    Time sunelapsed = sunclock.getElapsedTime();
    if(sunelapsed.asMilliseconds() >= 6000){
        sunclock.restart();
        add_sun();
    }
    Time projectileelapsed = projectileclock.getElapsedTime();
    if(projectileelapsed.asMilliseconds() >= 900){
        projectileclock.restart();
        add_projectile();
    }
    Time zombieelapsed = zombieclock.getElapsedTime();
    if(zombieelapsed.asMilliseconds() >= 2000){
        zombieclock.restart();
        add_zombie();
    }
    clamed_suns = peashootercard ->update(clamed_suns, type == Nothing);
    clamed_suns = snowpeashootercard ->update(clamed_suns, type == Nothing);   
    clamed_suns = sunflowercard ->update(clamed_suns, type == Nothing);
    clamed_suns = wallnutcard ->update(clamed_suns, type == Nothing);
    for(auto s : Suns)
        s->update();
    for(auto p : Plants)
        if(!((p->type == EmptyPlant)&&(type == Nothing)))
            p->update(mousePos);
    for(auto v : Projectiles)
        v->update();
    for(auto z : Zombies)
        z->update();
    delete_out_of_bounds();
    handle_collision();
    handle_detection();
}

void Game_Handler::render(RenderWindow &window){
    peashootercard->render(window);
    snowpeashootercard->render(window);
    sunflowercard->render(window);
    wallnutcard->render(window);
    for(auto s : Suns)
        s->render(window);
    for(auto p : Plants)
        p->render(window);
    for(auto v : Projectiles)
        v->render(window);
    for(auto z : Zombies)
        z->render(window);
}

void Game_Handler::handle_mouse_press(Vector2i mousePos){
    for(auto s : Suns)
        clamed_suns = s->handle_mouse_press(mousePos, clamed_suns);
    if(type == Nothing){ 
        if(peashootercard->handle_mouse_press(mousePos)){
            type = Choosing;
            new_plant_type = PeaShooter;
        }
        if(snowpeashootercard->handle_mouse_press(mousePos)){
            type = Choosing;
            new_plant_type = SnowpeaShooter;
        }
        if(sunflowercard->handle_mouse_press(mousePos)){
            type = Choosing;
            new_plant_type = SunFlower;
        }
        if(wallnutcard->handle_mouse_press(mousePos)){
            type = Choosing;
            new_plant_type = Wallnut;
        }
    }
    if(type == Choosing)
        for(auto p : Plants)
            if(p->handle_mouse_press(mousePos, new_plant_type))
                type = Nothing;
}

bool Game_Handler::check_gameover(){
    for(auto z : Zombies)
        if(z->get_rect().left < 200)
            return true;
    return false;
}

void Game_Handler::add_sun(){
    Suns.push_back(new Sun(Vector2f(((rng()%5)*100)+65, 0)));
}

void Game_Handler::add_projectile(){
    Projectile* p_temp;
    for(auto p : Plants){
        if((p->action)&&((p->type == PeaShooter) || (p->type == SnowpeaShooter))){
            p_temp = new Projectile(p->get_projectile_pos(), p->get_projectile_type());
            Projectiles.push_back(p_temp);
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
    Zombies.push_back(z);
}

void Game_Handler::delete_out_of_bounds(){
    vector <Projectile*> trashv;
    for(auto v : Projectiles){
        if(v->is_out()){
            trashv.push_back(v);
        }
    }
    Projectiles.erase(remove_if(Projectiles.begin(), Projectiles.end(), 
        [](auto v){ return v->is_out(); }), Projectiles.end());
    for (auto v : trashv){
        delete v;
    }
    vector <Sun*> trashs;
    for(auto s : Suns){
        if(s->is_out()){
            trashs.push_back(s);
        }
    }
    Suns.erase(remove_if(Suns.begin(), Suns.end(), 
        [](auto s){ return s->is_out(); }), Suns.end());
    for (auto s : trashs){
        delete s;
    }
}

void Game_Handler::handle_collision(){
    vector <Projectile*> trashv;
    vector <Zombie*> trashz;
    for(auto v : Projectiles){
        for(auto z : Zombies){
            FloatRect z_rect = z->get_rect();
            FloatRect v_rect = v->get_rect();
            if(z_rect.intersects(v_rect)){
                trashv.push_back(v);
                trashz.push_back(z);
            }
        }
    }
    for(auto v : trashv){
        Projectiles.erase(remove(Projectiles.begin(), Projectiles.end(), v), Projectiles.end());   
        delete v;
    }
    for(auto z : trashz){
        Zombies.erase(remove(Zombies.begin(), Zombies.end(), z), Zombies.end());   
        delete z;
    }
}

void Game_Handler::handle_detection(){
    for(auto p : Plants)
        p->action = false;
    for(auto z : Zombies){
        if(z->get_rect().left < 1000)
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

void Game_Handler::handle_contention(){
    
}