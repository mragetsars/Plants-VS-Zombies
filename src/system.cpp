#include "system.hpp"

System::System(int width, int height) {
  window.create(VideoMode(width, height), "PVZ", Style::Default);
  window.setFramerateLimit(FRAME_RATE);
  state = MENU;
  screenmode = Day;
  set_background_texture();
  set_gameover_texture();
  set_menu_texture();
  if (!music.openFromFile(AUDIO_PATH + "bg.ogg")){
    debug("failed to load music");
  }
  music.setLoop(true);
  music.play();
  menu_handler = new Menu_Handler();
}

System::~System() {
    delete game_handler;
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
    if(game_handler->check_gameover())
      state = GAMEOVER_SCREEN;
    break;
  // case (PAUSE_MENU):
  //   break;
  case (MENU):
    menu_handler->update(pos);
    break;
  case (GAMEOVER_SCREEN):
    break;
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
  case (MENU):
    window.draw(menuSprite);
    menu_handler->render(window);
    break;
  case (GAMEOVER_SCREEN):
    window.draw(gameoverSprite);
    break;
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
  case (MENU):
    if(menu_handler->check_start()){
      game_handler = new Game_Handler();
      state = GAME;
    }
    if(menu_handler->check_exit()){
      // state = EXIT;
      if(screenmode == Day)
        screenmode = Night;
      else if(screenmode == Night)
        screenmode = Day;
      set_background_texture();
      set_gameover_texture();
      set_menu_texture();
    }
    break;
  case (GAMEOVER_SCREEN):
    delete game_handler;
    state = MENU;
    break;
  }
}

void System::set_background_texture(){
  if(screenmode == Day)
    if (!backgroundTexture.loadFromFile(PICS_PATH + "DayBackground.png")) {
      debug("failed to load image");
    }
  if(screenmode == Night)
    if (!backgroundTexture.loadFromFile(PICS_PATH + "NightBackground.png")) {
      debug("failed to load image");
    }
  backgroundSprite.setTexture(backgroundTexture);
}

void System::set_menu_texture(){
  if(screenmode == Day)
    if (!menuTexture.loadFromFile(PICS_PATH + "DayMenu.png")) {
      debug("failed to load image");
    }
  if(screenmode == Night)
    if (!menuTexture.loadFromFile(PICS_PATH + "NightMenu.png")) {
      debug("failed to load image");
    }
  menuSprite.setTexture(menuTexture);
}

void System::set_gameover_texture(){
  if (!gameoverTexture.loadFromFile(PICS_PATH + "GameOverScreen.png")) {
    debug("failed to load image");
  }
  gameoverSprite.setTexture(gameoverTexture);
}