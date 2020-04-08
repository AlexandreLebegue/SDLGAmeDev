#include <iostream>
#include <string>
#include "ScreenHandler.h"


int main(int argc, char* argv[])
{
	
	ScreenHandler screenHandler = ScreenHandler(640, 640);
	while (1) // Tant que l'on veut que le jeu fonctionne
	{
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) // Nous traitons les événements de la queue
		{
		}
		
		screenHandler.updateAll();

	}

	return 0;
}

/*
void old() {

	SDL_Init(SDL_INIT_VIDEO);

	Screen screen = Screen(1080, 1920);

	const char* filepath = "ressources/nyancat.bmp";

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

			}
			// Traitement de 'ev' (nous allons voir après comment traiter un SDL_Event)
		}


		screen.display();
	}

}*/