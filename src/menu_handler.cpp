#include "menu_handler.hpp"

Menu_Handler::Menu_Handler (){
    IntRect srect;
    srect.top = 0;
    srect.left = 0;
    srect.width = 340;
    srect.height = 105;
    if (!StartKeyTexture.loadFromFile(PICS_PATH + "s_StartKey.png")) {
        debug("failed to load image");
    }
    StartKeySprite.setTexture(StartKeyTexture);
    StartKeySprite.setTextureRect(srect);
    StartKeySprite.setScale(1, 1);
    StartKeySprite.setPosition(655 ,160);
    IntRect erect;
    erect.top = 0;
    erect.left = 0;
    erect.width = 340;
    erect.height = 105;
    if (!ExitKeyTexture.loadFromFile(PICS_PATH + "s_ExitKey.png")) {
        debug("failed to load image");
    }
    ExitKeySprite.setTexture(ExitKeyTexture);
    ExitKeySprite.setTextureRect(erect);
    StartKeySprite.setScale(1, 1);
    ExitKeySprite.setPosition(655 ,330);
    IntRect mrect;
    mrect.top = 0;
    mrect.left = 0;
    mrect.width = 1400;
    mrect.height = 400;
    if (!ModeKeyTexture.loadFromFile(PICS_PATH + "s_ModeKey.png")) {
        debug("failed to load image");
    }
    ModeKeySprite.setTexture(ModeKeyTexture);
    ModeKeySprite.setTextureRect(mrect);
    ModeKeySprite.setScale(1, 1);
    ModeKeySprite.setPosition(0 ,0);
}

Menu_Handler::~Menu_Handler(){
}

void Menu_Handler::update(Vector2i mousePos){
    StartKey = false;
    ExitKey = false;
    ModeKey = false;
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
    Vector2f mspritePos = ModeKeySprite.getPosition();
    Vector2f mspriteSize = {ModeKeySprite.getTextureRect().width, ModeKeySprite.getTextureRect().height/4};
    if (mousePos.x >= mspritePos.x && mousePos.x <= mspritePos.x + mspriteSize.x &&
        mousePos.y >= mspritePos.y && mousePos.y <= mspritePos.y + mspriteSize.y)
    {
        ModeKey = true;
    }
}

void Menu_Handler::render(RenderWindow &window){
    if(StartKey)
        window.draw(StartKeySprite);
    if(ExitKey)
        window.draw(ExitKeySprite);
    if(ModeKey)
        window.draw(ModeKeySprite);
}

bool Menu_Handler::check_start(){
    return StartKey;
}

bool Menu_Handler::check_exit(){
    return ExitKey;
}

bool Menu_Handler::check_mode(){
    return ModeKey;
}