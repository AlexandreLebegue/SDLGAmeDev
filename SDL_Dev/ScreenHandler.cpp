#include "ScreenHandler.h"

ScreenHandler::ScreenHandler(World world, Screen screen) {
	m_world =  world;
	m_screen = screen;
}

ScreenHandler::ScreenHandler(int resolutionX, int resolutionY) {
	SDL_Init(SDL_INIT_VIDEO);
	m_screen = Screen(resolutionY, resolutionX);
	m_world = World();
	Sprite prairie = Sprite(m_prairiePath, m_screen.m_Renderer);
	Sprite eau = Sprite(m_eauPath, m_screen.m_Renderer);
	Sprite foret = Sprite(m_foretPath, m_screen.m_Renderer);
	Sprite plage = Sprite(m_plagePath, m_screen.m_Renderer);
	m_world.generateWorld(6666);
	int w;
	for (int h = 0;  h < MAP_SIZE * SIZE_SPRITE; h += SIZE_SPRITE)
	{
		for (w = 0; w < MAP_SIZE; w++) {
			cout << " w : "<< w <<  ", h : " << h / SIZE_SPRITE <<", " << m_world.m_map[w][h / SIZE_SPRITE].toString ()<<endl;

			int biome = m_world.m_map[w][h / SIZE_SPRITE].m_type;
			switch (biome) {
			case PRAIRIE:
				m_screen.draw(prairie, w * SIZE_SPRITE, h, 1);
				break;
			case EAU:
				m_screen.draw(eau, w * SIZE_SPRITE, h, 1);
				break;
			case FORET:
				m_screen.draw(foret, w * SIZE_SPRITE, h, 1);
				break;
			case PLAGE:
				m_screen.draw(plage, w * SIZE_SPRITE, h, 1);
				break;
			}

		}
	}

}

void ScreenHandler::updateAll() {

	m_screen.display();
}