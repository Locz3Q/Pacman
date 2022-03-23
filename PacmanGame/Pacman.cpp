#include "Pacman.h"
#include "Labirynth.h"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "EveryPoints.h"
#include <string>
#include "Ghosts.h"
#include <time.h>

using namespace std;


Pacman::Pacman(float p_X, float p_Y) : playerScore(0) {
	pacmanShape.setPosition(p_X, p_Y);
	pacmanShape.setRadius(this->pacmanRadius);
	pacmanShape.setFillColor(Color::Yellow);
	pacmanShape.setOrigin(this->pacmanRadius, this->pacmanRadius);
}

void Pacman::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->pacmanShape, state);
}

void Pacman::pacmanMove(Labirynth &tiles, map<int, EveryPoints> &normalEveryPoints, Pacman &pacman) {
	this->pacmanShape.move(this->speed);
	speed.x = 0;
	speed.y = 0;
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
		this->direction = 'u';
		if (!tiles.isCol(this->pacmanShape.getPosition().x / 24, (this->pacmanShape.getPosition().y + 11) / 24, direction, normalEveryPoints, pacman)) {
			speed.y = -pacmanSpeed;
			//cout << " gora ";
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
		this->direction = 'd';
		if (!tiles.isCol(this->pacmanShape.getPosition().x / 24, (this->pacmanShape.getPosition().y - 11) / 24, direction, normalEveryPoints, pacman)) {
			speed.y = pacmanSpeed;
			//cout << " dol ";
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
		this->direction = 'l';
		if (!tiles.isCol((this->pacmanShape.getPosition().x + 11) / 24, (this->pacmanShape.getPosition().y) / 24, direction, normalEveryPoints, pacman)) {
			speed.x = -pacmanSpeed;
			if (tiles.teleport((this->pacmanShape.getPosition().x + 11) / 24, (this->pacmanShape.getPosition().y) / 24, direction)) {
				pacmanShape.setPosition(648, this->pacmanShape.getPosition().y);
			}
			//cout << " lewo ";
		}
		
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
		this->direction = 'r';
		if (!tiles.isCol((this->pacmanShape.getPosition().x - 11) / 24, (this->pacmanShape.getPosition().y) / 24, direction, normalEveryPoints, pacman)) {
			speed.x = pacmanSpeed;
			if (tiles.teleport((this->pacmanShape.getPosition().x - 11) / 24, (this->pacmanShape.getPosition().y) / 24, direction)) {
				pacmanShape.setPosition(24, this->pacmanShape.getPosition().y);
			}
			//cout << "prawo ";
		}
		
	}
	else {
		if (!tiles.isCol((this->pacmanShape.getPosition().x) / 24, (this->pacmanShape.getPosition().y) / 24, '0', normalEveryPoints, pacman)) {};
		speed.x = 0;
		speed.y = 0;
	}
}

void Pacman::getNormalPoint() {
	this->playerScore += 10;
	this->playerScoreString = to_string(this->playerScore);
	cout << " + "<<this->playerScoreString<<" ";
}