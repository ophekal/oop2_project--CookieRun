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
#include "PlayerState/BoostState.h"
#include "PlayerState/EnhanceState.h"

class Player : public MovingObject
{
public:
	Player(const sf::Sprite& sprite, float speed, const sf::Vector2f& position);
	~Player() override = default;
	void setPlayer(Players playerType);
	int getCoins()const;
	int getWeapons()const;
	int getjelly()const;
	void setCoins(int numOfCoins);
	void setJelly(int numOfJelly);

	//--------------------------------------------
	//void setSpeed(float speed);
	void startBoostTimer(sf::Time duration, float oldSpeed);
	//void update(sf::Time deltaTime); // New update method to manage timers

	//----------------------------------------------


	void setWeapon(int numOfWeapon);
	bool onGround()const;
	void handleExitFromLevel();
	bool isDead()const;

	//void run(float deltaTime);
	//void handleCollision();
	//void updateAnimation(sf::Time deltaTime);
	//void updateAnimation(sf::Time deltaTime, Movement movement);
	void movement(sf::Time deltaTime);
	//KeyboardInput getKeyboardInput() const;
	void move(float deltaTime);
	void move(const sf::Vector2f& position) { m_object.move(position); }
	void keyPressed(sf::Event::KeyEvent key);
	void keyReleased(sf::Event::KeyEvent key);
	void setOnGround(bool onGround);
	void resetGravity() { m_gravity = 0; }
	void updateGravity(float movement);
	float getGravity()const { return m_gravity; }
	void setGravity(float gravity) { m_gravity = gravity; }
	int getEnergy()const { return m_energy; }
	void setEnergy(int energy) { m_energy = energy; }
	bool isEnhance()const { return m_isEnhance; }
	void startEnhanceTimer(sf::Time duration, float scaleFactor);
	void checkGiftDurations(float deltaTime);
	void changeToFlyState();
	void changeToBoostState();
	void changeToEnhanceState();
	void changeEnhanceBack();
	const sf::Clock& getGiftClock()const { return m_giftClock; }

private:
	int m_coins = 0;
	int m_weapons = 0;
	int m_jelly = 0;
	int m_energy = 100;
	bool m_onGround = true;

	// gift variables
	bool m_isBoosted = false;
	bool m_isEnhance = false;

	sf::Clock m_giftClock;
	
	sf::Time m_boostDuration;
	sf::Time m_enhanceDuration;
	float m_oldSpeed= 350.f;
	float m_originalScale = 1.0f; 


	Players m_playerType = PLAYER_BRAVE;
	KeyboardInput m_keyPressed = K_NONE;

	//-------------states-----------------------
	JumpState m_jump;
	SlideState m_slide;
	FlyState m_fly;
	//BoostState m_boost;
	//EnhanceState m_enhance;
	RunState m_run;
	PlayerState* m_currentPlayerState;

	float m_gravity = 0;

};

