#include "Enemy.h"

Enemy::Enemy() : SDLGameObject()
{
	
}

void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6/*m_numFrames*/));
	if (m_position.getY() < 0)
	{
		m_velocity.setY(2);
	}
	else if (m_position.getY() > 400)
	{
		m_velocity.setY(-2);
	}
	SDLGameObject::update();
}
void Enemy::clean()
{
}

void Enemy::load(const LoaderParams *pParams)
{
	SDLGameObject::load(pParams);
	m_velocity.setY(2);
	m_velocity.setX(0.001);
}

