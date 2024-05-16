#include "system.hpp"

System::System(int width, int height) {
  window.create(VideoMode(width, height), "PVZ Mola", Style::Close);
  window.setFramerateLimit(FRAME_RATE);
  state = IN_GAME;
  player = new Player(100, 100);
  if (!backgroundTexture.loadFromFile(PICS_PATH + "nbg.png")) {
    debug("failed to load image");
  }
  backgroundSprite.setTexture(backgroundTexture);
  if (!music.openFromFile(AUDIO_PATH + "bg.ogg")){
    debug("failed to load music");
  }
  music.setLoop(true);
  music.play();
  handler = new Handler(player);
}

System::~System() {
    delete player;
    delete handler;
}

void System::run() {
  while (window.isOpen() and state != EXIT) {
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
      state = EXIT;
      break;
    case (Event::KeyPressed):
      handle_key_down(event.key.code);
      break;
    case (Event::KeyReleased):
      handle_key_up(event.key.code);
      break;
    case (Event::MouseButtonPressed):
      handle_mouse_press(event);
      break;
    case (Event::MouseButtonReleased):
      handle_mouse_release(event);
      break;
    default:
      break;
    }
  }
}

void System::update() {
  Vector2i pos = Mouse::getPosition(window);
  switch (state) {
  case (IN_GAME):
    player->update(pos);
    handler->update();
    break;
  case (PAUSE_MENU):
    break;
  case (MAIN_MENU):
    break;
  case (VICTORY_SCREEN):
    break;
  case (GAMEOVER_SCREEN):
    break;
  }
}

void System::render() {
  window.clear();
  switch (state) {
  case (IN_GAME):
    window.draw(backgroundSprite);
    player->render(window);
    handler->render(window);
    break;
  case (PAUSE_MENU):
    break;
  case (MAIN_MENU):
    break;
  case (VICTORY_SCREEN):
    break;
  case (GAMEOVER_SCREEN):
    break;
  }
  window.display();
}

void System::handle_key_up(Keyboard::Key key) {
  switch (state) {
  case (IN_GAME):
    break;
  case (PAUSE_MENU):
    break;
  case (MAIN_MENU):
    break;
  case (VICTORY_SCREEN):
    break;
  case (GAMEOVER_SCREEN):
    break;
  }
}

void System::handle_key_down(Keyboard::Key key) {
  switch (state) {
  case (IN_GAME):
    break;
  case (PAUSE_MENU):
    break;
  case (MAIN_MENU):
    break;
  case (VICTORY_SCREEN):
    break;
  case (GAMEOVER_SCREEN):
    break;
  }
}

void System::handle_mouse_press(Event ev) {
  if (ev.mouseButton.button == Mouse::Right)
    return;
  Vector2i pos = {ev.mouseButton.x, ev.mouseButton.y};
  switch (state) {
  case (IN_GAME):
    player->handle_mouse_press(pos);
    break;
  case (PAUSE_MENU):
    break;
  case (MAIN_MENU):
    break;
  case (VICTORY_SCREEN):
    break;
  case (GAMEOVER_SCREEN):
    break;
  }
}

void System::handle_mouse_release(Event ev) {
  if (ev.mouseButton.button == Mouse::Right)
    return;
  Vector2i pos = {ev.mouseButton.x, ev.mouseButton.y};
  switch (state) {
  case (IN_GAME):
    player->handle_mouse_release(pos);
    break;
  case (PAUSE_MENU):
    break;
  case (MAIN_MENU):
    break;
  case (VICTORY_SCREEN):
    break;
  case (GAMEOVER_SCREEN):
    break;
  }
}