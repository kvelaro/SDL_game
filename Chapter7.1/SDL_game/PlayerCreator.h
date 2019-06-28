#pragma once
#include "GameObjectFactory.h"
#include "GameObject.h"
#include "Player.h"

class PlayerCreator : public BaseCreator
{
public:
	GameObject *createGameObject() const
	{
		return new Player();
	}
};

