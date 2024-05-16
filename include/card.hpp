#pragma once

#include "global.hpp"

enum Card_Type {
  PeaShooterCard,
  SnowpeaShooterCard,
  SunFlowerCard,
  WallnutCard,
};

class Card{
public:
    Card(Vector2f input_pos, Card_Type input_type, Setting* s);
    ~Card();
    int update(int colected_suns, bool select_check);
    void render(RenderWindow &window);
    bool handle_mouse_press(Vector2i mousePos);
    bool active;
private:
    Setting* setting;
    Card_Type type;
    Texture texture;
    Sprite sprite;
    Texture selected_texture;
    Sprite selected_sprite;
    Texture inactive_texture;
    Sprite inactive_sprite;
    Vector2f pos;
    bool selected;
    int price;
    void set_card_texture();
    void setup();
};