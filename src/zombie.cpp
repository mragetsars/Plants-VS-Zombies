#include "zombie.hpp"

Zombie::Zombie(Vector2f p, Zombie_Type input_type, Setting* s){
    setting = s;
    type = input_type;
    setup();
    action = false;
    pos = p;
    set_zombie_texture();
    IntRect rect;
    rect.top = 2;
    rect.left = 2;
    rect.width = 43; 
    rect.height = 53;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(2, 2);
}
       
Zombie::~Zombie(){
}

void Zombie::render(RenderWindow &window){
    window.draw(sprite);
}

void Zombie::update(){
    handel_animation();
    if(!action)
        pos.x -= speed;
    sprite.setPosition(pos);
}

int Zombie::output_damage(){
    return damage;
}

bool Zombie::input_damage(int input_damage){
    if(health - input_damage > 0){
        health -= input_damage;
        return true;
    }else
        return false;
}

FloatRect Zombie::get_rect(){
    return sprite.getGlobalBounds();
}

int Zombie::get_line(){
    if(pos.y == 65)
        return 1;
    if(pos.y == 165)
        return 2;
    if(pos.y == 265)
        return 3;
    if(pos.y == 365)
        return 4;
    if(pos.y == 465)
        return 5;   
}

void Zombie::reduce_speed(){
    speed = setting->Zombie.Speed/2;
}

void Zombie::setup(){
    switch (type){
    case (Regular):
        health = setting->Zombie.Health;
        damage = setting->Zombie.Damage;
        speed = setting->Zombie.Speed;
        break;
    case (Gargantuar):
        health = setting->Gargantuar.Health;
        damage = setting->Gargantuar.Damage;
        speed = setting->Gargantuar.Speed;
        break;
    }
}

void Zombie::set_zombie_texture(){
    if(type == Regular){
        if(action){
            if (!texture.loadFromFile(PICS_PATH + "z_AZombie(eating).png"))
                debug("failed to load zombie texture");
        }else{
            if (!texture.loadFromFile(PICS_PATH + "z_AZombie.png"))
                debug("failed to load zombie texture");
        }
    }
    if(type == Gargantuar){
        if(action){
            if (!texture.loadFromFile(PICS_PATH + "z_BZombie(eating).png"))
                debug("failed to load zombie texture");
        }else{
            if (!texture.loadFromFile(PICS_PATH + "z_BZombie.png"))
                debug("failed to load zombie texture");
        }
    }
}

void Zombie::handel_animation(){
    if(action)
        set_zombie_texture();
    else  
        set_zombie_texture();
    Time animationelapsed = animationclock.getElapsedTime();
    if(animationelapsed.asMilliseconds() >= 100){
        animationclock.restart();
        cur_rect = (cur_rect + 1) % 7;
        IntRect rect;
        rect.top = 2;
        rect.left = zombie_animation_rect[cur_rect];
        rect.width = 43;
        rect.height = 53;
        sprite.setTextureRect(rect);
    }
}
