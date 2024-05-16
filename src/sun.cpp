#include "sun.hpp"

Sun::Sun(Vector2f p){
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
        clamed_suns += 50;
        cout << clamed_suns << endl;
    }
    return clamed_suns;
}
    
bool Sun::is_out(){
    return (sprite.getPosition().y > HEIGHT + 10)||clamed;
}

void Sun::set_sun_texture(){
    if (!texture.loadFromFile(PICS_PATH + "Sun.png"))
        debug("failed to load sun texture");
}
