#include <vector>
#include <string>
#include "Biome.h"
#include <time.h>


#ifndef  DEF_WORLD
#define DEF_WORLD

#define MAP_SIZE 10

using namespace std;
	class World {
	public:
		World();
	
		World(int size_x, int size_y);		
		vector<Biome> m_BiomeList;
		void generateWorld(int seed = time(NULL));
		void generateWorldFullRand(int seed = time(NULL));
		string toString();
		Biome m_map[MAP_SIZE][MAP_SIZE];

	private:
		void mapInit();
		void genAffinityTab(Biome biome);
		void resetAffinityTab();
		void setAffinityAround(int x, int y, int value);
		int m_affinityTab[MAP_SIZE][MAP_SIZE];
		bool m_map_defined[MAP_SIZE][MAP_SIZE];
		int m_size_x, m_size_y;

	};

#endif
