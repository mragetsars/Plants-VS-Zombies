#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <chrono>
#include <deque>
#include <fstream>
#include <iostream>
#include <math.h>
#include <random>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using namespace sf;
using namespace std;

const float PI = acos(-1);
const int WIDTH = 1400;
const int HEIGHT = 600;
const int FRAME_RATE = 160;
const int FARM_LINES[5] = {90, 190, 290, 390, 490};
const int FARM_COLUMNs[9] = {255, 330, 412, 491, 570, 649, 729, 807, 887};
const string PICS_PATH = "./files/pics/", AUDIO_PATH = "./files/audio/",
             FONTS_PATH = "./files/fonts/";
const Color BLUE = Color(50, 115, 220);
const Color PURPLE = Color(130, 50, 220);
const Color YELLOW = Color(255, 248, 220);

#define debug(x) cout << x << endl, exit(0);