#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "PlayState.h"

const string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	
}

bool MenuState::onEnter()
{
	return true;
}

bool MenuState::onExit()
{
	return true;
}