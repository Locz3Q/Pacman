#pragma once
#include <SFML/Graphics.hpp>

class AllTexts :
    public sf::Text {
    sf::Font font;
    std::string content;
    int size;
    sf::Color color;
    float x;
    float y;
public:
    AllTexts(sf::Font, std::string, int, sf::Color, float, float);
    ~AllTexts() {}
};
