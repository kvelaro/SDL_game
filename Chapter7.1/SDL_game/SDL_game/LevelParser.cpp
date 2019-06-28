#include "LevelParser.h"
#include "Game.h"
#include "TileLayer.h"
#include "base64.h"
#include "zlib.h"
#include "zconf.h"



Level *LevelParser::parseLevel(const char* levelFile)
{
	TiXmlDocument levelDocument;
	levelDocument.LoadFile(levelFile);
	Level* pLevel = new Level();
	TiXmlElement* pRoot = levelDocument.RootElement();
	pRoot->Attribute("tilewidth", &m_tileSize);
	pRoot->Attribute("width", &m_width);
	pRoot->Attribute("height", &m_height);
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == string("tileset"))
		{
			parseTilesets(e, pLevel->getTilesets());
		}
	}

	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("layer"))
		{
			parseTileLayer(e, pLevel->getLayers(), pLevel->getTilesets());
		}
	}
	return pLevel;
}

void LevelParser::parseTilesets(TiXmlElement *pTilesetElement, vector<Tileset>*pTilesets)
{
	string source = pTilesetElement->Attribute("source");
	string tilesetPath = "assets/" + source;
	string tilesetID = "tileset" + (string)pTilesetElement->Attribute("firstgid");
	int firstGID = atoi(pTilesetElement->Attribute("firstgid"));
	
	
	Tileset tileset;
	TiXmlDocument levelDocument;
	levelDocument.LoadFile(tilesetPath);
	TiXmlElement* pTilesetRoot = levelDocument.RootElement();
	pTilesetRoot->FirstChildElement()->Attribute("width", &tileset.width);
	pTilesetRoot->FirstChildElement()->Attribute("height", &tileset.height);
	tileset.firstGidID = firstGID;
	pTilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
	pTilesetRoot->Attribute("tileheight", &tileset.tileHeight);
	pTilesetRoot->Attribute("spacing", &tileset.spacing);
	pTilesetRoot->Attribute("margin", &tileset.margin);
	tileset.name = tilesetID;
	tileset.numColumns = tileset.width / (tileset.tileWidth + tileset.spacing);

	string imageName = pTilesetRoot->FirstChildElement()->Attribute("source");
	string imagePath = "assets/" + imageName;
	TheTextureManager::Instance()->load(imagePath, tilesetID, TheGame::Instance()->getRenderer());

	pTilesets->push_back(tileset);
}

void LevelParser::parseTileLayer(TiXmlElement *pFileElement, vector<Layer*> *pLayers, const vector<Tileset>*pTilesets)
{
	TileLayer* pTileLayer = new TileLayer(m_tileSize, *pTilesets);
	// tile data
	std::vector<std::vector<int>> data;
	std::string decodedIDs;
	TiXmlElement* pDataNode = NULL;
	for (TiXmlElement* e = pFileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("data"))
		{
			pDataNode = e;
		}
	}

	uLongf numGids = m_width * m_height * sizeof(int);
	std::vector<unsigned int> gids(numGids);
	std::vector<int> layerRow(m_width);

	unsigned int i = 0;
	for (TiXmlElement* e = pDataNode->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Attribute("gid") != nullptr)
		{
			gids[i] = atoi(e->Attribute("gid"));
		}
		else
		{
			gids[i] = 0;
		}
		i++;
		
		
		//gids[i++] = (unsigned int)();	
				
		/*
		TiXmlText* text = e->ToText();
		std::string t = text->Value();
		decodedIDs = base64_decode(t);
		*/
	}	
	/*
	uncompress((Bytef*)&gids[0], &numGids, (const Bytef*)decodedIDs.c_str(), decodedIDs.size());
	*/
		

	for (int j = 0; j < m_height; j++)
	{
		data.push_back(layerRow);
	}

	for (int rows = 0; rows < m_height; rows++)
	{
		for (int cols = 0; cols < m_width; cols++)
		{
			data[rows][cols] = gids[rows * m_width + cols];
		}
	}
	pTileLayer->setTileIDs(data);
	pLayers->push_back(pTileLayer);
}
