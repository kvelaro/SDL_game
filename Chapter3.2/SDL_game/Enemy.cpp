#include "Enemy.h"

void Enemy::load(int x, int y, int width, int height, string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}

void Enemy::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
	std::cout << "draw player";
}


void Enemy::update()
{
	m_y += 1;
	m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));}

void Enemy::clean()
{
	GameObject::clean();
	std::cout << "clean player";
}




