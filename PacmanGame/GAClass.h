#pragma once
#include <iostream>
#include <vector>
#include "Ghosts.h"

class GAClass {
	
	static const int xSize = 28;
	static const int ySize = 33;
public:
	std::vector<std::vector<char>> randomToursPinky;
	std::vector<std::vector<char>> randomToursInky;
	std::vector<std::vector<char>> randomToursClyde;
	std::vector<std::vector<char>> randomToursBlinky;
	friend class Ghosts;
	friend void GAControler(Labirynth, std::vector<Ghosts>, int, int, char);
	void generateFirstPopulation(std::vector<Ghosts>, int, int, char);
	void selection();
	void PMXCrossover();
	void mutate();

	GAClass();
	~GAClass() {}
protected:
	long colisionMap[ySize][xSize];
};

void GAControler(Labirynth, std::vector<Ghosts>, int, int, char, GAClass&);