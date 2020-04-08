#include "World.h"
#include "Reader.h"


int main() {

	World world = World();	
	Reader r;
	r.selectFile("C:/Users/alexa/Documents/biomelist.txt.txt");
	world.m_BiomeList = r.genBiomeList();

	world.generateWorld();
	std::cout << world.toString() <<endl;
	std::cout << "jobs done" << endl;

	

	

	return 0;
}