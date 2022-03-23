#pragma once
using namespace std;
#include "Labirynth.h"
#include "Pacman.h"
#include <SFML/Graphics.hpp>
#include <thread>
class Labirynth;
class Pacman;
class GAClass;

class Ghosts : public sf::Drawable {
	const float ghostSquare{ 48.0 };
	const float ghostSpeed{ 3.0 };
	Vector2f ghostVelocity{ ghostSpeed, ghostSpeed };
	Vector2f ghostSize{ ghostSquare, ghostSquare };
	bool dead = false;
	int lastX = 0, lastY = 0;
	friend class Labirynth;
	friend class Pacman;
	friend void countingDown(vector<Ghosts>&); 
protected:
	string name;
public:
	int moveNumber;
	sf::RectangleShape ghostShape;
	void draw(RenderTarget& target, RenderStates state) const override;
	void pinkyMove(Labirynth&, vector<Ghosts>&, map<int, EveryPoints>, GAClass&);
	bool pinkyGAgo = true;
	void inkyMove(Labirynth&, vector<Ghosts>&, map<int, EveryPoints>, GAClass&);
	bool inkyGAgo = true;
	void clydeMove(Labirynth&, vector<Ghosts>&, map<int, EveryPoints>, GAClass&);
	bool clydeGAgo = true;
	void blinkyMove(Labirynth&, vector<Ghosts>&, map<int, EveryPoints>, GAClass&);
	bool blinkyGAgo = true;
	void getNormalPoint() {}
	void top(Ghosts&);
	void down(Ghosts&);
	void left(Ghosts&);
	void right(Ghosts&);
	void moveG(int, GAClass, vector<Ghosts>&);
	Ghosts() = delete;
	Ghosts(float p_X, float p_Y, string _name);
	~Ghosts() = default;

};

void spawnGhosts(float, float, char, vector<Ghosts>&);

void ghostsMove(Labirynth&, vector<Ghosts>&, map<int, EveryPoints>, GAClass&);

void countingDown(vector<Ghosts>&);