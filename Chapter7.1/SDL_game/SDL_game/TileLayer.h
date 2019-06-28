#pragma once
#ifndef __TILELAYER__
#define __TILELAYER__

#include <vector>
#include <iostream>
#include "Layer.h"
#include "Level.h"
#include "Vector2D.h"
using namespace std;

class TileLayer : public Layer
{
public:
	TileLayer(int tileSize, const vector<Tileset> &tilesets);
	~TileLayer();

	virtual void update();
	virtual void render();

	void setTileIDs(const vector<vector<int>>&data);
	void setTileSize(int tileSize);
	Tileset getTilesetByID(int tileID);	

private:
	int m_numColumns;
	int m_numRows;
	int m_tileSize;
	Vector2D m_position;
	Vector2D m_velocity;
	const std::vector<Tileset> &m_tilesets;
	vector<vector<int>>m_tileIDs;
};


#endif // !__TILELAYER__


