#pragma once
#ifndef __GAMEOVERSTATE__
#define __GAMEOVERSTATE__
#include <vector>
#include "GameState.h"
#include "GameObject.h"

class GameOverState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() const { return s_gameOverID; }

private:
	static void s_gameOverToMain();
	static void s_restartPlay();
	static const std::string s_gameOverID;
	vector<GameObject*> m_gameObjects;
};

#endif
