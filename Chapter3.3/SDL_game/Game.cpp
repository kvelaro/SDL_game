#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char *title, int xpos, int ypos, int height, int width, int flags) 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
		if (m_pWindow != 0) 
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer);

			m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
			m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));


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
	
	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	SDL_RenderPresent(m_pRenderer);	
}
void Game::update() 
{
	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
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