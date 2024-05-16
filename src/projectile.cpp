#include "projectile.hpp"

Projectile::Projectile(Vector2f p){
    pos = p;
    if (!texture.loadFromFile(PICS_PATH + "tir.png")) {
        debug("failed to load player texture");
    }
    sprite.setTexture(texture);
    sprite.setScale(0.7, 0.7);
}

Projectile::~Projectile(){

}

void Projectile::render(RenderWindow &window){
    window.draw(sprite);
}

void Projectile::update(){
    pos.x += speed;
    sprite.setPosition(pos);
}

bool Projectile::is_out(){
    return sprite.getPosition().x > WIDTH + 10;
}

FloatRect Projectile::get_rect(){
    return sprite.getGlobalBounds();
}