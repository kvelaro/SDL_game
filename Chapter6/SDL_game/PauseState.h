#pragma once
#ifndef __PAUSESTATE__
#define __PAUSESTATE__
#include <vector>
#include "MenuState.h"
#include "GameObject.h"

class PauseState : public MenuState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() const { return s_pauseID; }
	static void s_pauseToMain();
	static void s_resumePlay();
	virtual void setCallbacks(const std::vector<Callback>& callbacks);
private:
	
	static const string s_pauseID;
	vector<GameObject*> m_gameObjects;
};

#endif