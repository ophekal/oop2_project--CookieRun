#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <string.h>
#include <vector>
#include "Macros.h"
#include <unordered_map>
//#include "Animation.h"

class HandleResources
{
public:
	static HandleResources& instance();

	const sf::Texture* getBackgroundTexture(Background icon);
	//const sf::Texture* getMenuTexture(MenuButton icon);
	//const sf::Texture* getInfoBarTexture(Bar icon);
	const sf::Texture* getFeedbackTexture(FEEDBACK icon);
	const sf::Texture* getButtonTexture(Buttons button);
	const sf::Texture* getPlayerTexture(Players player);


	const sf::Texture* getLevel1Texture(LEVELTEXTURE1 icon);
	const sf::Texture* getLevel2Texture(LEVELTEXTURE2 icon);
	const sf::Texture* getLevel3Texture(LEVELTEXTURE3 icon);
	const sf::Texture* getGiftTexture(GIFTTEXTURE icon);
	//const sf::Texture*
	std::vector <sf::IntRect>& getAnimationData(AnimationType type);

	const sf::Font* getFont();
	//void playSound(GameSound sound);
	//void playMusic();
	//void stopMusic();

private:
	HandleResources();   //update all the resources of the play   
	//void updateObjectVector();
	void updateBackgroundVector();
	void updateButtonTextureVector();
	void updatePlayerTextureVector();
	
	void updateLevel1TextureVector();
	void updateLevel2TextureVector();
	void updateLevel3TextureVector();
	void updateGiftTextureVector();
	
	//void updateInfoBarVector();
	void updateFeedbackVector();
	//void updateBufferSounds();
	//void updateGameSounds();


	void updateAnimationData();
	void updateCoinsAnimation();
	void updateCookieBraveRunAnimation(); 
	void updateCookieBraveSlideAnimation(); 
	void updateCookieBraveJumpAnimation();
	void updateCookieBrightRunAnimation();
	void updateCookieBrightSlideAnimation();
	void updateCookieBrightJumpAnimation();
	void updateCookieBraveDieAnimation();
	void updateCookieBrightDieAnimation();
	void updateDevilCookieAnimation();
	void updateCarrotCookieAnimation();
	void updateZombieCookieAnimation();
	void updateCookieBraveFlyAnimation();
	void updateCookieBrightFlyAnimation();
	void updateBoomAnimation();



	//std::vector<sf::Texture> m_objectsTextures;
	std::vector<sf::Texture> m_backgroundsTextures;
	std::vector<sf::Texture> m_buttonsTextures;
	std::vector<sf::Texture> m_playersTextures;
	
	std::vector<sf::Texture> m_level1Textures;
	std::vector<sf::Texture> m_level2Textures;
	std::vector<sf::Texture> m_level3Textures;
	std::vector<sf::Texture> m_giftTextures;

	std::unordered_map<AnimationType, std::vector<sf::IntRect>> m_animationData;

	//std::vector<sf::Texture> m_infoBarTextures;	//infobar
	std::vector<sf::Texture> m_feedbackTextures;

	sf::Font m_font;
	//sf::Music m_gameMusic;
	//std::vector <sf::SoundBuffer> m_bufferSounds;
	//std::vector <sf::Sound>  m_gameSound;

};