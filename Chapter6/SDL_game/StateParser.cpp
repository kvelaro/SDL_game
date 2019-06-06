#include "StateParser.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameObjectFactory.h"

bool StateParser::parseState(const char* stateFile, string stateID, vector<GameObject*>*pObjects, vector<string>*pTextureIDs)
{
	TiXmlDocument xmlDoc;
	if (!xmlDoc.LoadFile(stateFile))
	{
		cerr << xmlDoc.ErrorDesc() << "\n";
		return false;
	}
	TiXmlElement *pRoot = xmlDoc.RootElement();
	TiXmlElement *pStateRoot = 0;
	for (TiXmlElement *e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == stateID)
		{
			pStateRoot = e;
		}
	}
	TiXmlElement *pTextureRoot = 0;
	for (TiXmlElement *e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == string("TEXTURES"))
		{
			pTextureRoot = e;
		}
	}
	parseTextures(pTextureRoot, pTextureIDs);

	TiXmlElement* pObjectRoot = 0;
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == string("OBJECTS"))
		{
			pObjectRoot = e;
		}
	}
	parseObjects(pObjectRoot, pObjects);
	return true;
}

void StateParser::parseObjects(TiXmlElement *pStateRoot, vector<GameObject*>*pObjects)
{
	for (TiXmlElement *e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		int x, y, width, height, numFrames, callbackID, animSpeed;
		string textureID;
		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("width", &width);
		e->Attribute("height", &height);
		e->Attribute("numFrames", &numFrames);
		e->Attribute("callbackID", &callbackID);
		e->Attribute("animSpeed", &animSpeed);
		textureID = e->Attribute("textureID");

		GameObject* pGameObject = TheGameObjectFactory::Instance()->create(e->Attribute("type"));
		pGameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames, callbackID, animSpeed));
		pObjects->push_back(pGameObject);
	}
}

void StateParser::parseTextures(TiXmlElement *pStateRoot, vector<string>*pTextureIDs)
{
	for (TiXmlElement *e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		string filenameAttribute = e->Attribute("filename");
		string idAttribute = e->Attribute("ID");
		pTextureIDs->push_back(idAttribute);
		TheTextureManager::Instance()->load(filenameAttribute, idAttribute, TheGame::Instance()->getRenderer());
	}
}
