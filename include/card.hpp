#pragma once

#include "global.hpp"

enum Card_Type {
  PeaShooterCard,
  SnowpeaShooterCard,
  SunFlowerCard,
  SelectedCard,
};

class Card{
public:
    Card(Vector2f input_pos, Card_Type input_type);
    ~Card();
    void render(RenderWindow &window);
    bool handle_mouse_press(Vector2i mousePos);
private:
    Card_Type type;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    void set_card_texture();
};