#include "EveryPoints.h"
#include <vector>

using namespace std;
EveryPoints::EveryPoints(float _X, float _Y) {
	point.setPosition(_X, _Y);
	point.setRadius(this->pointRadius);
	point.setFillColor(sf::Color::Yellow);
	point.setOrigin(-10, -10);
}

EveryPoints::EveryPoints(float _X, float _Y, char _type) {
    point.setPosition(_X, _Y);
    point.setRadius(this->bigPointRadius);
    point.setFillColor(sf::Color::Yellow);
    point.setOrigin(-3, -3);
}

EveryPoints::~EveryPoints() {

}

void EveryPoints::draw(sf::RenderTarget& target, sf::RenderStates state) const {
	target.draw(this->point, state);
}

void generateNormalPoint(Labirynth colision, map<int, EveryPoints> &mapOfNormalEveryPoints) {
    int iterator = 0;
    char type = 'B';
    for (int i = 1; i < 27; i++) {
        for (int j = 1; j < 30; j++) {
            if (colision.findZero(j, i)) {
                if ((i == 1 && j == 3) || (i == 1 && j == 23) || (i == 26 && j == 3) || (i == 26 && j == 23)) {
                    EveryPoints normalPoint(i * 24, j * 24, type);
                    mapOfNormalEveryPoints.insert(make_pair(iterator, normalPoint));
                }
                else {
                    EveryPoints normalPoint(i * 24, j * 24);
                    mapOfNormalEveryPoints.insert(make_pair(iterator, normalPoint));
                }
            }
            iterator++;
        }
    }
}