#pragma once
#ifndef __PLAYER__
#define __PLAYER__

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Player : public SDLGameObject
{
public:
	Player();
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* pParams);
	void handleInput();
};

class PlayerCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Player();
	}
};
#endif

