#include <iostream>
#include <string>
#include "GameObjectFactory.h"
GameObjectFactory *GameObjectFactory::s_pInstance = 0;

GameObject* GameObjectFactory::create(std::string typeID)
{
	std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeID);

	if (it != m_creators.end())
	{
		BaseCreator* pCreator = (*it).second;
		return pCreator->createGameObject();		
	}
	std::cout << "could not find type: " << typeID << "\n";
	return NULL;
	
}


bool GameObjectFactory::registerType(string typeID, BaseCreator *pCreator)
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