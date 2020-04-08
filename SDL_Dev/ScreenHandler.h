#include "SDL.h"
#include "Screen.h"
#include "World.h"

#define SIZE_SPRITE 64

class ScreenHandler {

	//const char* filepath = "ressources/nyancat.bmp";
	const char* m_prairiePath = "ressources/prri.bmp";
	const char* m_eauPath = "ressources/eau.bmp";
	const char* m_foretPath = "ressources/foret.bmp";
	const char* m_plagePath = "ressources/plage.bmp";
	
	//const char* filepath = "ressources/nyancat.bmp";

public:
	World m_world;
	Screen m_screen;

	ScreenHandler(World world, Screen screen);
	ScreenHandler(int resolutionX, int resolutionY);
	void updateAll();
	

};