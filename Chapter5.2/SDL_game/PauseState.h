#pragma once
#ifndef __PAUSESTATE__
#define __PAUSESTATE__
#include <vector>
#include "GameState.h"
#include "GameObject.h"

class PauseState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() const { return s_pauseID; }
	static void s_pauseToMain();
	static void s_resumePlay();
private:
	
	static const string s_pauseID;
	vector<GameObject*> m_gameObjects;
};

#endif