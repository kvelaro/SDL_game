#pragma once
#ifndef __GAME__
#define __GAME__

#include <SDL.h>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
	bool init(const char *title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running();
	
	int m_currentFrame;

	GameObject *m_go;
	GameObject *m_player;
	GameObject *m_enemy;

	vector<GameObject*> m_gameObjects;	

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;
};

#endif // !__GAME__

