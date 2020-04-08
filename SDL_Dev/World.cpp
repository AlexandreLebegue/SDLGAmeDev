#include "World.h"
#include <iostream>
#include <stdlib.h>


using namespace std;

#define DEFAULT_SIZE 10;
constexpr auto MAX_PROB = 100;

World::World() {
	m_size_x = MAP_SIZE;
	m_size_y = MAP_SIZE;
	
	mapInit();
}

World::World(int size_x, int size_y){
	m_size_x = size_x;
	m_size_y = size_y;
	mapInit();
}



void World::mapInit() {

	for (int i = 0; i < MAP_SIZE* MAP_SIZE; i += 3) {
		m_BiomeList.push_back(Biome(PRAIRIE));
		m_BiomeList.push_back(Biome(EAU));
		m_BiomeList.push_back(Biome(FORET));
		
	}

	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			m_map[i][j] = Biome(EAU);
		}
	}
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			m_map_defined[i][j] = false;
		}
	}
}


void World::generateWorldFullRand(int seed) {
	cout << "Creating new world ... " << endl;
	int randy = 0;
	int randx = 0;
	bool add = false;
	srand(seed);
	
	for (size_t i = 0; i < m_BiomeList.size(); i++) {
		do {
			randy = rand() % MAP_SIZE ;
			randx = rand() % MAP_SIZE ;
			if (!m_map_defined[randx][randy])
				add = true;
			else
				add = false;
		} while (!add);
		m_map[randx][randy] = m_BiomeList.at(i);
		m_map_defined[randx][randy] = true;
		
	}

};

void World::generateWorld(int seed) {
	cout << "Creating new world ... " << endl;
	
	int wrand = 0;
	bool add = false;
	srand(seed);
	int m_probTab[MAP_SIZE][MAP_SIZE];
	for (size_t f = 0; f < m_BiomeList.size(); f++) {
		genAffinityTab(m_BiomeList.at(f));
		for (int i = 0; i < MAP_SIZE; i++) {
			for (int j = 0; j < MAP_SIZE; j++) {
				wrand = rand() % MAX_PROB + 1;
				m_probTab[i][j] = m_affinityTab[i][j] * wrand;
			}
		}

		int max = INT_MIN;
		int x(0), y(0);
		for (int i = 0; i < MAP_SIZE; i++) {
			for (int j = 0; j < MAP_SIZE; j++) {
				if (m_probTab[i][j] > max) {
					if (!m_map_defined[i][j]) {
						max = m_probTab[i][j];
						x = i;
						y =	j;
					}
				}
			}
		}
		m_map_defined[x][y] = true;
		int  type = m_BiomeList.at(f).m_type;
		m_map[x][y] = Biome(type);

	}
};




void World::genAffinityTab(Biome biome) {
	resetAffinityTab();	
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			int affinity = biome.checkAffinity(m_map[i][j]);
			setAffinityAround(i, j, affinity);
		}
	}
}

void World::setAffinityAround(int x, int y, int value) {
	if (x + 1 < MAP_SIZE) {m_affinityTab[x + 1][y] += value;}
	if (x - 1 > 0) {m_affinityTab[x - 1][y] += value;}
	if (y + 1 < MAP_SIZE) {m_affinityTab[x][y+1] += value;}
	if (y - 1 > 0) {m_affinityTab[x][y-1] += value;}
	if ((y - 1 > 0) && (x - 1 > 0)) { m_affinityTab[x - 1 ][y - 1] += value; }
	if ((y + 1 < MAP_SIZE) && (x + 1 > MAP_SIZE)) { m_affinityTab[x + 1][y + 1] += value; }
	if ((y - 1 > 0) && (x + 1 < MAP_SIZE)) { m_affinityTab[x + 1][y - 1] += value; }
	if ((y + 1 < MAP_SIZE ) && (x - 1 > 0)) { m_affinityTab[x - 1][y + 1] += value; }
}

void World::resetAffinityTab() {
	for (int i = 0; i < m_size_x; i++) {
		for (int j = 0; j < m_size_y; j++) {
			m_affinityTab[i][j] = 1;
		}
	}
}


string World::toString() {
	string returnvalue;
	for (int i = 0; i < m_size_x; i++) {
		for (int j = 0; j < m_size_y; j++) {
			returnvalue += m_map[i][j].toString() + " |";
		}
		returnvalue += "\n";
	}
	return returnvalue;
}