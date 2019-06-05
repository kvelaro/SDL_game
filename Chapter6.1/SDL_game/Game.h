#pragma once
#ifndef __GAME__
#define __GAME__

#include <SDL.h>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "GameStateMachine.h"

enum game_states
{
	MENU = 0,
	PLAY = 1,
	GAMEOVER = 2
};

class Game
{
public:
	bool init(const char *title, int xpos, int ypos, int height, int width, int flags);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
	void quit();
	
	int m_currentFrame;

	GameObject *m_go;
	GameObject *m_player;
	GameObject *m_enemy;

	vector<GameObject*> m_gameObjects;	

	static Game *Instance() 
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	static Game *s_pInstance;
	GameStateMachine *m_pGameStateMachine;
};

typedef Game TheGame;

#endif // !__GAME__

