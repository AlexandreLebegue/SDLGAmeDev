#include <string>
#include <iostream>


#ifndef  DEF_BIOME
#define DEF_BIOME

#define PLAGE 3
#define FORET 2
#define EAU 1
#define PRAIRIE 0

const int affinity_matrice[4][4] =
{ { 5,3,1,2 },
  { 3,5,2,1 },
  { 1,2,5,10 },
  { -5,-5,10,5 } };

using namespace std;

class Biome {
public:
	Biome();
	Biome(int type);
	Biome(string type);
	int checkAffinity(Biome biome);
	int m_type;
	string toString();
};

#endif // ! DEF_BIOME