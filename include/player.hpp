#pragma once

#include "global.hpp"


class Player{
public:
    Player(int x, int y);
    ~Player();
    void render(RenderWindow &window);
    void update(Vector2i pos);
    void handle_mouse_press(Vector2i pos);
    void handle_mouse_release(Vector2i pos);
    Vector2f get_projectile_pos();
private:
    Texture texture;
    Sprite sprite;
    IntRect rect;
    Vector2f pos;
    bool is_tagged = false;
    void fix_position();
};