#pragma once
#include <SFML/Graphics.hpp>


//------------LevelGenerator----------------
const int NUM_OF_PARTS_PER_LEVEL = 4;
const int POSITION_OF_LAST_FLOOR = 50;
const int ENEMIES_PER_LEVEL = 2;
const int LAST_PART_LEVEL_1 = 3;
const int LAST_PART_LEVEL_2 = 7;
const int LAST_PART_LEVEL_3 = 11;


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
	B_LEVEL_ON,
	B_LEVEL_OFF
};

//----------------ChoosePlayers-------------
const float BRAVE_X = 380;
const float BRIGHT_X = 730;
const float PLAYERS_Y = 300;
const sf::Vector2f PLAYERS_SIZE = { 400,500 };


//---------------Players--------------------
enum Players
{
	CHOOSE_PLAYER_BRAVE,
	CHOOSE_PLAYER_BRIGHT,
	PLAYER_BRAVE,
	PLAYER_BRIGHT
};

const sf::Vector2f PLAYER_INIT_POSITION{ 620,759 };

enum KeyboardInput
{
	K_UP,
	K_DOWN,
	K_ENTER,
	K_NONE
};

const int FULL_ENERGY = 100;


//----------------Setting--------------------
const sf::Vector2f MUSIC_SIZE = { 300,100 };
const float SOUND_X = 600;
const float SOUND_Y = 325;
const float MUSIC_Y = 525;


//-----------------Controller---------------
const int WINDOW_HEIGHT = 950;
const int WINDOW_WIDTH = 1500;

//----------------StartGame------------------
enum LEVELS
{
	LEVEL1,
	LEVEL2,
	LEVEL3
};

const float LEVEL_X = 600;
const float LEVEL_Y = 225;


//-----------------Level---------------------
enum LEVELTEXTURE1
{
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
	L2_FLOOR,
	L2_ENEMY,
	L2_OBSTACLE1,
	L2_OBSTACLE2,
	L2_OBSTACLE3,
	L2_ANI_OBSTACLE1

};
enum LEVELTEXTURE3
{
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
	G_MAGNET,
	G_ENHANCE,
	G_COIN,
	G_BOOST,
	G_FLIGHT,
	G_WEAPON,
	G_BOOM
};

const int JELLY2ENERGY = 3;
const int L1_COIN_MIN = 0;
const int L2_COIN_MIN = 15;
const int L3_COIN_MIN = 20;


enum FEEDBACK
{
	F_TRYAGAIN,
	F_GOODJOB,
};


//--------------Animations-------------------
enum AnimationType
{
	ANI_COIN,
	ANI_COOKIEBRAVE_RUN,
	ANI_COOKIEBRIGHT_RUN,
	ANI_COOKIEBRAVE_SLIDE,
	ANI_COOKIEBRAVE_JUMP,
	ANI_COOKIEBRIGHT_SLIDE,
	ANI_COOKIEBRIGHT_JUMP,
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

//----------------Enemies-------------------------
const int LEFT = -1;
const int RIGHT = 1;
const int START = 0;
const float ENEMY_MOVE_DISTANCE = 1.0f;

//----------------MenuInterface------------------
enum Background
{
	MENU,
	SETTINGS,
	CHOOSE_PLAYER,
	STARTGAME,
	INSTRUCTIONS,
	L1_BACKGROUND,
	L2_BACKGROUND,
	L3_BACKGROUND
};

const float BACK_X = 20;
const float BACK_Y = 1385;
const sf::Vector2f BACK_SIZE = { 65,65 };


const float START_X = 750;
const float START_Y = 75;
const float INSTRUCTIONS_Y = 1125;
const float SETTINGS_Y = 775;
const float EXIT_X = 65;
const float EXIT_Y = 1385;
const float CHOOSEPLAYER_Y = 425;

const sf::Vector2f BUTTON_SIZE = { 300,100 };
const sf::Vector2f EXIT_SIZE = { 65,65 };


//----------------Exceptions----------------------
const float EXCEPTIONS_WID = 650;
const float EXCEPTIONS_HIG = 150;

//-------------------Sounds------------------------
enum GameSound
{
	S_COIN,
	S_COOKIEDEAD,
	S_GOODJOB,
	S_TRYAGAIN,
	S_JELLY,
	S_GIFT,
	S_BOOM
};