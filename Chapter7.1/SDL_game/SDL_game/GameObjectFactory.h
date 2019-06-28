#pragma once
#include <map>
#include "GameObject.h"

class BaseCreator
{
public:
	virtual GameObject *createGameObject() const = 0;
	virtual ~BaseCreator() {}
};

class GameObjectFactory
{
public:
	bool registerType(string typeID, BaseCreator *pCreator);
	GameObject* create(std::string typeID);

	static GameObjectFactory *Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new GameObjectFactory();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	map<string, BaseCreator*> m_creators;
	static GameObjectFactory *s_pInstance;
};

typedef GameObjectFactory TheGameObjectFactory;
