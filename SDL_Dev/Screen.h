#include "SDL.h"
#include "Sprite.h"

class Screen {

public:
	int m_ScreenWidth, m_ScreenHeight;
	SDL_Window* m_Screen;
	SDL_Renderer* m_Renderer;


	Screen();
	Screen(int width, int height);
	void draw(Sprite& sprite, int x, int y, int size);
	void display();
	void createWindow(int& width, int& height);
	void clearScreen();




};