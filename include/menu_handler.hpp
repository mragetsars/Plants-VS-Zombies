#pragma once

#include "global.hpp"

class Menu_Handler{
public:
    Menu_Handler ();
    ~Menu_Handler();
    void update(Vector2i mousePos);
    void render(RenderWindow &window);
    bool check_start();
    bool check_exit();
    bool cm;
private:
    Texture StartKeyTexture;
    Sprite StartKeySprite;
    bool StartKey;
    Texture ExitKeyTexture;
    Sprite ExitKeySprite;
    bool ExitKey;
};