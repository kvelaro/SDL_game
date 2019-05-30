#pragma once
#ifndef __TEXTUREMANAGER__
#define __TEXTUREMANAGER__

#include <iostream>
#include <map>
#include <SDL.h>
using namespace std;
class TextureManager
{
public:
	bool load(string fileName, std::string id, SDL_Renderer* pRenderer);
	void draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void clearFromTextureMap(string id);

	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	TextureManager() {}
	map<string, SDL_Texture *> m_textureMap;
	static TextureManager *s_pInstance;
};

typedef TextureManager TheTextureManager;

#endif // !__TEXTUREMANAGER__
