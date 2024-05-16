#include "system.hpp"

System::System(int width, int height) {
  window.create(VideoMode(width, height), "PVZ", Style::Default);
  window.setFramerateLimit(FRAME_RATE);
  state = GAME;
  set_background_texture();
  backgroundSprite.setTexture(backgroundTexture);
  if (!music.openFromFile(AUDIO_PATH + "bg.ogg")){
    debug("failed to load music");
  }
  music.setLoop(true);
  music.play();
  game_handler = new Game_Handler();
}

System::~System() {
    delete game_handler;
}

void System::run() {
  while (window.isOpen() /*and state != EXIT*/) {
    update();
    render();
    handle_events();
  }
  exit(0);
}

void System::handle_events() {
  Event event;
  while (window.pollEvent(event)) {
    switch (event.type) {
    case (Event::Closed):
      window.close();
      // state = EXIT;
      break;
    case (Event::MouseButtonPressed):
      handle_mouse_press(event);
      break;
    case (Event::MouseButtonReleased):
      break;
    default:
      break;
    }
  }
}

void System::update() {
  Vector2i pos = Mouse::getPosition(window);
  switch (state) {
  case (GAME):
    game_handler->update(pos);
    break;
  // case (PAUSE_MENU):
  //   break;
  // case (MAIN_MENU):
  //   break;
  // case (VICTORY_SCREEN):
  //   break;
  // case (GAMEOVER_SCREEN):
  //   break;
  }
}

void System::render() {
  window.clear();
  switch (state) {
  case (GAME):
    window.draw(backgroundSprite);
    game_handler->render(window);
    break;
  // case (PAUSE_MENU):
  //   break;
  // case (MAIN_MENU):
  //   break;
  // case (VICTORY_SCREEN):
  //   break;
  // case (GAMEOVER_SCREEN):
  //   break;
  }
  window.display();
}

void System::handle_mouse_press(Event ev) {
  if (ev.mouseButton.button == Mouse::Right)
    return;
  Vector2i pos = {ev.mouseButton.x, ev.mouseButton.y};
  switch (state) {
  case (GAME):
    game_handler->handle_mouse_press(pos);
    break;
  // case (PAUSE_MENU):
  //   break;
  // case (MAIN_MENU):
  //   break;
  // case (VICTORY_SCREEN):
  //   break;
  // case (GAMEOVER_SCREEN):
  //   break;
  }
}

void System::set_background_texture(){
  if (!backgroundTexture.loadFromFile(PICS_PATH + "DayBackground.png")) {
    debug("failed to load image");
  }
  // if (!backgroundTexture.loadFromFile(PICS_PATH + "NightBackground.png")) {
  //   debug("failed to load image");
  // }
}