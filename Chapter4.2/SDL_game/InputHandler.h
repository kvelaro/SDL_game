#pragma once
#ifndef __INPUTHANDLER__
#define __INPUTHANDLER__
#include <iostream>
#include <SDL.h>
#include <vector>
#include "Vector2D.h"
using namespace std;

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();

private:
	InputHandler();
	~InputHandler();
	static InputHandler* s_pInstance;

	void onMouseButtonDown(SDL_Event event);
	void onMouseButtonUp(SDL_Event event);
	void onMouseMotion(SDL_Event event);

	vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;

};
typedef InputHandler TheInputHandler;

#endif // !__INPUTHANDLER__
