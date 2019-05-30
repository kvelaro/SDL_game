#pragma once
#ifndef __PLAYSTATE__
#define __PLAYSTATE__
#include <vector>
#include "GameState.h"
#include "GameObject.h"
#include "SDLGameObject.h"
class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual string getStateID() const { return s_playID; }
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

private:
	static const string s_playID;
	vector<GameObject*> m_gameObjects;	
};

#endif // !__PLAYSTATE__