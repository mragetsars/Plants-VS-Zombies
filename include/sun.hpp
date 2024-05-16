#pragma once

#include "global.hpp"

class Sun{
public:
    Sun(Vector2f pos, Setting* s);
    ~Sun();
    void update();
    void render(RenderWindow &window);
    int handle_mouse_press(Vector2i mousePos, int clamed_suns);
    bool is_out();
private:
    Setting* setting;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    bool clamed;
    const float speed = 0.25;
    void set_sun_texture();
};

class SunSign{
public:
    SunSign();
    ~SunSign();
    void update(int colected_suns);
    void render(RenderWindow &window);
private:
    Texture texture;
    Sprite sprite;
    Font font;
    Text text;
};