#pragma once

#include "global.hpp"

class PeashooterCard{
public:
    PeashooterCard();
    ~PeashooterCard();
    void render(RenderWindow &window);
    bool handle_mouse_press(Vector2i pos);
private:
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    bool is_tagged = false;
};