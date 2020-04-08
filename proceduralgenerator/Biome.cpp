#include "Biome.h"


Biome::Biome() {
	m_type = 0;
}

Biome::Biome(int type) {
	m_type = type;
}

Biome::Biome(string type) {
	if (type == "plag")
		m_type = PLAGE;
	else if (type == "fort")
		m_type = FORET;
	else if (type == "eaux")
		m_type = EAU;
	else if (type == "prri")
		m_type = PRAIRIE;
	else {
		m_type = PRAIRIE;
		cout << "Error reading biome name" << endl;
	}
}


string Biome::toString() {
	switch (m_type) {
		case PLAGE  : return "plag";
		case FORET  : return "fort";
		case EAU    : return "eaux";
		case PRAIRIE: return "prri";
		default		: return "wtf" ;
	}
}


/*
	Check Affinity of the current biome with the param biome 
*/	
int Biome::checkAffinity(Biome biome) {
	return affinity_matrice[biome.m_type][m_type];
}

