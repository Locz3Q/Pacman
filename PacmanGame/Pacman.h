#pragma once

#include "Labirynth.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class Labirynth;
class EveryPoints;
class Ghosts;

class Pacman : public Drawable {
	CircleShape pacmanShape;
	const float pacmanRadius{ 24 };
	const float pacmanSpeed{ 3.5 };
	Vector2f speed{ pacmanSpeed, pacmanSpeed };
	void draw(RenderTarget& target, RenderStates state) const override;
	char direction;
	int playerScore;
	int lastX = 0, lastY = 0;
	friend class Labirynth;
public:
	void pacmanMove(Labirynth&, map<int, EveryPoints>&, Pacman&);
	bool dead = false;
	Pacman() = delete;
	Pacman(float p_X, float p_Y);
	~Pacman() = default;
	string playerScoreString;
protected:
	void getNormalPoint();
};

