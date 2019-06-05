#pragma once
#ifndef __GAMESTATEMACHINE__
#define __GAMESTATEMACHINE__
#include <vector>
#include"GameState.h"

class GameStateMachine
{
public:
	void pushState(GameState *pState);
	void changeState(GameState *pState);
	void popState();
	void update();
	void render();

private:
	vector<GameState *> m_gameStates;
};


#endif // !__GAMESTATEMACHINE__


