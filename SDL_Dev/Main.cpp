#include <iostream>
#include <string>
#include "Screen.h"

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	Screen screen = Screen(1080, 1920);
	
	const char* filepath = "C:/Users/gigabyte/Documents/Informatique_2018-2019/Git/SDLGameDev/SDL_Dev/x64/Debug/nyancat.bmp";

	Sprite sprite = Sprite(filepath, screen.m_Renderer);
	Sprite sprite2 = Sprite(filepath, screen.m_Renderer);
	screen.draw(sprite, 400, 400, 2);
	
	while (1) // Tant que l'on veut que le jeu fonctionne
	{
		
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) // Nous traitons les événements de la queue
		{
			if (ev.type == SDL_MOUSEMOTION) {
				screen.clearScreen();
				screen.draw(sprite, ev.motion.x, ev.motion.y, 2);
				screen.draw(sprite2, ev.motion.y, ev.motion.x, 2);
				screen.display();
			}
			// Traitement de 'ev' (nous allons voir après comment traiter un SDL_Event)
		}

		

	}
	
	return 0;
}