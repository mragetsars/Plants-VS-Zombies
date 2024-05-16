#include "zombie.hpp"

Zombie::Zombie(Vector2f p, Zombie_Type input_type){
    type = input_type;
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
    pos.x -= speed;
    sprite.setPosition(pos);
}

FloatRect Zombie::get_rect(){
    return sprite.getGlobalBounds();
}

void Zombie::set_zombie_texture(){
    if(type == Normal1)
        if (!texture.loadFromFile(PICS_PATH + "AZombie.png"))
            debug("failed to load zombie texture");
    if(type == Normal2)
        if (!texture.loadFromFile(PICS_PATH + "BZombie.png"))
            debug("failed to load zombie texture");
}

void Zombie::handel_animation(){
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
