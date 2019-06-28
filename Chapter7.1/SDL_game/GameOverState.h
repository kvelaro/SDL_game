#pragma once
#ifndef __GAMEOVERSTATE__
#define __GAMEOVERSTATE__
#include <vector>
#include "MenuState.h"
#include "GameObject.h"

class GameOverState : public MenuState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() const { return s_gameOverID; }
	virtual void setCallbacks(const std::vector<Callback>& callbacks);

private:
	static void s_gameOverToMain();
	static void s_restartPlay();
	static const std::string s_gameOverID;
	vector<GameObject*> m_gameObjects;
	vector<Callback> m_callbacks;
	vector<string>m_textureIDList;
};

#endif
