#pragma once
#ifndef __PLAYSTATE__
#define __PLAYSTATE__

#include "GameState.h"
class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual string getStateID() const { return s_playID; }

private:
	static const string s_playID;
};

#endif // !__PLAYSTATE__