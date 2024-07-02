
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
	updateFeedbackVector();
	updateBufferSounds();
	updateGameSounds();
	m_font.loadFromFile("font.ttf");
	m_gameMusic.openFromFile("gameMusic.wav");
}

//------------------------------------------------------------------------
HandleResources& HandleResources::instance()
{
	static HandleResources inst;
	return inst;
}

//-------------------------------------------------------------------------
void HandleResources::updateBackgroundVector()
{
	m_backgroundsTextures.resize(8);
	m_backgroundsTextures[MENU].loadFromFile("menuBackground.jpg");
	m_backgroundsTextures[SETTINGS].loadFromFile("settingsBackground.jpg");
	m_backgroundsTextures[CHOOSE_PLAYER].loadFromFile("choosePlayerBackground.jpg");
	m_backgroundsTextures[STARTGAME].loadFromFile("startGameBackground.jpg");
	m_backgroundsTextures[INSTRUCTIONS].loadFromFile("instructionsBackground.jpg");
	m_backgroundsTextures[L1_BACKGROUND].loadFromFile("backgroundOven.png");
	m_backgroundsTextures[L2_BACKGROUND].loadFromFile("backgroundKitchen.png");
	m_backgroundsTextures[L3_BACKGROUND].loadFromFile("backgroundGarden.png");
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
	m_buttonsTextures.resize(12);
	m_buttonsTextures[B_EXIT].loadFromFile("exitButton.png");
	m_buttonsTextures[B_START].loadFromFile("startButton.png");
	m_buttonsTextures[B_PLAYER].loadFromFile("playerButton.png");
	m_buttonsTextures[B_INSTRUCTIONS].loadFromFile("instructionsButton.png");
	m_buttonsTextures[B_SETTINGS].loadFromFile("settingsButton.png");
	m_buttonsTextures[B_BACK].loadFromFile("backButton.png");		
	m_buttonsTextures[B_SOUND_ON].loadFromFile("soundOn.png");
	m_buttonsTextures[B_SOUND_OFF].loadFromFile("soundOff.png");
	m_buttonsTextures[B_MUSIC_ON].loadFromFile("musicOn.png");
	m_buttonsTextures[B_MUSIC_OFF].loadFromFile("musicOff.png");
	m_buttonsTextures[B_LEVEL_ON].loadFromFile("levelOn.png");
	m_buttonsTextures[B_LEVEL_OFF].loadFromFile("levelOff.png");
}

//-------------------------------------------------------------------------
void HandleResources::updateLevel1TextureVector()
{
	m_level1Textures.resize(7);
	m_level1Textures[L1_FLOOR].loadFromFile("floor.png");
	m_level1Textures[L1_ENEMY].loadFromFile("devilCookie.png");
	m_level1Textures[L1_OBSTACLE1].loadFromFile("obstacle1.png");
	m_level1Textures[L1_OBSTACLE2].loadFromFile("obstacle2.png");
	m_level1Textures[L1_OBSTACLE3].loadFromFile("obstacle3.png");
	m_level1Textures[L1_ANI_OBSTACLE1].loadFromFile("oven_obstacleAni.png");
	m_level1Textures[L1_FLAG].loadFromFile("flag_Animation.png");
}

//-------------------------------------------------------------------------
void HandleResources::updateLevel2TextureVector()
{
	m_level2Textures.resize(6);
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
	m_level3Textures.resize(6);
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
	m_giftTextures[G_COIN].loadFromFile("Coins-Sheet.png");
	m_giftTextures[G_WEAPON].loadFromFile("Dynamite_Missile.png");
	m_giftTextures[G_MAGNET].loadFromFile("Magnet.png");
	m_giftTextures[G_ENHANCE].loadFromFile("Enhance.png");
	m_giftTextures[G_BOOST].loadFromFile("Boost.png");
	m_giftTextures[G_FLIGHT].loadFromFile("FlyingGift.png");
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

//-------------------------------------------------------------------------
void HandleResources::updateBufferSounds()
{
	m_bufferSounds.resize(7);
	m_bufferSounds[S_COIN].loadFromFile("coins.wav");
	m_bufferSounds[S_COOKIEDEAD].loadFromFile("cookieObstcale.wav");
	m_bufferSounds[S_GOODJOB].loadFromFile("goodJob.wav");
	m_bufferSounds[S_TRYAGAIN].loadFromFile("tryAgain.wav");
	m_bufferSounds[S_JELLY].loadFromFile("cookieJelly.wav");
	m_bufferSounds[S_GIFT].loadFromFile("gift.wav");
	m_bufferSounds[S_BOOM].loadFromFile("explosion.wav");
}

//-------------------------------------------------------------------------
void HandleResources::updateGameSounds()
{
	m_gameSound.resize(7);
	m_gameSound[S_COIN].setBuffer(m_bufferSounds[S_COIN]);
	m_gameSound[S_COOKIEDEAD].setBuffer(m_bufferSounds[S_COOKIEDEAD]);
	m_gameSound[S_GOODJOB].setBuffer(m_bufferSounds[S_GOODJOB]);
	m_gameSound[S_TRYAGAIN].setBuffer(m_bufferSounds[S_TRYAGAIN]);
	m_gameSound[S_JELLY].setBuffer(m_bufferSounds[S_JELLY]);
	m_gameSound[S_GIFT].setBuffer(m_bufferSounds[S_GIFT]);
	m_gameSound[S_BOOM].setBuffer(m_bufferSounds[S_BOOM]);
}

//--------------------------------------------------------------------------
const sf::Texture* HandleResources::getFeedbackTexture(FEEDBACK icon)
{
	return &(m_feedbackTextures[icon]);
}

//-------------------------------------------------------------------------
const sf::Font* HandleResources::getFont()
{
	return &m_font;
}

//-------------------------------------------------------------------------
void HandleResources::playSound(GameSound sound)
{
	if (m_soundOn)
	{
		m_gameSound[sound].setVolume(50);
		m_gameSound[sound].play();
	}
}
//-------------------------------------------------------------------------
void HandleResources::updateSoundOn(bool sound)
{
	m_soundOn = sound;
}

//-------------------------------------------------------------------------
void HandleResources::playMusic()
{
	m_gameMusic.setLoop(true);
	m_gameMusic.play();
}

//--------------------------------------------------------------------------
void HandleResources::stopMusic()
{
	m_gameMusic.pause();
}

//---------------------------------------------------------------------------
// This function calls all the functions that are responsible for updating
// the animations

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
	updateDevilCookieAnimation();
	updateCarrotCookieAnimation();
	updateZombieCookieAnimation();
	updateBoomAnimation();
	updateOven1Animation();
	updateKitchen1Animation();
	updateGardenAnimation();
	updateFlagAnimation();
}

//-----------------------------------------------------------------------------
// This function sends back the vector that contains the animations for the
// appropriate AnimationType

std::vector <sf::IntRect>& HandleResources::getAnimationData(AnimationType type)
{
	return m_animationData[type];
}


//-----------------------------cookie brave-------------------------------
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
	const auto middleSpace = sf::Vector2i(95, 0); 

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
	const auto size = sf::Vector2i(124, 177);
	const auto initSpace = sf::Vector2i(1536, 111);
	const auto middleSpace = sf::Vector2i(177, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_COOKIEBRIGHT_JUMP].emplace_back(currentStart, size);
	m_animationData[ANI_COOKIEBRIGHT_JUMP].emplace_back(nextStart(), size);
	//m_animationData[ANI_COOKIEBRIGHT_JUMP].emplace_back(nextStart(), size);
}

//-----------------------------------------------------------------------
void HandleResources::updateCookieBrightFlyAnimation()
{
	const auto size = sf::Vector2i(145, 169);
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
	const auto size = sf::Vector2i(155, 178);
	const auto initSpace = sf::Vector2i(1679, 1104);
	const auto middleSpace = sf::Vector2i(161, 0);

	auto currentStart = initSpace;

	auto nextStart = [&]()
		{
			currentStart -= middleSpace;
			currentStart.x += size.x;
			return currentStart;
		};


	m_animationData[ANI_ZOMBIE_COOKIE].emplace_back(currentStart, size);
	m_animationData[ANI_ZOMBIE_COOKIE].emplace_back(nextStart(), size);
	m_animationData[ANI_ZOMBIE_COOKIE].emplace_back(nextStart(), size);
	m_animationData[ANI_ZOMBIE_COOKIE].emplace_back(nextStart(), size);
}



//-----------------------gifts and animation objects--------------------------
//-----------------------------------------------------------------------------
void HandleResources::updateCoinsAnimation()
{
	const auto size = sf::Vector2i(59, 59);
	const auto initSpace = sf::Vector2i(0, 0);
	const auto middleSpace = sf::Vector2i(0, 0);

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
	const auto size = sf::Vector2i(114, 111);
	const auto initSpace = sf::Vector2i(4, 5);
	const auto middleSpace = sf::Vector2i(4, 0);

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
	const auto size = sf::Vector2i(49, 99);
	const auto initSpace = sf::Vector2i(0, 0);
	const auto middleSpace = sf::Vector2i(0, 0);

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
	const auto size = sf::Vector2i(129, 150);
	const auto initSpace = sf::Vector2i(0, 9);
	const auto middleSpace = sf::Vector2i(1, 0);

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
	const auto initSpace = sf::Vector2i(3,2);
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