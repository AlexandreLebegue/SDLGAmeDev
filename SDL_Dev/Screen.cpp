#include "Screen.h"
#include <iostream>

Screen::Screen() {
	Screen(1920, 1080);
}

Screen::Screen(int h, int w) {
	m_ScreenHeight = h;
	m_ScreenWidth = w;
	createWindow(m_ScreenHeight, m_ScreenWidth);
}


void Screen::createWindow(int& height, int& width) {

	
	m_Screen = SDL_CreateWindow("SDL DEV", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		SDL_WINDOW_SHOWN);
	
	if (!m_Screen)
		std::cout<< "Erreur de création de la fenêtre: %s\n" << SDL_GetError() <<std::endl;
	
	m_Renderer = SDL_CreateRenderer(m_Screen, -1, SDL_RENDERER_ACCELERATED );
	if(!m_Renderer)
		std::cout << "Erreur de création du renderer: %s\n" << SDL_GetError() << std::endl;
	
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_Renderer);
}

void Screen::draw(Sprite& pSprite, int x, int y, int size) {
	SDL_Rect dest = {x,y,pSprite.m_Sprite->w/size, pSprite.m_Sprite->h / size };
	SDL_RenderCopy(m_Renderer, pSprite.m_CurrentTexture, NULL, &dest); // Copie du sprite grâce au SDL_Renderer
	
}

void Screen::display() {
	SDL_RenderPresent(m_Renderer); // Affichage
}


void Screen::clearScreen() {
	SDL_RenderClear(m_Renderer);
}
