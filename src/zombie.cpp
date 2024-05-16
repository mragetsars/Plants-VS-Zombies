#include "zombie.hpp"

Zombie::Zombie(Vector2f p){
    pos = p;
    if (!texture.loadFromFile(PICS_PATH + "zombie.png")) {
        debug("failed to load zombie texture");
    }
    sprite.setTexture(texture);
    sprite.setScale(1.2, 1.2);  
    IntRect rect;
    rect.width = 34; 
    rect.height = 62;
    sprite.setTextureRect(rect);
}
       
Zombie::~Zombie(){

}

void Zombie::render(RenderWindow &window){
    window.draw(sprite);
}

void Zombie::update(){
    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 300){
        clock.restart();
        cur_rect = (cur_rect + 1) % 3;
        IntRect rect;
        rect.width = 34; 
        rect.height = 62;
        rect.left = poses[cur_rect];
        sprite.setTextureRect(rect);
    }
    pos.x -= speed;
    sprite.setPosition(pos);
}

FloatRect Zombie::get_rect(){
    return sprite.getGlobalBounds();
}