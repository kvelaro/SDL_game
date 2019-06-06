#pragma once
#ifndef __MAINMENUSTATE__
#define __MAINMENUSTATE__
#include <iostream>
#include "MenuState.h"
#include "GameObject.h"
class MainMenuState : public MenuState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() const { return s_menuID; }
private:
	virtual void setCallbacks(const std::vector<Callback>&callbacks);
	static void s_menuToPlay();
	static void s_exitFromMenu();
	static const string s_menuID;	
	vector<GameObject*> m_gameObjects;
};
#endif
