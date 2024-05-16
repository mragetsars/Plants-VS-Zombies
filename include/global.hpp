#pragma once

#include <array>
#include <deque>
#include <math.h>
#include <random>
#include <chrono>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <stdexcept>
#include <algorithm>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const float PI = acos(-1);
const int WIDTH = 1400;
const int HEIGHT = 600;
const int FRAME_RATE = 60;
const int FARM_LINES[5] = {90, 190, 290, 390, 490};
const int FARM_COLUMNs[9] = {260, 340, 430, 505, 580, 660, 740, 820, 900};

const string PICS_PATH = "./files/pics/",
             AUDIO_PATH = "./files/audio/",
             FONTS_PATH = "./files/fonts/";

const int plant_action_animation_rect[6] = {2, 86, 170, 2, 86, 170};
const int plant_animation_rect[6] = {2, 86, 170, 254, 338, 422};
const int zombie_animation_rect[7] = {3, 55, 107, 159, 211, 263, 315};
#define debug(x) cout << x << endl, exit(0);

#include "setting.hpp"

// ZOMBIES:
// hairMetalGargantuar-20-80-6-5
// regular-10-50-5-7

// PLANTS:
// snowpea-8-30-9-5-5-6
// peashooter-5-40-5-5-7-4
// walnut-0-200-10-0-0-2
// sunflower-0-30-10-12-0-2
// kernelPult-15-20-10-8-7-8

// ATTACKS: 100-10-3-1

// SUN: 10-10

// speed- 9 ratehit - health - damage - type%