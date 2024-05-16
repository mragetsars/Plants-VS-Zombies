#include "card.hpp"

Card::Card(Vector2f input_pos, Card_Type input_type){
    selected = false;
    active = false;
    type = input_type;
    pos = input_pos;
    set_card_texture();
    set_card_price();
    IntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 49;
    rect.height = 69;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(1, 1);
    sprite.setPosition(pos);
    selected_sprite.setTexture(selected_texture);
    selected_sprite.setTextureRect(rect);
    selected_sprite.setScale(1, 1);
    selected_sprite.setPosition(pos);
    inactive_sprite.setTexture(inactive_texture);
    inactive_sprite.setTextureRect(rect);
    inactive_sprite.setScale(1, 1);
    inactive_sprite.setPosition(pos);
}

Card::~Card(){
}

int Card::update(int colected_suns, bool select_check){ 
    if(select_check){
        if(selected)
            colected_suns -= price;
        selected = false;
    }
    if(colected_suns >= price)
        active = true;
    else
        active = false;
    return colected_suns;
}

void Card::render(RenderWindow &window){
    window.draw(sprite);
    if(!active)
         window.draw(inactive_sprite);
    if(selected)
        window.draw(selected_sprite);
}

void Card::set_card_texture(){
    if (!selected_texture.loadFromFile(PICS_PATH + "c_SelectedCard.png"))
        debug("failed to load player texture");
    if (!inactive_texture.loadFromFile(PICS_PATH + "c_InactiveCard.png"))
        debug("failed to load player texture");
    if(type == PeaShooterCard)
        if (!texture.loadFromFile(PICS_PATH + "c_PeaShooterCard.png"))
            debug("failed to load player texture");
    if(type == SnowpeaShooterCard)
        if (!texture.loadFromFile(PICS_PATH + "c_SnowpeaShooterCard.png"))
            debug("failed to load player texture");
    if(type == SunFlowerCard)
        if (!texture.loadFromFile(PICS_PATH + "c_SunFlowerCard.png"))
            debug("failed to load player texture");
    if(type == WallnutCard)
        if (!texture.loadFromFile(PICS_PATH + "c_WallnutCard.png"))
            debug("failed to load player texture");
}

void Card::set_card_price(){
    if(type == PeaShooterCard)
        price = 100;
    if(type == SnowpeaShooterCard)
        price = 175;
    if(type == SunFlowerCard)
        price = 50;
    if(type == WallnutCard)
        price = 50;
}

bool Card::handle_mouse_press(Vector2i mousePos){
    Vector2f spritePos = sprite.getPosition();
    Vector2f spriteSize = {sprite.getTextureRect().width, sprite.getTextureRect().height};
    if ((mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
        mousePos.y >= spritePos.y && mousePos.y <= spritePos.y + spriteSize.y)&&active)
        selected = true;
    else
        selected = false;
    return selected;
}