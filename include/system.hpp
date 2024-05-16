#pragma once

#include "global.hpp"
#include "game_handler.hpp"
#include "menu_handler.hpp"

enum State {
  GAME,
  // PAUSE,
  MENU,
  GAMEOVER_SCREEN,
  EXIT
};

enum Mode{
  Day,
  Night
};

class System {
public:
  System(int width, int height);
  ~System();
  RenderWindow window;
  void run();

private:
  State state;
  Mode mode;
  Texture backgroundTexture;
  Sprite backgroundSprite;
  void set_background_texture();
  Texture gameoverTexture;
  Sprite gameoverSprite;
  void set_gameover_texture();
  Texture menuTexture;
  Sprite menuSprite;
  void set_menu_texture();
  Music music;
  Game_Handler* game_handler;
  Menu_Handler* menu_handler;
  void handle_events();
  void update();
  void render();
  void handle_mouse_press(Event ev);
};