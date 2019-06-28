#include "Player.h"
#include "InputHandler.h"

Player::Player() : SDLGameObject()
{
}

void Player::draw()
{
	SDLGameObject::draw(); 
}
void Player::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
		m_velocity = (*vec - m_position) / 100;

	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}


	SDLGameObject::update();

}
void Player::clean()
{
}

void Player::handleInput() {
	Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;
}

void Player::load(const LoaderParams* pParams)
{
	SDLGameObject::load(pParams);
}