#pragma once

#include "global.hpp"
#include "game_handler.hpp"

enum State {
  GAME,
  // PAUSE_MENU,
  // MAIN_MENU,
  // VICTORY_SCREEN,
  GAMEOVER_SCREEN,
  // EXIT
};

class System {
public:
  System(int width, int height);
  ~System();
  RenderWindow window;
  void run();

private:
  State state;
  Game_Handler* game_handler;
  Texture backgroundTexture;
  Sprite backgroundSprite;
  Music music;
  void handle_events();
  void update();
  void render();
  void set_background_texture();
  void handle_mouse_press(Event ev);
};