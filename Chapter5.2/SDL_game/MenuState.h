#pragma once
#ifndef __MENUSTATE__
#define __MENUSTATE__
#include <vector>
#include "GameState.h"
#include "GameObject.h"
class MenuState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() const { return s_menuID; }
	static void s_menuToPlay();
	static void s_exitFromMenu();
private:
	static const string s_menuID;
	vector<GameObject*> m_gameObjects;
};

#endif // !__MENUSTATE__


