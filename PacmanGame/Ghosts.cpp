#include "Ghosts.h"
#include "GAClass.h"
#include <thread>
#include <chrono>

int py = 0, iy = 0, by = 0, ce = 0;

Ghosts::Ghosts(float x, float y, string _name) : name(_name) {
	ghostShape.setPosition(x, y);
	ghostShape.setSize(this->ghostSize);
	ghostShape.setOrigin(this->ghostSquare/2, this->ghostSquare/2);
}

void Ghosts::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->ghostShape, state);
}

void countingDown(vector<Ghosts>& ghost) {
	ghost[0].inkyGAgo = true;
	cout << "\nInky\n";

	ghost[1].blinkyGAgo = true;
	cout << "\nBlinky\n";

	ghost[2].pinkyGAgo = true;
	cout << "\nPinky\n";

	ghost[3].clydeGAgo = true;
	cout << "\nClyde\n";
	
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	
		ghost[0].inkyGAgo = true;
		cout << "\nInky";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	
		ghost[1].blinkyGAgo = true;
		cout << "\nBlinky";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		ghost[2].pinkyGAgo = true;
		cout << "\nPinky";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		ghost[3].clydeGAgo = true;
		cout << "\nClyde";
	}
}

void Ghosts::top(Ghosts& g) {
	g.ghostVelocity.y = -g.ghostSpeed;
	//cout << "u";
}

void Ghosts::down(Ghosts& g) {
	g.ghostVelocity.y = g.ghostSpeed;
	//cout << "d";
}

void Ghosts::left(Ghosts& g) {
	g.ghostVelocity.x = -g.ghostSpeed;
	//cout << "l";
}

void Ghosts::right(Ghosts& g) {
	g.ghostVelocity.x = g.ghostSpeed;
	//cout << "r";
}

void spawnGhosts(float x, float y, char type, vector<Ghosts> &vectorOfGhosts) {
	if (type == 'I') {
		Ghosts Inky(x, y, "inky");
		cout << typeid(Inky).name() << endl;
		Inky.ghostShape.setFillColor(sf::Color::Blue);
		vectorOfGhosts.push_back(Inky);
	}
	else if (type == 'B') {
		Ghosts Blinky(x, y, "blinky");
		cout << typeid(Blinky).name() << endl;
		Blinky.ghostShape.setFillColor(sf::Color::Red);
		vectorOfGhosts.push_back(Blinky);
	}
	else if (type == 'P') {
		Ghosts Pinky(x, y, "pinky");
		cout << typeid(Pinky).name() << endl;
		Pinky.ghostShape.setFillColor(sf::Color::Magenta);
		vectorOfGhosts.push_back(Pinky);
	}
	else if (type == 'C') {
		Ghosts Clyde(x, y, "clyde");
		cout << typeid(Clyde).name() << endl;
		Clyde.ghostShape.setFillColor(sf::Color::Green);
		vectorOfGhosts.push_back(Clyde);
	}
}

void Ghosts::moveG(int ghostID, GAClass tour, vector<Ghosts> &ghosts) {
	switch (ghostID) {
	case 0:
		if (tour.randomToursInky[0][ghosts[ghostID].moveNumber] == 'l') {
			left(ghosts[ghostID]);
		}
		else if (tour.randomToursInky[0][ghosts[ghostID].moveNumber] == 'r') {
			right(ghosts[ghostID]);
		}
		else if (tour.randomToursInky[0][ghosts[ghostID].moveNumber] == 'u') {
			top(ghosts[ghostID]);
		}
		else {
			down(ghosts[ghostID]);
		}
		
		break;
	case 1:
		
		if (tour.randomToursBlinky[0][ghosts[ghostID].moveNumber] == 'l') {
			left(ghosts[ghostID]);
		}
		else if (tour.randomToursBlinky[0][ghosts[ghostID].moveNumber] == 'r') {
			right(ghosts[ghostID]);
		}
		else if (tour.randomToursBlinky[0][ghosts[ghostID].moveNumber] == 'u') {
			top(ghosts[ghostID]);
		}
		else {
			down(ghosts[ghostID]);
		}
		
		break;
	case 2:
		
		if (tour.randomToursPinky[0][ghosts[ghostID].moveNumber] == 'l') {
			left(ghosts[ghostID]);
		}
		else if (tour.randomToursPinky[0][ghosts[ghostID].moveNumber] == 'r') {
			right(ghosts[ghostID]);
		}
		else if (tour.randomToursPinky[0][ghosts[ghostID].moveNumber] == 'u') {
			top(ghosts[ghostID]);
		}
		else {
			down(ghosts[ghostID]);
		}
		
		break;
	case 3:
		
		if (tour.randomToursClyde[0][ghosts[ghostID].moveNumber] == 'l') {
			left(ghosts[ghostID]);
		}
		else if (tour.randomToursClyde[0][ghosts[ghostID].moveNumber] == 'r') {
			right(ghosts[ghostID]);
		}
		else if (tour.randomToursClyde[0][ghosts[ghostID].moveNumber] == 'u') {
			top(ghosts[ghostID]);
		}
		else {
			down(ghosts[ghostID]);
		}
		
		break;
	}
}

void Ghosts::pinkyMove(Labirynth& tileMap, vector<Ghosts>& vectorOfGhost, map<int, EveryPoints> p, GAClass &geneticAlg) {		//2
	if (vectorOfGhost[2].pinkyGAgo && py == 0) {
		//cout << "\nPinky GA Start,";
		geneticAlg.randomToursPinky.clear();
		GAControler(tileMap, vectorOfGhost, (vectorOfGhost[2].ghostShape.getPosition().y) / 24, (vectorOfGhost[2].ghostShape.getPosition().x) / 24, 'p', geneticAlg);
		//cout << "Pinky GA End";
		vectorOfGhost[2].pinkyGAgo = false;
		vectorOfGhost[2].moveNumber = 0;
	}
	//tileMap.isCol((vectorOfGhost[2].ghostShape.getPosition().y) / 24, (vectorOfGhost[2].ghostShape.getPosition().x) / 24, 'g', p, vectorOfGhost[2]);
	py++;
	vectorOfGhost[2].ghostShape.move(vectorOfGhost[2].ghostVelocity);
	if (py == 8) {
		vectorOfGhost[2].moveNumber++;
		py = 0;
	}
	cout << " p";
	ghostVelocity.x = 0;
	ghostVelocity.y = 0;
	//cout << "\nPinky move Start, ";
	moveG(2, geneticAlg, vectorOfGhost);
	//cout << "Pinky move End";
}

void Ghosts::inkyMove(Labirynth& tileMap, vector<Ghosts>& vectorOfGhost, map<int, EveryPoints> p, GAClass &geneticAlg) {		//0
	if (vectorOfGhost[0].inkyGAgo && iy == 0) {
		//cout << "\nInky GA Start,";
		geneticAlg.randomToursInky.clear();
		GAControler(tileMap, vectorOfGhost, (vectorOfGhost[0].ghostShape.getPosition().y) / 24, (vectorOfGhost[0].ghostShape.getPosition().x) / 24, 'i', geneticAlg);
		//cout << "Inky GA End";
		vectorOfGhost[0].inkyGAgo = false;
		vectorOfGhost[0].moveNumber = 0;
	}
	iy++;
	vectorOfGhost[0].ghostShape.move(vectorOfGhost[0].ghostVelocity);
	if (iy == 8) {
		vectorOfGhost[0].moveNumber++;
		iy = 0;
	}
	cout << " i";
	ghostVelocity.x = 0;
	ghostVelocity.y = 0;
	//cout << "\nInky move Start, ";
	moveG(0, geneticAlg, vectorOfGhost);
	//cout << "Inky move End";
	
}

void Ghosts::clydeMove(Labirynth& tileMap, vector<Ghosts>& vectorOfGhost, map<int, EveryPoints> p, GAClass &geneticAlg) {		//3
	
	if (vectorOfGhost[3].clydeGAgo && ce == 0) {
		//cout << "\nClyde GA Start,";
		geneticAlg.randomToursClyde.clear();
		GAControler(tileMap, vectorOfGhost, (vectorOfGhost[3].ghostShape.getPosition().y) / 24, (vectorOfGhost[3].ghostShape.getPosition().x) / 24, 'c', geneticAlg);
		//cout << "Clyde GA End";
		vectorOfGhost[3].clydeGAgo = false;
		vectorOfGhost[3].moveNumber = 0;
	}
	ce++;
	vectorOfGhost[3].ghostShape.move(vectorOfGhost[3].ghostVelocity);
	if (ce == 8) {
		vectorOfGhost[3].moveNumber++;
		ce = 0;
	}	
	cout << " c";
	ghostVelocity.x = 0;
	ghostVelocity.y = 0;
	//cout << "\nClyde move Start, ";
	moveG(3, geneticAlg, vectorOfGhost);
	//cout << "Clyde move End";
}

void Ghosts::blinkyMove(Labirynth& tileMap, vector<Ghosts>& vectorOfGhost, map<int, EveryPoints> p, GAClass &geneticAlg) {	//1
	
	if (vectorOfGhost[1].blinkyGAgo && by == 0) {
		//cout << "\nBlinky GA Start,";
		geneticAlg.randomToursBlinky.clear();
		GAControler(tileMap, vectorOfGhost, (vectorOfGhost[1].ghostShape.getPosition().y) / 24, (vectorOfGhost[1].ghostShape.getPosition().x) / 24, 'b', geneticAlg);
		//cout << "Blinky GA End";
		vectorOfGhost[1].blinkyGAgo = false;
		vectorOfGhost[1].moveNumber = 0;
	}
	by++;
	vectorOfGhost[1].ghostShape.move(vectorOfGhost[1].ghostVelocity);
	if (by == 8) {
		vectorOfGhost[1].moveNumber++;
		by = 0;
	}	
	cout << " b";
	ghostVelocity.x = 0;
	ghostVelocity.y = 0;
	//cout << "\nBlinky move Start, ";
	moveG(1, geneticAlg, vectorOfGhost);
	//cout << "Blinky move End";
}

void ghostsMove(Labirynth& tileMap, vector<Ghosts>& vectorOfGhost, map<int, EveryPoints> p, GAClass &geneticAlg) {
	
	vectorOfGhost[0].inkyMove(tileMap, vectorOfGhost, p, geneticAlg);
	vectorOfGhost[1].blinkyMove(tileMap, vectorOfGhost, p, geneticAlg);
	vectorOfGhost[2].pinkyMove(tileMap, vectorOfGhost, p, geneticAlg);
	vectorOfGhost[3].clydeMove(tileMap, vectorOfGhost, p, geneticAlg);
}