#pragma once

#ifndef __AnimatedGraphic__
#define __AnimatedGraphic__

#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
	int m_animSpeed;
public:
	AnimatedGraphic();
	void update();
	void draw();
	void clean();
	void load(const LoaderParams* pParams);
};

#endif //defined(__AnimatedGraphic__)