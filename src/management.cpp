#include "management.hpp"

PeashooterCard::PeashooterCard(){
    pos = Vector2f(10, 10);
    if (!texture.loadFromFile(PICS_PATH + "PeashooterCard.png")) {
        debug("failed to load player texture");
    }
    IntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 48;
    rect.height = 68;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(1, 1);
    sprite.setPosition(pos);
}

PeashooterCard::~PeashooterCard(){

}

void PeashooterCard::render(RenderWindow &window){
    window.draw(sprite);
}

bool PeashooterCard::handle_mouse_press(Vector2i mousePos){
    Vector2f spritePos = sprite.getPosition();
    Vector2f spriteSize = {sprite.getTextureRect().width, sprite.getTextureRect().height};
    if (mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
        mousePos.y >= spritePos.y && mousePos.y <= spritePos.y + spriteSize.y)
    {
        is_tagged = true;
    }
    return is_tagged;
}