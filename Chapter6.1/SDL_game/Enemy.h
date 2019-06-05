#pragma once
#include "SDLGameObject.h"
class Enemy : public SDLGameObject
{
public:
	Enemy();
	
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams *pParams);
};

