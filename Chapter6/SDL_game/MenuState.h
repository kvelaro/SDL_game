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
private:
	static const string s_menuID;
	vector<GameObject*> m_gameObjects;	
protected:
	typedef void(*Callback)();
	vector<Callback> m_callbacks;
	virtual void setCallbacks(const vector<Callback>& callbacks) = 0;
	vector<string>m_textureIDList;
};

#endif // !__MENUSTATE__


