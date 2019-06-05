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
	bool registerType(string typeID, BaseCreator *pCreator)
	{
		map<string, BaseCreator *>::iterator it = m_creators.find(typeID);
		if (it != m_creators.end())
		{
			delete pCreator;
			return false;
		}
		m_creators[typeID] = pCreator;
		return true;
	}

	GameObject *create(string typeID)
	{
		map<string, BaseCreator*>::iterator it = m_creators.find(typeID);
		if (it == m_creators.end())
		{
			cout << "could not find type \n";
			return NULL;
		}
		BaseCreator *pCreator = (*it).second;
		return pCreator->createGameObject();
	}

private:
	map<string, BaseCreator*> m_creators;
};

