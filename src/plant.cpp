#include "plant.hpp"

Plant::Plant(int x, int y){
    type = EmptyPlant;
    set_plant_texture();
    pos = Vector2f(x, y);
    IntRect rect;
    rect.top = 2;
    rect.left = 12;
    rect.width = 70;
    rect.height = 70;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(1, 1);
    sprite.setPosition(pos);
}

Plant::~Plant(){
}

void Plant::render(RenderWindow &window){
    window.draw(sprite);
}

void Plant::update(Vector2i mousePos){
    if((type == SnowpeaShooter)||(type == PeaShooter)||(type == SunFlower))
        handel_animation();
    if(type == EmptyPlant){
        Vector2f spritePos = sprite.getPosition();
        Vector2f spriteSize = {sprite.getTextureRect().width, sprite.getTextureRect().height};
        if (mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
            mousePos.y >= spritePos.y && mousePos.y <= spritePos.y + spriteSize.y)
        {
            type = SelectedPlant;
            set_plant_texture();
        }
    }
    if(type == SelectedPlant){
        Vector2f spritePos = sprite.getPosition();
        Vector2f spriteSize = {sprite.getTextureRect().width, sprite.getTextureRect().height};
        if (!(mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
            mousePos.y >= spritePos.y && mousePos.y <= spritePos.y + spriteSize.y))
        {
            type = EmptyPlant;
            set_plant_texture();
        }
    }
}

Vector2f Plant::get_projectile_pos(){
    return Vector2f(sprite.getPosition().x + 50, sprite.getPosition().y + 12);
}

Projectile_Type Plant::get_projectile_type(){
    Projectile_Type output_projectile_type;
    if(type == PeaShooter)
        output_projectile_type = Pea;
    else if(type == SnowpeaShooter)
        output_projectile_type = Snowpea;
    return output_projectile_type;
}

bool Plant::handle_mouse_press(Vector2i mousePos, Plant_Type input_type){
    Vector2f spritePos = sprite.getPosition();
    Vector2f spriteSize = {sprite.getTextureRect().width, sprite.getTextureRect().height};
    if (mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
        mousePos.y >= spritePos.y && mousePos.y <= spritePos.y + spriteSize.y)
    {
        type = input_type;
        set_plant_texture();
        return true;
    }
    else
        return false;
}

void Plant::set_plant_texture(){
    if(type == EmptyPlant)
        if (!texture.loadFromFile(PICS_PATH + "EmptyPlant.png"))
            debug("failed to load player texture");
    if(type == SelectedPlant)
        if (!texture.loadFromFile(PICS_PATH + "SelectedPlant.png"))
            debug("failed to load player texture");
    if(type == PeaShooter)
        if (!texture.loadFromFile(PICS_PATH + "PeaShooter(attack).png"))
            debug("failed to load player texture");
    if(type == SnowpeaShooter)
        if (!texture.loadFromFile(PICS_PATH + "SnowpeaShooter(attack).png"))
            debug("failed to load player texture");
    if(type == SunFlower)
        if (!texture.loadFromFile(PICS_PATH + "SunFlower(idle).png"))
            debug("failed to load player texture");
}

void Plant::handel_animation(){
    if((type == PeaShooter)||(type == SnowpeaShooter))
        handel_action_animation();
    if((type == SunFlower))
        handel_idle_animation();
}

void Plant::handel_action_animation(){
    Time animationelapsed = animationclock.getElapsedTime();
    if(animationelapsed.asMilliseconds() >= 200){
        animationclock.restart();
        IntRect rect;
        rect.top = 2;
        cur_rect = (cur_rect + 1) % 3;
        rect.left = plant_action_animation_rect[cur_rect]+10;
        rect.width = 70; 
        rect.height = 70;
        sprite.setTextureRect(rect);
    }
}

void Plant::handel_idle_animation(){
    Time animationelapsed = animationclock.getElapsedTime();
    if(animationelapsed.asMilliseconds() >= 200){
        animationclock.restart();
        IntRect rect;
        rect.top = 2;
        cur_rect = (cur_rect + 1) % 6;
        rect.left = plant_idle_animation_rect[cur_rect]+10;
        rect.width = 70; 
        rect.height = 70;
        sprite.setTextureRect(rect);
    }
}