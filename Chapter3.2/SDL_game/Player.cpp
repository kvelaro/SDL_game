#include "Player.h"

void Player::load(int x, int y, int width, int height, string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
	std::cout << "draw player";
}


void Player::update()
{
	m_x--;
	
}

void Player::clean() 
{
	GameObject::clean();
	std::cout << "clean player";
}
