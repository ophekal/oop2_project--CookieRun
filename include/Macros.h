#pragma once
#include <SFML/Graphics.hpp>


//------------LevelGenerator----------------

const int NUM_OF_PARTS_PER_LEVEL = 4;
const int POSITION_OF_LAST_FLOOR = 50;
const int ENEMIES_PER_LEVEL = 2;

//---------------Buttons--------------------
enum Buttons
{
	B_EXIT,
	B_START,
	B_PLAYER,
	B_INSTRUCTIONS,
	B_SETTINGS,
	B_BACK,
	B_SOUND_ON,
	B_SOUND_OFF,
	B_MUSIC_ON,
	B_MUSIC_OFF,
	B_LEVEL1_ON,
	B_LEVEL1_OFF,
	B_LEVEL2_ON,
	B_LEVEL2_OFF,
	B_LEVEL3_ON,
	B_LEVEL3_OFF,

};

//----------------ChoosePlayers-------------

const float BRAVE_X = 380;
const float BRIGHT_X = 730;
const float PLAYERS_Y = 300;



//---------------Players--------------------
enum Players
{
	CHOOSE_PLAYER_BRAVE,
	CHOOSE_PLAYER_BRIGHT,
	PLAYER_BRAVE,
	PLAYER_BRIGHT
};

const sf::Vector2f PLAYERS_SIZE = { 400,500 };

enum KeyboardInput
{
	K_UP,
	K_DOWN,
	K_ENTER,
	K_NONE
};

const sf::Vector2f PLAYER_INIT_POSITION{ 620,688 };
const int JELLY2ENERGY = 3;
//---------------Player State--------------------------
//const float MaxJump = 1000.0f;
const float MaxJump = 2; // Represents a jump height of 200 pixels
const float MaxDoubleJump = 5.5f;// 2500.0f;
//-----------instructions-------------------



//----------------Setting-------------------

const sf::Vector2f MUSIC_SIZE = { 300,100 };

const float SOUND_X = 600;
const float SOUND_Y = 325;
const float MUSIC_Y = 525;


//-----------------Controller---------------

const int WINDOW_HEIGHT = 950;
const int WINDOW_WIDTH = 1500;


//-----------------InfoBar-------------------




//----------------GameStart---------------------
enum LEVELS
{
	LEVEL1,
	LEVEL2,
	LEVEL3
};

const float LEVEL_Y = 600;
const float LEVEL1_X = 225;
const float LEVEL2_X = 425;
const float LEVEL3_X = 625;


//-----------------Level---------------------
enum LEVELTEXTURE1
{
	L1_BACKGROUND,
	L1_FLOOR,
	L1_ENEMY,
	L1_OBSTACLE1,
	L1_OBSTACLE2,
	L1_OBSTACLE3,
	L1_ANI_OBSTACLE1,
	L1_FLAG
};
enum LEVELTEXTURE2
{
	L2_BACKGROUND,
	L2_FLOOR,
	L2_ENEMY,
	L2_OBSTACLE1,
	L2_OBSTACLE2,
	L2_OBSTACLE3,
	L2_ANI_OBSTACLE1

};
enum LEVELTEXTURE3
{
	L3_BACKGROUND,
	L3_FLOOR,
	L3_ENEMY,
	L3_OBSTACLE1,
	L3_OBSTACLE2,
	L3_OBSTACLE3,
	L3_ANI_OBSTACLE1

};
enum GIFTTEXTURE
{
	G_JELLY,
	G_MAGNENT,
	G_ENHANCE,
	G_COIN,
	G_BOOST,
	G_FLIGHT,
	G_WEAPON,
	G_BOOM
};


const int L1_COIN_MIN = 0;
const int L2_COIN_MIN = 15;
const int L3_COIN_MIN = 20;


enum FEEDBACK
{
	F_TRYAGAIN,
	F_GOODJOB,
};

//----------------------Animation-------------------

enum AnimationType
{
	ANI_COIN,
	ANI_COOKIEBRAVE_RUN,
	ANI_COOKIEBRIGHT_RUN,
	ANI_COOKIEBRAVE_SLIDE,
	ANI_COOKIEBRAVE_JUMP,
	ANI_COOKIBRAVE_DIE,
	ANI_COOKIEBRIGHT_SLIDE,
	ANI_COOKIEBRIGHT_JUMP,
	ANI_COOKIEBRIGHT_DIE,
	ANI_DEVIL_COOKIE,
	ANI_COOKIEBRAVE_FLY,
	ANI_COOKIEBRIGHT_FLY,
	ANI_CARROT_COOKIE,
	ANI_ZOMBIE_COOKIE,
	ANI_BOOM,
	ANI_OVEN_OBSTCALE1,
	ANI_KITCH_OBSTCALE1,
	ANI_GARDEN_OBSTCALE1,
	ANI_FLAG
};

enum Movement
{
	JUMP,
	DOUBLE_JUMP,
	SLIDE,
	DIE,
	RUN

};

//----------------Direction-----------------------
const int LEFT = -1;
const int RIGHT = 1;
const int START = 0;
const float ENEMY_MOVE_DISTANCE = 1.0f;


//----------------backgrounds---------------------
enum Background
{
	MENU,
	SETTINGS,
	CHOOSE_PLAYER,
	STARTGAME,
	INSTRUCTIONS,
	FLYSTATE
};

const float BACK_X = 20;
const float BACK_Y = 1385;
const sf::Vector2f BACK_SIZE = { 65,65 };


//const int WINDOW_HEIGHT = 950;
//const int WINDOW_WIDTH = 1500;
const float START_X = 750;
const float START_Y = 75;
const float LOAD_X = 550;
const float LOAD_Y = 450;
//const float INSTRUCTIONS_X = 750;
const float INSTRUCTIONS_Y = 1125;
const float SETTINGS_Y = 775;
const float EXIT_X = 65;
const float EXIT_Y = 1385;
//const float SOUND_X = 1385;
//const float SOUND_Y = 42;
const float CHOOSEPLAYER_Y = 425;

const sf::Vector2f BUTTON_SIZE = { 300,100 };
const sf::Vector2f EXIT_SIZE = { 65,65 };

//----------------exceptions----------------------
const float EXCEPTIONS_WID = 650;
const float EXCEPTIONS_HIG = 150;

//-------------------board------------------------
const float BOARD_HIG = 950;
const float BOARD_WID = 1050;
const float BOARD_START_X = 450;
const float BOARD_START_Y = 0;

//-------------------infoBar-----------------------
const float INFO_HIG = 950;
const float INFO_WID = 450;
const float INFO_START_X = 0;
const float INFO_START_Y = 0;

enum Bar
{
	B_TIME,
	B_SAVE,
	B_HOME,
	B_FREE,
	B_PICKEDUP,
	B_LEFT,
	B_SCORE,
	B_HINT
};

const sf::Vector2f INFO_SIZE = { 300,90 };

const float INFO_X = 70;
const float INFO_Y = 50;
const float CLOCK_Y = 120;
const float FREE_Y = 225;
const float PICKEDUP_Y = 330;
const float LEFT_Y = 435;
const float SCORE_Y = 540;
const float SAVE_Y = 750;
const float HINT_Y = 645;
const float I_SOUND_X = 70;
const float I_SOUND_Y = 855;
const float HOME_X = 305;
const float HOME_Y = 855;

// text size
const int INFOBAR_TEXT_SIZE = 30;
const int SCORE_TEXT_SIZE = 80;


//----------------levelLength----------------------
const float LONG_LEVEL = (3 * 60) + 1;
const float SHORT_LEVEL = (1.5 * 60) + 1;


//-------------------sounds------------------------
enum GameSound
{
	G_FREE,
	G_BLOCKED,
};