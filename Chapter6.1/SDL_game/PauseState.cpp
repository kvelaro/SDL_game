#include "PauseState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "InputHandler.h"

const string PauseState::s_pauseID = "PAUSE";

void PauseState::update()
{
	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PauseState::render()
{
	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PauseState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/resume.png", "resumebutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png", "mainbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* button1 = new MenuButton();
	button1->load(new LoaderParams(200, 100, 200, 80, "mainbutton", 6, s_pauseToMain));
	GameObject* button2 = new MenuButton();
	button2->load(new LoaderParams(200, 300, 200, 80, "resumebutton", 6, s_resumePlay));
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	return true;
}

bool PauseState::onExit()
{
	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
	std::cout << "exiting PauseState\n";
	return true;
}

void PauseState::s_pauseToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}
void PauseState::s_resumePlay()
{
	TheGame::Instance()->getStateMachine()->popState();
}