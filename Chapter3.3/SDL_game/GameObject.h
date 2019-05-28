#pragma once
#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include <iostream>
#include <SDL.h>
#include "LoaderParams.h"

using namespace std;

class GameObject 
{
public:
	virtual void draw();
	virtual void update();
	virtual void clean();

protected:
	GameObject(const LoaderParams *pParams) {}
	virtual ~GameObject() {}
};

#endif // !__GAMEOBJECT__

