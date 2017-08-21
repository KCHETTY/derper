#pragma once

#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../Graphics_lib/Inc/Base.hpp"

enum eBlockType
{
	OPEN_TERRAIN = 0,
	SOLID_BLOCK,
	DESTRUCTIBLE_BLOCK,
	ENEMY_BLOCK,
	GATE, //ON TOP OF GATE WILL CREATE DESTRUCTIBLE_BLOCK
	PLAYER
};

enum eMovementDir
{
	UP = 0,
	RIGHT,
	DOWN,
	LEFT
};

enum eGamestate
{
	SPLASH_SCREEN = 0,
	MENU,
	GAME,
	LEVEL_SELECT,
	SETTINGS,
	LOAD_GAME,
	//  BONUS: TUTORIAL
	//  BONUS: MAP EDITOR
	CREDITS
};

enum ePowerups
{
	POW_RANGE = 0,
	POW_BOMBS,
	POW_SPEED,
	POW_LIFE
};

enum eScore
{
	ENEMY,
	LIVES,
	POWERUPS,
	TIME_LEFT
};


#define GRID_X 48
#define GRID_Y 48
#define MAP_X 16
#define MAP_Y 16
#define FIXED_FPS 60
#define BOMB_COOLDOWN 20
#define ENEMY_MOVE_TICK 4 * FIXED_FPS
