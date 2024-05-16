#include "plants.hpp"

Shooter::Shooter(int x, int y, Plant_Type input_type){
    type = input_type;
    pos = Vector2f(x, y);
    set_plant_texture();
    IntRect rect;
    rect.top = 2;
    rect.left = 2;
    rect.width = 80;
    rect.height = 80;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(1, 1);
    sprite.setPosition(pos);
}

Shooter::~Shooter(){
    for(auto p : projectiles)
        delete p;
}

void Shooter::render(RenderWindow &window){
    window.draw(sprite);
    for(auto p : projectiles)
        p->render(window);
}

void Shooter::update(Vector2i pos){
    
    if((type == SnowpeaShooter)||(type == PeaShooter)){
        handel_projectile();
        handel_animation();
    }
    if(is_tagged){
        Vector2f target(static_cast<float>(pos.x) - 45, static_cast<float>(pos.y) - 45);
        sprite.setPosition(target);
    }
    fix_position();
}

void Shooter::fix_position(){
    FloatRect rect = sprite.getGlobalBounds();
    rect.top = max(0.f, rect.top);
    rect.top = min(rect.top, HEIGHT - rect.height);
    rect.left = max(0.f, rect.left);
    rect.left = min(rect.left, WIDTH - rect.width);
    sprite.setPosition(rect.left, rect.top);
}

Vector2f Shooter::get_projectile_pos(){
    return Vector2f(sprite.getPosition().x + 60, sprite.getPosition().y + 15);
}

void Shooter::handle_mouse_press(Vector2i mousePos){
    Vector2f spritePos = sprite.getPosition();
    Vector2f spriteSize = {sprite.getTextureRect().width, sprite.getTextureRect().height};
    if (mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
        mousePos.y >= spritePos.y && mousePos.y <= spritePos.y + spriteSize.y)
    {
        is_tagged = true;
    }
}

void Shooter::handle_mouse_release(Vector2i mousePos){
    is_tagged = false;
}

void Shooter::add_projectile(){
    Projectile* p;
    if(type == SnowpeaShooter)
        p = new Projectile(get_projectile_pos(), Icepea);
    if(type == PeaShooter)
        p = new Projectile(get_projectile_pos(), Pea);
    projectiles.push_back(p);
}

void Shooter::delete_out_of_bounds(){
    vector <Projectile*> trash;
    for(auto p : projectiles){
        if(p->is_out()){
            trash.push_back(p);
        }
    }
    projectiles.erase(remove_if(projectiles.begin(), projectiles.end(), 
        [](auto p){ return p->is_out(); }), projectiles.end());
    for (auto p : trash){
        delete p;
    }
}

void Shooter::set_plant_texture(){
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

void Shooter::handel_animation(){
    Time animationelapsed = animationclock.getElapsedTime();
    if(animationelapsed.asMilliseconds() >= 200){
        animationclock.restart();
        cur_rect = (cur_rect + 1) % 3;
        IntRect rect;
        rect.top = 2;
        rect.left = animation_rect[cur_rect];
        rect.width = 80; 
        rect.height = 80;
        sprite.setTextureRect(rect);
    }
}

void Shooter::handel_projectile(){
    Time projectileelapsed = projectileclock.getElapsedTime();
    if(projectileelapsed.asMilliseconds() >= 600){
        projectileclock.restart();
        add_projectile();
    }
    for(auto p : projectiles){
        p->update();
    }
}