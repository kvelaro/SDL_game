#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
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

	SDLGameObject::update();

}
void Player::clean()
{
}
