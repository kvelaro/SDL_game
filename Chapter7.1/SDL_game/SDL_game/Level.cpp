#include "Level.h"



Level::Level()
{
}


Level::~Level()
{
}

vector<Tileset>* Level::getTilesets()
{
	return &m_tilesets;
}

vector<Layer*>* Level::getLayers()
{
	return &m_layers;
}

void Level::update() {
	for (unsigned int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->update();
	}
}

void Level::render() {
	for (unsigned int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->render();
	}
}