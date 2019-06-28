#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "StateParser.h"
#include "GameObjectFactory.h"
#include "Player.h"
#include "LevelParser.h"


const string PlayState::s_playID = "PLAY";


void PlayState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}


	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	/*
	if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))	{
		TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
	}
	*/
}

void PlayState::render()
{
	/*
	for (vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	*/
	pLevel->render();
}

bool PlayState::onEnter()
{
	LevelParser levelParser;
	pLevel = levelParser.parseLevel("assets/map1.tmx");
	/*
	TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
	TheGameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());
	StateParser stateParser;
	stateParser.parseState("test.xml", s_playID, &m_gameObjects, &m_textureIDList);
	*/
	std::cout << "entering PlayState\n";
	return true;	
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();
	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();
	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}