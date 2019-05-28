#pragma once
#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include <iostream>
#include <SDL.h>
using namespace std;

class GameObject 
{
public:
	virtual void load(int x, int y, int width, int height, string textureID);
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean();

protected:
	string m_textureID;

	int m_currentFrame;
	int m_currentRow;

	int m_x;
	int m_y;

	int m_width;
	int m_height;
};

#endif // !__GAMEOBJECT__

