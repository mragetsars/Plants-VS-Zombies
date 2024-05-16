#include "plant.hpp"

Plant::Plant(int x, int y, Setting* s){
    setting = s;
    type = EmptyPlant;
    action = false;
    setup();
    set_plant_texture();
    pos = Vector2f(x, y);
    IntRect rect;
    rect.top = 2;
    rect.left = 12;
    rect.width = 70;
    rect.height = 80;
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
    if(!((type == SelectedPlant)||(type == EmptyPlant)))
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

Projectile* Plant::get_projectile(){
    Projectile_Type output_projectile_type;
    if(type == PeaShooter)
        output_projectile_type = Pea;
    else if(type == SnowpeaShooter)
        output_projectile_type = Snowpea;
    Vector2f output_projectile_pos = Vector2f(sprite.getPosition().x + 50, sprite.getPosition().y + 12);
    return new Projectile(output_projectile_pos, output_projectile_type, setting);
}

bool Plant::handle_mouse_press(Vector2i mousePos, Plant_Type input_type){
    Vector2f spritePos = sprite.getPosition();
    Vector2f spriteSize = {sprite.getTextureRect().width, sprite.getTextureRect().height};
    if (mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
        mousePos.y >= spritePos.y && mousePos.y <= spritePos.y + spriteSize.y)
    {
        type = input_type;
        setup();
        set_plant_texture();
        return true;
    }
    else
        return false;
}

void Plant::input_damage(int input_damage){
    if(health - input_damage > 0){
        health -= input_damage;
    }else{
        type = EmptyPlant;
        action = false;
        setup();
        set_plant_texture();
        IntRect rect;
        rect.top = 2;
        rect.left = 12;
        rect.width = 70;
        rect.height = 80;
        sprite.setTexture(texture);
        sprite.setTextureRect(rect);
        sprite.setScale(1, 1);
        sprite.setPosition(pos);
    }
}

FloatRect Plant::get_rect(){
    return sprite.getGlobalBounds();
}

void Plant::setup(){
    switch (type){
    case (EmptyPlant):
        health = 0;
        break;
    case (SelectedPlant):
        health = 0;
        break;
    case (PeaShooter):
        health = setting->PeaShooter.Health;
        break;
    case (SnowpeaShooter):
        health = setting->SnowpeaShooter.Health;
        break;
    case (SunFlower):
        health = setting->SunFlower.Health;
        break;
    case (Wallnut):
        health = setting->Wallnut.Health;
        break;
    }
}

void Plant::set_plant_texture(){
    switch (type){
    case (EmptyPlant):
        if (!texture.loadFromFile(PICS_PATH + "p_EmptyPlant.png"))
            debug("failed to load player texture");
        break;
    case (SelectedPlant):
        if (!texture.loadFromFile(PICS_PATH + "p_SelectedPlant.png"))
            debug("failed to load player texture");
        break;
    case (PeaShooter):
        if(action){
            if (!texture.loadFromFile(PICS_PATH + "p_PeaShooter(attack).png"))
                debug("failed to load player texture");
        }else{
            if (!texture.loadFromFile(PICS_PATH + "p_PeaShooter(idle).png"))
                debug("failed to load player texture");
        }
        break;
    case (SnowpeaShooter):
        if(action){
            if (!texture.loadFromFile(PICS_PATH + "p_SnowpeaShooter(attack).png"))
                debug("failed to load player texture");
        }else{
            if (!texture.loadFromFile(PICS_PATH + "p_SnowpeaShooter(idle).png"))
                debug("failed to load player texture");
        }
        break;
    case (SunFlower):
        if(action){
            if (!texture.loadFromFile(PICS_PATH + "p_SunFlower(glow).png"))
                debug("failed to load player texture");
        }else{
            if (!texture.loadFromFile(PICS_PATH + "p_SunFlower(idle).png"))
                debug("failed to load player texture");
        }
        break;
    case (Wallnut):
        if(health >= 150)
            if (!texture.loadFromFile(PICS_PATH + "p_Wallnut(idle).png"))
                debug("failed to load player texture");
        if((health < 100)&&(health > 50))
            if (!texture.loadFromFile(PICS_PATH + "p_Wallnut(cracked).png"))
                debug("failed to load player texture");
        if(health <= 50)
            if (!texture.loadFromFile(PICS_PATH + "p_Wallnut(verycracked).png"))
                debug("failed to load player texture");
        break;
    }
}

void Plant::handel_animation(){
    if(action)
        set_plant_texture();
    else  
        set_plant_texture();
    Time animationelapsed = animationclock.getElapsedTime();
    if(animationelapsed.asMilliseconds() >= 200){
        animationclock.restart();
        IntRect rect;
        rect.top = 2;
        cur_rect = (cur_rect + 1) % 6;
        rect.left = plant_animation_rect[cur_rect]+10;
        rect.width = 70; 
        rect.height = 70;
        sprite.setTextureRect(rect);
    }
}