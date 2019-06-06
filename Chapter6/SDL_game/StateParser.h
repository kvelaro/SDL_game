#pragma once
#include <iostream>
#include <vector>
#include "GameObject.h"
#include "tinyxml.h"
using namespace std;

class StateParser
{
public:
	bool parseState(const char* stateFile, string stateID, vector<GameObject*>*pObjects, vector<string>*pTextureIDs);

private:
	void parseObjects(TiXmlElement *pStateRoot, vector<GameObject*>*pObjects);
	void parseTextures(TiXmlElement *pStateRoot, vector<string>*pTextureIDs);
};

