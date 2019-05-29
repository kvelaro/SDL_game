#include "PlayState.h"

const string PlayState::s_playID = "PLAY";


void PlayState::update()
{
	// nothing for now
}

void PlayState::render()
{
	// nothing for now
}

bool PlayState::onEnter()
{
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";
	return true;
}