#include "menu_handler.hpp"

Menu_Handler::Menu_Handler (){
    IntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 340;
    rect.height = 105;
    if (!StartKeyTexture.loadFromFile(PICS_PATH + "StartKey.png")) {
        debug("failed to load image");
    }
    StartKeySprite.setTexture(StartKeyTexture);
    StartKeySprite.setTextureRect(rect);
    StartKeySprite.setScale(1, 1);
    StartKeySprite.setPosition(655 ,160);
    if (!ExitKeyTexture.loadFromFile(PICS_PATH + "ExitKey.png")) {
        debug("failed to load image");
    }
    ExitKeySprite.setTexture(ExitKeyTexture);
    ExitKeySprite.setTextureRect(rect);
    StartKeySprite.setScale(1, 1);
    ExitKeySprite.setPosition(655 ,330);
}

Menu_Handler::~Menu_Handler(){
}

void Menu_Handler::update(Vector2i mousePos){
    cm = false;
    StartKey = false;
    ExitKey = false;
    Vector2f sspritePos = StartKeySprite.getPosition();
    Vector2f sspriteSize = {StartKeySprite.getTextureRect().width, StartKeySprite.getTextureRect().height};
    if (mousePos.x >= sspritePos.x && mousePos.x <= sspritePos.x + sspriteSize.x &&
        mousePos.y >= sspritePos.y && mousePos.y <= sspritePos.y + sspriteSize.y)
    {
        StartKey = true;
    }
    Vector2f espritePos = ExitKeySprite.getPosition();
    Vector2f espriteSize = {ExitKeySprite.getTextureRect().width, ExitKeySprite.getTextureRect().height};
    if (mousePos.x >= espritePos.x && mousePos.x <= espritePos.x + espriteSize.x &&
        mousePos.y >= espritePos.y && mousePos.y <= espritePos.y + espriteSize.y)
    {
        ExitKey = true;
    }
    if (mousePos.x >= 0 && mousePos.x <= 0 + 10 &&
        mousePos.y >= 0 && mousePos.y <= 0 + 10)
    {
        cm = true;
    }
}

void Menu_Handler::render(RenderWindow &window){
    if(StartKey)
        window.draw(StartKeySprite);
    if(ExitKey)
        window.draw(ExitKeySprite);
}

bool Menu_Handler::check_start(){
    return StartKey;
}

bool Menu_Handler::check_exit(){
    return ExitKey;
}