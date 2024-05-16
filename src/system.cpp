#include "system.hpp"

System::System(int width, int height) {
  window.create(VideoMode(width, height), "PVZ", Style::Close);
  window.setFramerateLimit(FRAME_RATE);
  state = IN_GAME;
  peashooters.push_back(new Shooter(FARM_COLUMNs[0], FARM_LINES[0], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[0], FARM_LINES[1], EmptyPlant));
  peashooters.push_back(new Shooter(FARM_COLUMNs[0], FARM_LINES[2], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[0], FARM_LINES[3], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[0], FARM_LINES[4], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[1], FARM_LINES[0], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[1], FARM_LINES[1], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[1], FARM_LINES[2], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[1], FARM_LINES[3], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[1], FARM_LINES[4], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[2], FARM_LINES[0], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[2], FARM_LINES[1], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[2], FARM_LINES[2], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[2], FARM_LINES[3], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[2], FARM_LINES[4], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[3], FARM_LINES[0], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[3], FARM_LINES[1], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[3], FARM_LINES[2], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[3], FARM_LINES[3], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[3], FARM_LINES[4], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[4], FARM_LINES[0], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[4], FARM_LINES[1], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[4], FARM_LINES[2], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[4], FARM_LINES[3], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[4], FARM_LINES[4], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[5], FARM_LINES[0], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[5], FARM_LINES[1], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[5], FARM_LINES[2], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[5], FARM_LINES[3], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[5], FARM_LINES[4], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[6], FARM_LINES[0], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[6], FARM_LINES[1], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[6], FARM_LINES[2], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[6], FARM_LINES[3], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[6], FARM_LINES[4], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[7], FARM_LINES[0], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[7], FARM_LINES[1], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[7], FARM_LINES[2], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[7], FARM_LINES[3], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[7], FARM_LINES[4], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[8], FARM_LINES[0], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[8], FARM_LINES[1], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[8], FARM_LINES[2], SnowpeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[8], FARM_LINES[3], PeaShooter));
  peashooters.push_back(new Shooter(FARM_COLUMNs[8], FARM_LINES[4], SnowpeaShooter));
  if (!backgroundTexture.loadFromFile(PICS_PATH + "NightBackground.png")) {
    debug("failed to load image");
  }
  backgroundSprite.setTexture(backgroundTexture);
  if (!music.openFromFile(AUDIO_PATH + "bg.ogg")){
    debug("failed to load music");
  }
  music.setLoop(true);
  music.play();
  handler1 = new PeashooterHandler(peashooters[0]);
  // handler2 = new PeashooterHandler(peashooters[1]);
}

System::~System() {
    for(auto p : peashooters)
      delete p;
    delete handler1;
    // delete handler2;
}

void System::run() {
  while (window.isOpen() /*Sand state != EXIT*/) {
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
    for(auto p : peashooters)
        p->update(pos);
    handler1->update();
    // handler2->update();
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
  case (IN_GAME):
    window.draw(backgroundSprite);
    for(auto p : peashooters)
        p->render(window);
    handler1->render(window);
    // handler2->render(window);
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
  case (IN_GAME):
    for(auto p : peashooters)
        p->handle_mouse_press(pos);
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

void System::handle_mouse_release(Event ev) {
  if (ev.mouseButton.button == Mouse::Right)
    return;
  Vector2i pos = {ev.mouseButton.x, ev.mouseButton.y};
  switch (state) {
  case (IN_GAME):
    for(auto p : peashooters)
        p->handle_mouse_release(pos);
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