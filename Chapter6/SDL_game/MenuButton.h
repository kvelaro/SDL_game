#pragma once
#ifndef __MENUBUTTON__
#define __MENUBUTTON__

#include "SDLGameObject.h"
#include "GameObjectFactory.h"
class MenuButton : public SDLGameObject
{
public:
	MenuButton();
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* pParams);
	void setCallback(void(*callback)()) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }

private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	bool m_bReleased;
	void(*m_callback)();
	int m_callbackID;
};


class MenuButtonCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new MenuButton();
	}
};

#endif // !__MENUBUTTON__


