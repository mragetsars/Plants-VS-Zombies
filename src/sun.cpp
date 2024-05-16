#include "sun.hpp"

Sun::Sun(Vector2f p, Setting* s){
    setting = s;
    pos = p;
    set_sun_texture();
    IntRect rect;
    rect.top = 3;
    rect.left = 2;
    rect.width = 43;
    rect.height = 43;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(1, 1);
    clamed = false;
}
       
Sun::~Sun(){
}

void Sun::update(){
    pos.y += speed;
    sprite.setPosition(pos);
}

void Sun::render(RenderWindow &window){
    window.draw(sprite);
}

int Sun::handle_mouse_press(Vector2i mousePos, int clamed_suns){
    Vector2f spritePos = sprite.getPosition();
    Vector2f spriteSize = {sprite.getTextureRect().width, sprite.getTextureRect().height};
    if (mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
        mousePos.y >= spritePos.y && mousePos.y <= spritePos.y + spriteSize.y)
    {
        clamed = true;
        clamed_suns += setting->Sun.Interval;
    }
    return clamed_suns;
}
    
bool Sun::is_out(){
    return (sprite.getPosition().y > HEIGHT + 10)||clamed;
}

void Sun::set_sun_texture(){
    if (!texture.loadFromFile(PICS_PATH + "v_Sun.png"))
        debug("failed to load sun texture");
}

SunSign::SunSign(){
    if (!texture.loadFromFile(PICS_PATH + "c_SunCard.png"))
        debug("failed to load player texture");
    IntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 115;
    rect.height = 25;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setScale(1.5, 1.5);
    sprite.setPosition(Vector2f(10, 553));
    if (!font.loadFromFile(FONTS_PATH + "SunSignFont.otf"))
        debug("failed to load player texture");
    text.setFont(font);
    text.setFillColor(Color::Black);
    text.setCharacterSize(24);
    text.setPosition(Vector2f(25, 556));
}

SunSign::~SunSign(){
}

void SunSign::update(int colected_suns){ 
    text.setString(to_string(colected_suns));
}

void SunSign::render(RenderWindow &window){
    window.draw(sprite);
    window.draw(text);
}


