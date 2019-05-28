#include <SDL.h>
#include "Game.h"

Game *g_pgame = 0;

int main(int argc, char *argv[]) {

	g_pgame = new Game();
	g_pgame->init("Chapter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	while (g_pgame->running())
	{
		g_pgame->handleEvents();
		g_pgame->update();
		g_pgame->render();		
		SDL_Delay(10);
	}
	g_pgame->clean();
	return 0;
}