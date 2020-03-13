#include "SDL.h"
#include <string>
#include <vector>
class Sprite {

public:
	SDL_Surface* m_Sprite;
	SDL_Texture* m_CurrentTexture;
	SDL_Renderer* m_Renderer;
	int m_CurrentTextureIndex;
	std::vector<SDL_Texture*> m_Textures;

	Sprite(const char* filepath, SDL_Renderer* renderer);
	Sprite(SDL_Renderer* renderer);

	void updateTexture();



};