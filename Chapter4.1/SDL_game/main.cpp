#include <SDL.h>
#include "Game.h"

Game *g_pgame = 0;

int main(int argc, char *argv[]) {

	TheGame::Instance()->init("Chapter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	while (TheGame::Instance()->running())
	{
		TheGame::Instance()->handleEvents();
		TheGame::Instance()->update();
		TheGame::Instance()->render();
		SDL_Delay(10);
	}
	TheGame::Instance()->clean();
	return 0;
}