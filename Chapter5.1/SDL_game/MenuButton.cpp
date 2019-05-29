#include "MenuButton.h"
#include "InputHandler.h"


MenuButton::MenuButton(const LoaderParams *pParams) : SDLGameObject(pParams)
{
	m_currentFrame = MOUSE_OUT;
}

void MenuButton::draw()
{
	SDLGameObject::draw();
}

void MenuButton::update()
{
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();
	if (pMousePos->getX() < (m_position.getX() + m_width) && pMousePos->getX() > m_position.getX() && pMousePos->getY() < (m_position.getY() + m_height) && pMousePos->getY() > m_position.getY())
	{
		m_currentFrame = MOUSE_OVER;
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_currentFrame = CLICKED;
		}
		else {
			m_currentFrame = MOUSE_OUT;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}

void MenuButton::clean()
{
	SDLGameObject::clean();
}
