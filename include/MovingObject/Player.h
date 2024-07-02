#pragma once
#include "MovingObject/MovingObject.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Macros.h"
#include <vector>
#include "PlayerState/PlayerState.h"
#include "PlayerState/FlyState.h"
#include "PlayerState/JumpState.h"
#include "PlayerState/SlideState.h"
#include "PlayerState/RunState.h"


class Player : public MovingObject
{
public:
	Player(const sf::Sprite& sprite, float speed, const sf::Vector2f& position);
	~Player() override = default;
	void setPlayer(Players playerType);
	void handleExitFromLevel();

	//--------------getters------------------
	int getCoins()const;
	int getWeapons()const;
	int getjelly()const;
	float getGravity()const { return m_gravity; }
	int getEnergy()const { return m_energy; }
	KeyboardInput getKeyPressed()const { return m_keyPressed; }
	sf::Vector2f getVelocity()const { return m_velocity; }
	const sf::Clock& getGiftClock()const { return m_giftClock; }
	Players getPlayerType()const { return m_playerType; }
	sf::Sprite& getPlayerSpriteForAnimation() { return m_object; }
	bool onGround()const;		// change name to get on ground


	//--------------setters------------------
	void setCoins(int numOfCoins);
	void setJelly(int numOfJelly);
	void setWeapon(int numOfWeapon);
	void setOnGround(bool onGround);
	void setGravity(float gravity) { m_gravity = gravity; }
	void setEnergy(int energy) { m_energy = energy; }
	void setIsFlyState(bool fly) { m_isFlyState = fly; }

	//------------movement-------------------
	void movement(sf::Time deltaTime);
	void move(float deltaTime);
	void move(const sf::Vector2f& position) { m_object.move(position); }

	//-----------keyboard--------------------
	void keyPressed(sf::Event::KeyEvent key);
	void keyReleased(sf::Event::KeyEvent key);
	void resetKeyPress();

	//-------player and gift status-----------
	bool isDead()const;
	bool isEnhance()const { return m_isEnhance; }
	bool isBoost()const { return m_isBoosted; }
	bool isMagnet()const { return m_isMagnet; }
	bool isFlyState()const { return m_isFlyState; }
	void startEnhanceTimer(sf::Time duration, float scaleFactor);
	void startBoostTimer(sf::Time duration, float oldSpeed);
	void startMagnetTimer(sf::Time duration);
	void checkGiftDurations(float deltaTime);
	void changeToFlyState();
	void changeEnhanceBack();

	//--------gravity and velocity------------
	void resetGravity() { m_gravity = 0; }
	void updateGravity(float movement);
	void setVelocityY(float y) { m_velocity.y = y; };
	


private:
	sf::Vector2f m_velocity;
	float m_gravity;
	int m_coins = 0;
	int m_weapons = 0;
	int m_jelly = 0;
	int m_energy = 100;
	bool m_onGround = true;
	Players m_playerType = PLAYER_BRAVE;
	KeyboardInput m_keyPressed = K_NONE;
	std::unique_ptr<PlayerState> m_currentPlayerState;

	// gift variables
	bool m_isBoosted = false;
	bool m_isEnhance = false;
	bool m_isFlyState = false;
	bool m_isMagnet = false;
	sf::Clock m_giftClock;
	sf::Time m_boostDuration = sf::seconds(5);
	sf::Time m_enhanceDuration = sf::seconds(5);
	sf::Time m_magnetDuration = sf::seconds(5);
	float m_oldSpeed= 350.f;
	float m_originalScale = 1.0f;


	void checkInsideWindow();
};

