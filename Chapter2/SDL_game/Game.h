#pragma once
#ifndef __GAME__
#define __GAME__

#include <SDL.h>
#include "TextureManager.h"

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

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;
};

#endif // !__GAME__

