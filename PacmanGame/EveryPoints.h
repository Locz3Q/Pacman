#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include <vector>

using namespace std;

class Labirynth;
class EveryPoints : public sf::Drawable {
	sf::CircleShape point;
	const float pointRadius{ 2.0 };
	const float bigPointRadius{ 9.0 };
	friend class Pacman;
public:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	EveryPoints(float X, float Y);
	EveryPoints(float X, float Y, char type);
	~EveryPoints();
};

void generateNormalPoint(Labirynth, map<int, EveryPoints>&);