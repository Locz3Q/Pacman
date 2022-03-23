#pragma once
#include <vector>
#include <iostream>
#include "EveryPoints.h"
#include <Windows.h>
using namespace std;
class Pacman;
class Labirynth {
public:
	friend class EveryPoints;
	friend class GAClass;
	static const int xSize = 28;
	static const int ySize = 33;
	string classPacmanString = "class Pacman";
	string classGhostsString = "class Ghosts";
	Labirynth();
	virtual ~Labirynth() {};
	bool teleport(long x, long y, char d);
	bool findZero(int C_Y, int C_X);
	void showMap(Labirynth);
	long tempCoords[ySize][xSize];
	template<typename T>
	bool isCol(long x, long y, char d, map<int, EveryPoints> &normalEveryPoints, T &who) {
		int sum = (29 * (x - 1)) + y - 1;
		
		if (typeid(who).name() == classGhostsString && this->tileMapCoords[y][x] != 4 && this->tileMapCoords[y][x] != 1) {
			this->tempCoords[y][x] = this->tileMapCoords[y][x];
			this->tileMapCoords[y][x] = 4;
			if (x == who.lastX) {
				this->tileMapCoords[who.lastY][x] = this->tempCoords[y][x];
			}
			
			else if (y == who.lastY) {
				this->tileMapCoords[y][who.lastX] = this->tempCoords[y][x];
			}
			who.lastX = x;
			who.lastY = y;
			return false;
		}

		if ((typeid(who).name() == classPacmanString)
				&& (this->tileMapCoords[y][x] == 4)) {
			who.dead = true;
			sf::Time t = sf::milliseconds(1000);
			sleep(t);
			return false;
		}

		if (typeid(who).name() == classPacmanString) {
			switch (d) {
			case 'u': {
				if (this->tileMapCoords[y - 1][x] == 1) {
					return true;
				}
				else {
					if (this->tileMapCoords[y][x] == 0) {
						this->tileMapCoords[y][x] = 3;
						normalEveryPoints.erase(sum);
						who.getNormalPoint();
					}
					return false;
				}
				break;
			}
			case 'd': {
				if (this->tileMapCoords[y + 1][x] == 1) {
					return true;
				}
				else {
					if (this->tileMapCoords[y][x] == 0) {
						this->tileMapCoords[y][x] = 3;
						normalEveryPoints.erase(sum);
						who.getNormalPoint();
					}
					return false;
				}
				break;
			}
			case 'l': {
				if (this->tileMapCoords[y][x - 1] == 1) {
					return true;
				}
				else {
					if (this->tileMapCoords[y][x] == 0) {
						this->tileMapCoords[y][x] = 3;
						normalEveryPoints.erase(sum);
						who.getNormalPoint();
					}
					return false;
				}
				break;
			}
			case 'r': {
				if (this->tileMapCoords[y][x + 1] == 1) {
					return true;
				}
				else {
					if (this->tileMapCoords[y][x] == 0) {
						this->tileMapCoords[y][x] = 3;
						normalEveryPoints.erase(sum);
						who.getNormalPoint();
					}
					return false;
				}
				break;
			}
			default: return false;
			}
		}
		
	}
protected:
	long tileMapCoords[ySize][xSize];
};

