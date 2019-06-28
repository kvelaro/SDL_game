#pragma once
#ifndef __LEVEL__
#define __LEVEL__
#include <iostream>
#include <vector>
#include "Layer.h"

using namespace std;

struct Tileset
{
	int firstGidID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	string name;
};

class Level
{
public:	
	~Level();

	void update();
	void render();

	vector<Tileset>* getTilesets();
	vector<Layer*>* getLayers();

private:
	vector<Tileset> m_tilesets;
	vector<Layer*> m_layers;
	Level();
	friend class LevelParser;
};


#endif // !__LEVEL__


