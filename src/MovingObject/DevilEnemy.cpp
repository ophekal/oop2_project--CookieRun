//#include "AnimationObject/DevilEnemy.h"
//
//
////-------------------------------------------------------------------------------------------------------------
//Player::Player(const sf::Sprite& sprite, float speed, const sf::Vector2f& position)
//	:MovingObject(sprite, speed, position),
//	m_doubleJump(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_DOUBLE_JUMP), m_object, sf::seconds(0.1f)),
//	m_jump(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_JUMP), m_object, sf::seconds(0.1f)),
//	m_slide(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_SLIDE), m_object, sf::seconds(0.1f)),
//	//m_fly
//	//m_enhance
//	m_run(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_RUN), m_object, sf::seconds(0.1f), m_slide, m_jump, m_doubleJump),
//	m_currentPlayerState(&m_run)
//{
//	m_doubleJump.setMembers(m_run);
//	m_jump.setMembers(m_run, m_doubleJump);
//	m_slide.setMembers(m_run);
//}
////-------------------------------------------------------------------------------------------------
//int Player::getCoins()const
//{
//	return m_coins;
//}
////------------------------------------------------------------------------------------------------
//int Player::getWeapons()const
//{
//	return m_weapons;
//}
////-----------------------------------------------------------------------------------------------
//int Player::getjelly()const
//{
//	return m_jelly;
//}
////---------------------------------------------------------------------------------------------
//void Player::setCoins(int numOfCoins)
//{
//	m_coins = numOfCoins;
//}
////---------------------------------------------------------------------------------------
//void Player::setJelly(int numOfJelly)
//{
//	m_jelly = numOfJelly;
//}
////---------------------------------------------------------------------------
//void Player::setWeapon(int numOfWeapon)
//{
//	m_weapons = numOfWeapon;
//}
//
////---------------------------------------------------------------------------
//void Player::startBoostTimer(sf::Time duration, float oldSpeed)
//{
//	m_isBoosted = true;
//	m_boostClock.restart();
//	m_boostDuration = duration;
//	m_oldSpeed = oldSpeed;
//}
//
//////---------------------------------------------------------------------------
////// Update method to manage the boost timer
////void Player::update(sf::Time deltaTime)
////{
////	// Check if the player is boosted and the boost duration has expired
////	if (m_isBoosted && m_boostClock.getElapsedTime() >= m_boostDuration)
////	{
////		// Reset the player's speed
////		setSpeed(m_oldSpeed);
////		m_isBoosted = false;
////	}
////}
//
////-----------------------------------------------------------------
//void Player::setPlayer(Players playerType)
//{
//	m_playerType = playerType;
//	sf::Sprite sprite = sf::Sprite(*HandleResources::instance().getPlayerTexture(m_playerType));
//	switch (m_playerType)
//	{
//	case PLAYER_BRAVE:
//	{
//		m_doubleJump.updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_DOUBLE_JUMP), sprite);
//		m_jump.updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_JUMP), sprite);
//		m_slide.updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_SLIDE), sprite);
//		m_run.updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRAVE_RUN), sprite);
//		//m_fly
//		//m_enhance
//
//		break;
//	}
//	case PLAYER_BRIGHT:
//	{
//		m_doubleJump.updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRIGHT_DOUBLE_JUMP), sprite);
//		m_jump.updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRIGHT_JUMP), sprite);
//		m_slide.updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRIGHT_SLIDE), sprite);
//		m_run.updateAnimation(HandleResources::instance().getAnimationData(ANI_COOKIEBRIGHT_RUN), sprite);
//		//m_fly
//		//m_enhance
//
//		break;
//	}
//
//	default:
//		break;
//	}
//}
//////-----------------------------------------------------------------
//void Player::movement(sf::Time deltaTime)
//{
//	m_currentPlayerState = m_currentPlayerState->handleEvent(*this, m_keyPressed);
//	m_currentPlayerState->update(*this, deltaTime);
//
//	m_onGround = false;
//
//}
////-----------------------------------------------------------------------------
//void Player::keyPressed(sf::Event::KeyEvent key)
//{
//	switch (key.code)
//	{
//	case sf::Keyboard::Up:
//	{
//		m_keyPressed = K_UP;
//		break;
//	}
//	case sf::Keyboard::Down:
//	{
//		m_keyPressed = K_DOWN;
//		break;
//	}
//	case sf::Keyboard::Enter:
//	{
//		m_keyPressed = K_ENTER;
//		break;
//	}
//	default:
//	{
//		m_keyPressed = K_NONE;
//		break;
//	}
//
//	}
//}
////-----------------------------------------------------------------------------
//void Player::keyReleased(sf::Event::KeyEvent key)
//{
//	switch (key.code)
//	{
//	case sf::Keyboard::Up:
//	case sf::Keyboard::Down:
//	case sf::Keyboard::Enter:
//		m_keyPressed = K_NONE;
//		break;
//	default:
//		break;
//	}
//}
////--------------------------------------------------------------------------------
//void Player::updateGravity(float movement)
//{
//	m_gravity += movement;
//}
////------------------------------------------------------------------------------
//bool Player::onGround()const
//{
//	return m_onGround;
//}
////-------------------------------------------------------------------------------
//void Player::setOnGround(bool onGround)
//{
//	m_onGround = onGround;
//}
////-------------------------------------------------------------------------------
//void Player::handleExitFromLevel()
//{
//	// for the next level
//	m_currentPlayerState = &m_run;
//	m_object.setPosition({ 620,688 });
//	m_onGround = true;
//	toBeDeleted = true;
//	m_energy = 100;
//	m_jelly = 0;
//	m_weapons = 0;
//}
////--------------------------------------------------------------------------------
//bool Player::isDead()const
//{
//	if (toBeDeleted || m_energy == 0)
//	{
//		return true;
//	}
//	return false;
//}
////-----------------------------------------------------------------------------
//void Player::move(float deltaTime)
//{
//	// Check if the player is boosted and the boost duration has expired
//	if (m_isBoosted && m_boostClock.getElapsedTime() >= m_boostDuration)
//	{
//		// Reset the player's speed
//		this->setObjectSpeed(m_oldSpeed);
//		m_isBoosted = false;
//	}
//
//	m_object.move({ m_objectSpeed * deltaTime, m_gravity }); // was 350 before
//
//	if (m_object.getPosition().y >= PLAYER_INIT_POSITION.y + 2)
//	{
//		SlideState* currState = dynamic_cast<SlideState*>(m_currentPlayerState);
//		if (currState == nullptr)   //if we not in slide state
//		{
//			m_object.setPosition(m_object.getPosition().x, 688);
//		}
//		else if (m_object.getPosition().y >= PLAYER_INIT_POSITION.y + getSize().height)
//		{
//			m_object.setPosition(m_object.getPosition().x, PLAYER_INIT_POSITION.y + getSize().height + 7);
//		}
//
//	}
//
//}
