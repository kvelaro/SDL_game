#pragma once
#ifndef __LEVELPARSER__
#define __LEVELPARSER__
#include "Level.h"
#include "tinyxml.h"

class LevelParser
{
public:
	Level *parseLevel(const char* levelFile);

private:
	void parseTilesets(TiXmlElement *pTilesetElement, vector<Tileset>*pTilesets);
	void parseTileLayer(TiXmlElement *pFileElement, vector<Layer*> *pLayers, const vector<Tileset>*pTilesets);

	int m_tileSize;
	int m_width;
	int m_height;
};

#endif // !__LEVELPARSER__
