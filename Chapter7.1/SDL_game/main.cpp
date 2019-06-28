#include <SDL.h>
#include "Game.h"
#include <iostream>
#include <Windows.h>
using namespace std;
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;
Uint32 frameStart, frameTime;



int main(int argc, char *argv[]) 
{
	TheGame::Instance()->
	TheGame::Instance()->init("Chapter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 640, SDL_WINDOW_SHOWN);
	while (TheGame::Instance()->running())
	{
		frameStart = SDL_GetTicks();		
		TheGame::Instance()->handleEvents();
		TheGame::Instance()->update();
		TheGame::Instance()->render();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}
	TheGame::Instance()->clean();
	return 0;
}