#include "card.hpp"

Card::Card(Vector2f input_pos, Card_Type input_type){
    type = input_type;
    pos = input_pos;
    set_card_texture();
    IntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 49;
    rect.height = 69;
    sprite1.setTexture(texture);
    sprite1.setTextureRect(rect);
    sprite1.setScale(1, 1);
    sprite1.setPosition(pos);
    // sprite2.setTexture(texture);
    // sprite2.setTextureRect(rect);
    // sprite2.setScale(1, 1);
    // sprite2.setPosition(Vector2f(80,80));
}

Card::~Card(){

}

void Card::render(RenderWindow &window){
    window.draw(sprite1);
    // window.draw(sprite2);
}

// bool Card::handle_mouse_press(Vector2i mousePos){
//     Vector2f spritePos = sprite.getPosition();
//     Vector2f spriteSize = {sprite.getTextureRect().width, sprite.getTextureRect().height};
//     if (mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
//         mousePos.y >= spritePos.y && mousePos.y <= spritePos.y + spriteSize.y)
//     {

//     }
// }

void Card::set_card_texture(){
    if(type == PeaShooterCard)
        if (!texture.loadFromFile(PICS_PATH + "PeaShooterCard.png"))
            debug("failed to load player texture");
    if(type == SnowpeaShooterCard)
        if (!texture.loadFromFile(PICS_PATH + "SnowpeaShooterCard.png"))
            debug("failed to load player texture");
    if(type == SunFlowerCard)
        if (!texture.loadFromFile(PICS_PATH + "SunFlowerCard.png"))
            debug("failed to load player texture");
}