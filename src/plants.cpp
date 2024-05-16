#include "plants.hpp"

Plant::Plant(int x, int y){
    type = EmptyPlant;
    set_plant_texture();
    pos = Vector2f(x, y);
    IntRect rect;
    rect.top = 2;
    rect.left = 2;
    rect.width = 70;
    rect.height = 70;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(1, 1);
    sprite.setPosition(pos);
}

Plant::~Plant(){
for(auto p : projectiles)
        delete p;
}

void Plant::render(RenderWindow &window){
    window.draw(sprite);
// for(auto p : projectiles)
        // p->render(window);
}

void Plant::update(Vector2i pos){
    if((type == SnowpeaShooter)||(type == PeaShooter)){
        handel_animation();
    }
    if(type == EmptyPlant){
        Vector2f spritePos = sprite.getPosition();
        Vector2f spriteSize = {sprite.getTextureRect().width, sprite.getTextureRect().height};
        if (pos.x >= spritePos.x && pos.x <= spritePos.x + spriteSize.x &&
            pos.y >= spritePos.y && pos.y <= spritePos.y + spriteSize.y)
        {
            type = SelectedPlant;
            set_plant_texture();
        }
    }
    if(type == SelectedPlant){
        Vector2f spritePos = sprite.getPosition();
        Vector2f spriteSize = {sprite.getTextureRect().width, sprite.getTextureRect().height};
        if (!(pos.x >= spritePos.x && pos.x <= spritePos.x + spriteSize.x &&
            pos.y >= spritePos.y && pos.y <= spritePos.y + spriteSize.y))
        {
            type = EmptyPlant;
            set_plant_texture();
        }
    }
    fix_position();
}

void Plant::fix_position(){
    FloatRect rect = sprite.getGlobalBounds();
    rect.top = max(0.f, rect.top);
    rect.top = min(rect.top, HEIGHT - rect.height);
    rect.left = max(0.f, rect.left);
    rect.left = min(rect.left, WIDTH - rect.width);
    sprite.setPosition(rect.left, rect.top);
}

Vector2f Plant::get_projectile_pos(){
    return Vector2f(sprite.getPosition().x + 60, sprite.getPosition().y + 15);
}
Projectile_Type Plant::get_projectile_type(){
    Projectile_Type output_projectile_type;
    if(type == PeaShooter)
        output_projectile_type = Pea;
    else if(type == SnowpeaShooter)
        output_projectile_type = Snowpea;
    return output_projectile_type;
}

void Plant::handle_mouse_press(Vector2i mousePos, Plant_Type input_type){
    Vector2f spritePos = sprite.getPosition();
    Vector2f spriteSize = {sprite.getTextureRect().width, sprite.getTextureRect().height};
    if (mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
        mousePos.y >= spritePos.y && mousePos.y <= spritePos.y + spriteSize.y)
    {
        type = input_type;
        set_plant_texture();
    }
}

void Plant::handle_mouse_release(Vector2i mousePos){
    is_fixed = false;
}

void Plant::set_plant_texture(){
    if(type == EmptyPlant){
          if (!texture.loadFromFile(PICS_PATH + "EmptyPlant.png")) {
              debug("failed to load player texture");
          }
      }
      else if(type == SelectedPlant){
          if (!texture.loadFromFile(PICS_PATH + "SelectedPlant.png")) {
              debug("failed to load player texture");
          }
      }
      else if(type == PeaShooter){
          if (!texture.loadFromFile(PICS_PATH + "PeaShooter(attack).png")) {
              debug("failed to load player texture");
          }
      }
      else if(type == SnowpeaShooter){
          if (!texture.loadFromFile(PICS_PATH + "SnowpeaShooter(attack).png")) {
              debug("failed to load player texture");
          }
      }
}

void Plant::handel_animation(){
    
    Time animationelapsed = animationclock.getElapsedTime();
    if(animationelapsed.asMilliseconds() >= 200){
        animationclock.restart();
        IntRect rect;
        rect.top = 2;
        cur_rect = (cur_rect + 1) % 3;
        rect.left = abnormal_animation_rect[cur_rect];
        rect.width = 80; 
        rect.height = 80;
        sprite.setTextureRect(rect);
    }
}