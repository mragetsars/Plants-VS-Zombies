#pragma once

#include "global.hpp"

class Sun{
public:
    Sun(Vector2f pos);
    ~Sun();
    void update();
    void render(RenderWindow &window);
    int handle_mouse_press(Vector2i mousePos, int clamed_suns);
    bool is_out();
private:
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    bool clamed;
    const float speed = 0.25;
    void set_sun_texture();
};