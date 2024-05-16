#include "projectile.hpp"

Projectile::Projectile(Vector2f p, Projectile_Type input_type){
        type = input_type;
        pos = p;
        set_projectile_texture();
        IntRect rect;
        rect.top = 2;
        rect.left = 2;
        if(type == Pea)
            rect.width = 19;
        if(type == Snowpea)
            rect.width = 22;
        rect.height = 17;
        sprite.setTextureRect(rect);
        sprite.setTexture(texture);
        sprite.setScale(1, 1);
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

void Projectile::set_projectile_texture(){
    if(type == Pea)
        if (!texture.loadFromFile(PICS_PATH + "v_Pea.png"))
            debug("failed to load player texture");
    if(type == Snowpea)
        if (!texture.loadFromFile(PICS_PATH + "v_Snowpea.png"))
            debug("failed to load player texture");
}