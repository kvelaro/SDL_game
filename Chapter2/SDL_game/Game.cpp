#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

bool Game::init(const char *title, int xpos, int ypos, int height, int width, int flags) 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
		if (m_pWindow != 0) 
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer);
			m_bRunning = true;			
			return true;
		}
	}
	return false;
}

void Game::render() 
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(m_pRenderer);
	
	TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);

	SDL_RenderPresent(m_pRenderer);	
}
void Game::update() 
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Game::handleEvents() 
{
	SDL_Event event;
	if (SDL_PollEvent(&event)) 
	{
		switch (event.type) 
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}
void Game::clean() 
{
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
}

bool Game::running() { return m_bRunning; }