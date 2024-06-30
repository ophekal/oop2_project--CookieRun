
#include "HandleResources.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "Macros.h"


//------------------------------------------------------------------------
HandleResources::HandleResources()
{
	//update all the resources of the game
	updateBackgroundVector();
	updateButtonTextureVector();
	updatePlayerTextureVector();

	updateLevel1TextureVector();
	updateLevel2TextureVector();
	updateLevel3TextureVector();
	updateGiftTextureVector();

	updateAnimationData();

	//updateInfoBarVector();
	updateFeedbackVector();
	//updateBufferSounds();
	//updateGameSounds();
	m_font.loadFromFile("font.ttf");
	//m_gameMusic.openFromFile("gameMusic.wav");
}

//------------------------------------------------------------------------
HandleResources& HandleResources::instance()
{
	static HandleResources inst;
	return inst;
}

////------------------------------------------------------------------------
//void HandleResources::updateObjectVector()
//{
//	m_objectsTextures.resize(12);
//	m_objectsTextures[I_L_CAT].loadFromFile("leftCat.png");
//	m_objectsTextures[I_R_CAT].loadFromFile("rightCat.png");
//	m_objectsTextures[I_L_MOUSE].loadFromFile("leftMouse.png");
//	m_objectsTextures[I_R_MOUSE].loadFromFile("rightMouse.png");
//	m_objectsTextures[I_KEY].loadFromFile("key.png");
//	m_objectsTextures[I_ADDLIFEGIFT].loadFromFile("addLifeGift.png");
//	m_objectsTextures[I_ADDTIMEGIFT].loadFromFile("addTimeGift.png");
//	m_objectsTextures[I_FREEZECATGIFT].loadFromFile("freezeCatGift.png");
//	m_objectsTextures[I_KILLCATGIFT].loadFromFile("killCatGift.png");
//	m_objectsTextures[I_CHEESE].loadFromFile("cheese.png");
//	m_objectsTextures[I_DOOR].loadFromFile("door.png");
//	m_objectsTextures[I_WALL].loadFromFile("wall.png");
//}

//-------------------------------------------------------------------------
void HandleResources::updateBackgroundVector()
{
	m_backgroundsTextures.resize(6);
	m_backgroundsTextures[MENU].loadFromFile("menuBackground.jpg");
	m_backgroundsTextures[SETTINGS].loadFromFile("settingBackground.jpg");
	m_backgroundsTextures[CHOOSE_PLAYER].loadFromFile("choosePlayerBackground.jpg");
	m_backgroundsTextures[STARTGAME].loadFromFile("startGameBackground.jpg");
	m_backgroundsTextures[INSTRUCTIONS].loadFromFile("instructionsBackground.jpg");
	m_backgroundsTextures[FLYSTATE].loadFromFile("flyStateBackground.png");

}

//-------------------------------------------------------------------------
void HandleResources::updatePlayerTextureVector()
{
	m_playersTextures.resize(4);
	m_playersTextures[CHOOSE_PLAYER_BRAVE].loadFromFile("ChoosePlayerGingerBrave.jpg");
	m_playersTextures[CHOOSE_PLAYER_BRIGHT].loadFromFile("ChoosePlayerGingerBright.jpg");
	m_playersTextures[PLAYER_BRAVE].loadFromFile("Cookie_Brave.png");
	m_playersTextures[PLAYER_BRIGHT].loadFromFile("Cookie_Bright.png");

}

//-------------------------------------------------------------------------
void HandleResources::updateButtonTextureVector()
{
	m_buttonsTextures.resize(16);
	m_buttonsTextures[B_EXIT].loadFromFile("exitButton.png");
	m_buttonsTextures[B_START].loadFromFile("startButton.png");
	m_buttonsTextures[B_PLAYER].loadFromFile("playerButton.png");
	m_buttonsTextures[B_INSTRUCTIONS].loadFromFile("instructionsButton.png");
	m_buttonsTextures[B_SETTINGS].loadFromFile("settingsButton.png");
	m_buttonsTextures[B_BACK].loadFromFile("backButton.png");			//to change!!
	m_buttonsTextures[B_SOUND_ON].loadFromFile("soundOn.png");
	m_buttonsTextures[B_SOUND_OFF].loadFromFile("soundOff.png");
	m_buttonsTextures[B_MUSIC_ON].loadFromFile("musicOn.png");
	m_buttonsTextures[B_MUSIC_OFF].loadFromFile("musicOff.png");
	m_buttonsTextures[B_LEVEL1_ON].loadFromFile("level1on.png");
	m_buttonsTextures[B_LEVEL1_OFF].loadFromFile("level1off.png");
	m_buttonsTextures[B_LEVEL2_ON].loadFromFile("level2on.png");
	m_buttonsTextures[B_LEVEL2_OFF].loadFromFile("level2off.png");
	m_buttonsTextures[B_LEVEL3_ON].loadFromFile("level3on.png");
	m_buttonsTextures[B_LEVEL3_OFF].loadFromFile("level3off.png");
}
//-------------------------------------------------------------------------
void HandleResources::updateLevel1TextureVector()
{
	m_level1Textures.resize(8);
	m_level1Textures[L1_BACKGROUND].loadFromFile("backgroundOven.png");
	m_level1Textures[L1_FLOOR].loadFromFile("floor.png");
	m_level1Textures[L1_ENEMY].loadFromFile("devilCookie.png");
	m_level1Textures[L1_OBSTACLE1].loadFromFile("obstacle1.png");
	m_level1Textures[L1_OBSTACLE2].loadFromFile("obstacle2.png");
	m_level1Textures[L1_OBSTACLE3].loadFromFile("obstacle3.png");
	m_level1Textures[L1_ANI_OBSTACLE1].loadFromFile("oven_obstacle1Ani.png");
	m_level1Textures[L1_FLAG].loadFromFile("flag_Animation.png");
}
//-------------------------------------------------------------------------
void HandleResources::updateLevel2TextureVector()
{
	m_level2Textures.resize(7);
	m_level2Textures[L2_BACKGROUND].loadFromFile("backgroundKitchen.png");
	m_level2Textures[L2_FLOOR].loadFromFile("floor2.png");
	m_level2Textures[L2_ENEMY].loadFromFile("carrotCookie.png");
	m_level2Textures[L2_OBSTACLE1].loadFromFile("kitchen_obstcale1.png");
	m_level2Textures[L2_OBSTACLE2].loadFromFile("kitchen_obstcale2.png");
	m_level2Textures[L2_OBSTACLE3].loadFromFile("kitchen_obstcale3.png");
	m_level2Textures[L2_ANI_OBSTACLE1].loadFromFile("kitchen_obstcaleAni.png");
	
}
//------------------------------------------------------------------------
void HandleResources::updateLevel3TextureVector()
{
	m_level3Textures.resize(7);
	m_level3Textures[L3_BACKGROUND].loadFromFile("backgroundGarden.png");
	m_level3Textures[L3_FLOOR].loadFromFile("floor3.png");
	m_level3Textures[L3_ENEMY].loadFromFile("zombieCookie.png");
	m_level3Textures[L3_OBSTACLE1].loadFromFile("garden_obstcale1.png");
	m_level3Textures[L3_OBSTACLE2].loadFromFile("garden_obstcale2.png");
	m_level3Textures[L3_OBSTACLE3].loadFromFile("garden_obstcale3.png");
	m_level3Textures[L3_ANI_OBSTACLE1].loadFromFile("garden_obstcale_ani.png");

}
//------------------------------------------------------------------------
void HandleResources::updateGiftTextureVector()
{
	m_giftTextures.resize(8);
	m_giftTextures[G_JELLY].loadFromFile("JellyBean.png");
	m_giftTextures[G_MAGNET].loadFromFile("Magnet.png");
	m_giftTextures[G_ENHANCE].loadFromFile("Enhance.png");
	m_giftTextures[G_COIN].loadFromFile("Coins-Sheet.png");
	m_giftTextures[G_BOOST].loadFromFile("Boost.png");
	m_giftTextures[G_FLIGHT].loadFromFile("FlyingGift.png");
	m_giftTextures[G_WEAPON].loadFromFile("Dynamite_Missile.png");
	m_giftTextures[G_BOOM].loadFromFile("Effects.png");
}

//-------------------------------------------------------------------------
const sf::Texture* HandleResources::getBackgroundTexture(Background background)
{
	return &(m_backgroundsTextures[background]);
}

//-------------------------------------------------------------------------
const sf::Texture* HandleResources::getButtonTexture(Buttons button)
{
	return &(m_buttonsTextures[button]);
}

//-------------------------------------------------------------------------
const sf::Texture* HandleResources::getPlayerTexture(Players player)
{
	return &(m_playersTextures[player]);
}
//--------------------------------------------------------------------------
const sf::Texture* HandleResources::getLevel1Texture(LEVELTEXTURE1 icon)
{
	return &(m_level1Textures[icon]);
}
//--------------------------------------------------------------------------
const sf::Texture* HandleResources::getLevel2Texture(LEVELTEXTURE2 icon)
{
	return &(m_level2Textures[icon]);
}
//--------------------------------------------------------------------------
const sf::Texture* HandleResources::getLevel3Texture(LEVELTEXTURE3 icon)
{
	return &(m_level3Textures[icon]);
}
//--------------------------------------------------------------------------
const sf::Texture* HandleResources::getGiftTexture(GIFTTEXTURE icon)
{
	return &(m_giftTextures[icon]);
}

//-------------------------------------------------------------------------
void HandleResources::updateFeedbackVector()
{
	m_feedbackTextures.resize(2);
	m_feedbackTextures[F_GOODJOB].loadFromFile("goodJob.png");
	m_feedbackTextures[F_TRYAGAIN].loadFromFile("tryAgain.png");
}

////-------------------------------------------------------------------------
//void HandleResources::updateBufferSounds()
//{
//	m_bufferSounds.resize(6);
//	m_bufferSounds[G_CHEESE].loadFromFile("yummy.wav");
//	m_bufferSounds[G_GIFT].loadFromFile("gift.wav");
//	m_bufferSounds[G_MOUSE].loadFromFile("mouseEaten.wav");
//	m_bufferSounds[G_WIN].loadFromFile("goodJobYouWin.wav");
//	m_bufferSounds[G_LOST].loadFromFile("tryAgainGameOver.wav");
//	m_bufferSounds[G_KEY].loadFromFile("keys.wav");
//}
//
////-------------------------------------------------------------------------
//void HandleResources::updateGameSounds()
//{
//	m_gameSound.resize(6);
//	m_gameSound[G_CHEESE].setBuffer(m_bufferSounds[G_CHEESE]);
//	m_gameSound[G_GIFT].setBuffer(m_bufferSounds[G_GIFT]);
//	m_gameSound[G_MOUSE].setBuffer(m_bufferSounds[G_MOUSE]);
//	m_gameSound[G_WIN].setBuffer(m_bufferSounds[G_WIN]);
//	m_gameSound[G_LOST].setBuffer(m_bufferSounds[G_LOST]);
//	m_gameSound[G_KEY].setBuffer(m_bufferSounds[G_KEY]);
//}
//
////--------------------------------------------------------------------------
//const sf::Texture* HandleResources::getInfoBarTexture(Bar icon)
//{
//	return &(m_infoBarTextures[icon]);
//}
//
//--------------------------------------------------------------------------
const sf::Texture* HandleResources::getFeedbackTexture(FEEDBACK icon)
{
	return &(m_feedbackTextures[icon]);
}

////-------------------------------------------------------------------------
//const sf::Texture* HandleResources::getObjectTexture(IconType icon)
//{
//	return &(m_objectsTextures[icon]);
//}
 
//-------------------------------------------------------------------------
const sf::Font* HandleResources::getFont()
{
	return &m_font;
}

////-------------------------------------------------------------------------
//void HandleResources::playSound(GameSound sound)
//{
//	m_gameSound[sound].setVolume(50);
//	m_gameSound[sound].play();
//}
//
////-------------------------------------------------------------------------
//void HandleResources::playMusic()
//{
//	m_gameMusic.setLoop(true);
//	m_gameMusic.play();
//}
//
////--------------------------------------------------------------------------
//void HandleResources::stopMusic()
//{
//	m_gameMusic.pause();
//}
//---------------------------------------------------------------------------

void HandleResources::updateAnimationData()
{
	updateCoinsAnimation();
	updateCookieBraveRunAnimation();
	updateCookieBraveSlideAnimation();
	updateCookieBraveJumpAnimation();
	updateCookieBraveFlyAnimation();
	updateCookieBrightRunAnimation();
	updateCookieBrightSlideAnimation();
	updateCookieBrightJumpAnimation();
	updateCookieBrightFlyAnimation();
	updateCookieBraveDieAnimation();
	updateCookieBrightDieAnimation();
	updateDevilCookieAnimation();
	updateCarrotCookieAnimation();
	updateZombieCookieAnimation();
	updateBoomAnimation();
	updateOven1Animation();
	updateKitchen1Animation();
	updateGardenAnimation();
	updateFlagAnimation();
}
//--------------------------------------------------------------------------
std::vector <sf::IntRect>& HandleResources::getAnimationData(AnimationType type)
{
	return m_animationData[type];
}
//-----------------------------------------------------------------------------
void HandleResources::updateCoinsAnimation()
{
	const auto size = sf::Vector2i(59, 59);
	const auto initSpace = sf::Vector2i(0, 0);
	const auto middleSpace = sf::Vector2i(0, 0);

	//auto pacman = AnimationData{};
	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};

	
	m_animationData[ANI_COIN].emplace_back(currentStart, size);
	m_animationData[ANI_COIN].emplace_back(nextStart(), size);
	m_animationData[ANI_COIN].emplace_back(nextStart(), size);
	m_animationData[ANI_COIN].emplace_back(nextStart(), size);
	m_animationData[ANI_COIN].emplace_back(nextStart(), size);
	m_animationData[ANI_COIN].emplace_back(nextStart(), size);
}
//------------------------------------------------------------------------
void HandleResources::updateCookieBraveRunAnimation()
{
	const auto size = sf::Vector2i(130,143);
	const auto initSpace = sf::Vector2i(78,400);
	const auto middleSpace = sf::Vector2i(140, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_COOKIEBRAVE_RUN].emplace_back(currentStart, size);
	m_animationData[ANI_COOKIEBRAVE_RUN].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIEBRAVE_RUN].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIEBRAVE_RUN].emplace_back(nextStart(), size);
}

//------------------------------------------------------------------------
void HandleResources::updateCookieBraveSlideAnimation()
{
	const auto size = sf::Vector2i(176, 66);
	const auto initSpace = sf::Vector2i(2493, 201);
	const auto middleSpace = sf::Vector2i(95, 0); //90

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_COOKIEBRAVE_SLIDE].emplace_back(currentStart, size);
	m_animationData[ANI_COOKIEBRAVE_SLIDE].emplace_back(nextStart(), size);
}
//------------------------------------------------------------------------
void HandleResources::updateCookieBraveJumpAnimation()
{
	const auto size = sf::Vector2i(130, 120);
	const auto initSpace = sf::Vector2i(1978, 149);
	const auto middleSpace = sf::Vector2i(144, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_COOKIEBRAVE_JUMP].emplace_back(currentStart, size);
	m_animationData[ANI_COOKIEBRAVE_JUMP].emplace_back(nextStart(), size);
	//m_animationData[ANI_COOKIEBRAVE_JUMP].emplace_back(nextStart(), size);
}

//-----------------------------------------------------------------------
void HandleResources::updateCookieBraveFlyAnimation()
{
	const auto size = sf::Vector2i(125, 170);
	const auto initSpace = sf::Vector2i(1159, 910);
	const auto middleSpace = sf::Vector2i(143, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_COOKIEBRAVE_FLY].emplace_back(currentStart, size);
	m_animationData[ANI_COOKIEBRAVE_FLY].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIEBRAVE_FLY].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIEBRAVE_FLY].emplace_back(nextStart(), size);
}
//------------------------------------------------------------------------
void HandleResources::updateCookieBraveDieAnimation()
{
	const auto size = sf::Vector2i(186, 138);
	const auto initSpace = sf::Vector2i(1423, 1220);
	const auto middleSpace = sf::Vector2i(95, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_COOKIBRAVE_DIE].emplace_back(currentStart, size);
	m_animationData[ANI_COOKIBRAVE_DIE].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIBRAVE_DIE].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIBRAVE_DIE].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIBRAVE_DIE].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIBRAVE_DIE].emplace_back(nextStart(), size);
}

//--------------------------cookie bright---------------------------------
//------------------------------------------------------------------------
void HandleResources::updateCookieBrightRunAnimation()
{
	const auto size = sf::Vector2i(148,143);
	const auto initSpace = sf::Vector2i(60,435);
	const auto middleSpace = sf::Vector2i(138, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_COOKIEBRIGHT_RUN].emplace_back(currentStart, size);
	m_animationData[ANI_COOKIEBRIGHT_RUN].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIEBRIGHT_RUN].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIEBRIGHT_RUN].emplace_back(nextStart(), size);
}

//------------------------------------------------------------------------
void HandleResources::updateCookieBrightSlideAnimation()
{
	const auto size = sf::Vector2i(195, 95);
	const auto initSpace = sf::Vector2i(2647, 195);
	const auto middleSpace = sf::Vector2i(90, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_COOKIEBRIGHT_SLIDE].emplace_back(currentStart, size);
	m_animationData[ANI_COOKIEBRIGHT_SLIDE].emplace_back(nextStart(), size);
}

//------------------------------------------------------------------------
void HandleResources::updateCookieBrightJumpAnimation()
{
	const auto size = sf::Vector2i(142, 152);
	const auto initSpace = sf::Vector2i(1825, 139);
	const auto middleSpace = sf::Vector2i(131, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_COOKIEBRIGHT_JUMP].emplace_back(currentStart, size);
	m_animationData[ANI_COOKIEBRIGHT_JUMP].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIEBRIGHT_JUMP].emplace_back(nextStart(), size);
}



//-----------------------------------------------------------------------
void HandleResources::updateCookieBrightFlyAnimation()
{
	const auto size = sf::Vector2i(145, 163);
	const auto initSpace = sf::Vector2i(78, 978);
	const auto middleSpace = sf::Vector2i(145, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_COOKIEBRIGHT_FLY].emplace_back(currentStart, size);
	m_animationData[ANI_COOKIEBRIGHT_FLY].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIEBRIGHT_FLY].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIEBRIGHT_FLY].emplace_back(nextStart(), size);
}
//------------------------------------------------------------------------
void HandleResources::updateCookieBrightDieAnimation()
{
	const auto size = sf::Vector2i(194, 136);
	const auto initSpace = sf::Vector2i(1535, 1315);
	const auto middleSpace = sf::Vector2i(84, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_COOKIEBRIGHT_DIE].emplace_back(currentStart, size);
	m_animationData[ANI_COOKIEBRIGHT_DIE].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIEBRIGHT_DIE].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIEBRIGHT_DIE].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIEBRIGHT_DIE].emplace_back(nextStart(), size);
	m_animationData[ANI_COOKIEBRIGHT_DIE].emplace_back(nextStart(), size);
}


//------------------------------enemies-----------------------------------
//------------------------------------------------------------------------
void HandleResources::updateDevilCookieAnimation()
{
	const auto size = sf::Vector2i(180, 125);
	const auto initSpace = sf::Vector2i(3398, 593);
	const auto middleSpace = sf::Vector2i(183, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart -= middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_DEVIL_COOKIE].emplace_back(currentStart, size);
	m_animationData[ANI_DEVIL_COOKIE].emplace_back(nextStart(), size);
	m_animationData[ANI_DEVIL_COOKIE].emplace_back(nextStart(), size);
	m_animationData[ANI_DEVIL_COOKIE].emplace_back(nextStart(), size);
}

//------------------------------------------------------------------------
void HandleResources::updateCarrotCookieAnimation()
{
	const auto size = sf::Vector2i(185, 150);
	const auto initSpace = sf::Vector2i(1, 12);
	const auto middleSpace = sf::Vector2i(0, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.y += size.y;
			return currentStart;
		};


	m_animationData[ANI_CARROT_COOKIE].emplace_back(currentStart, size);
	m_animationData[ANI_CARROT_COOKIE].emplace_back(nextStart(), size);
	m_animationData[ANI_CARROT_COOKIE].emplace_back(nextStart(), size);
}


//------------------------------------------------------------------------
void HandleResources::updateZombieCookieAnimation()
{
	const auto size = sf::Vector2i(125, 170);
	const auto initSpace = sf::Vector2i(1828, 115);
	const auto middleSpace = sf::Vector2i(196, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_ZOMBIE_COOKIE].emplace_back(currentStart, size);
	m_animationData[ANI_ZOMBIE_COOKIE].emplace_back(nextStart(), size);
	m_animationData[ANI_ZOMBIE_COOKIE].emplace_back(nextStart(), size);
	m_animationData[ANI_ZOMBIE_COOKIE].emplace_back(nextStart(), size);
}

//----------------------------------------------------------------------------
void HandleResources::updateBoomAnimation()
{
	const auto size = sf::Vector2i(219,219);
	const auto initSpace = sf::Vector2i(7, 1581);
	const auto middleSpace = sf::Vector2i(5, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_BOOM].emplace_back(currentStart, size);
	m_animationData[ANI_BOOM].emplace_back(nextStart(), size);
	m_animationData[ANI_BOOM].emplace_back(nextStart(), size);
}
//---------------------------------------------------------------------------
void HandleResources::updateOven1Animation()
{
	const auto size = sf::Vector2i(252, 226);
	const auto initSpace = sf::Vector2i(0, 0);
	const auto middleSpace = sf::Vector2i(152, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_OVEN_OBSTCALE1].emplace_back(currentStart, size);
	m_animationData[ANI_OVEN_OBSTCALE1].emplace_back(nextStart(), size);
}
//---------------------------------------------------------------------------
void HandleResources::updateKitchen1Animation()
{
	const auto size = sf::Vector2i(117, 244);
	const auto initSpace = sf::Vector2i(1, 620);
	const auto middleSpace = sf::Vector2i(0.5, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_KITCH_OBSTCALE1].emplace_back(currentStart, size);
	m_animationData[ANI_KITCH_OBSTCALE1].emplace_back(nextStart(), size);
	m_animationData[ANI_KITCH_OBSTCALE1].emplace_back(nextStart(), size);
}
//---------------------------------------------------------------------------
void HandleResources::updateGardenAnimation()
{
	const auto size = sf::Vector2i(129,136);
	const auto initSpace = sf::Vector2i(0,0);
	const auto middleSpace = sf::Vector2i(132, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_GARDEN_OBSTCALE1].emplace_back(currentStart, size);
	m_animationData[ANI_GARDEN_OBSTCALE1].emplace_back(nextStart(), size);
	m_animationData[ANI_GARDEN_OBSTCALE1].emplace_back(nextStart(), size);
}
//-----------------------------------------------------------------------------------
void HandleResources::updateFlagAnimation()
{
	const auto size = sf::Vector2i(289, 363);
	const auto initSpace = sf::Vector2i(3,1);
	const auto middleSpace = sf::Vector2i(90, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_FLAG].emplace_back(currentStart, size);
	m_animationData[ANI_FLAG].emplace_back(nextStart(), size);
	m_animationData[ANI_FLAG].emplace_back(nextStart(), size);
}