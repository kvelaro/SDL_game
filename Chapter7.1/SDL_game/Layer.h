#pragma once
#ifndef __LAYER__
#define __LAYER__

class Layer
{
public:
	virtual void render() = 0;
	virtual void update() = 0;

protected:
	virtual ~Layer();
};


#endif // !__LAYER__
