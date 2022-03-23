#include "AllTexts.h"

AllTexts::AllTexts(sf::Font _font, std::string _content, int _size, sf::Color _color, float _x, float _y) : font(_font), content(_content), size(_size), color(_color), x(_x), y(_y) {
	font.loadFromFile("RobotoCondensed-Regular.ttf");
	this->setFont(this->font);
	this->setString(this->content);
	this->setCharacterSize(this->size);
	this->setFillColor(this->color);
	this->setPosition(this->x, this->y);
}