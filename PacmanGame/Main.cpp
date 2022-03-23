#include <iostream>
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Pacman.h"
#include "Labirynth.h"
#include "EveryPoints.h"
#include <map>
#include <windows.h>
#include "Ghosts.h"
#include "AllTexts.h"
#include <thread>
#include "GAClass.h"

using namespace std;
using namespace sf;
int main() {
    unsigned int ui;
    srand((unsigned)time(NULL));

    Pacman pacman(334, 560);

    RenderWindow window(VideoMode(672, 792), "Pacman Game");
    
    Texture mainMap;
    Labirynth colision;
    mainMap.loadFromFile("Map.png");
    Sprite set(mainMap);
    set.setScale(3, 3);
    window.setFramerateLimit(60);
    int itt = 0;
    Font font;
    AllTexts scoreString(font, "Wynik: ", 30, sf::Color::White, 0, 748);
    AllTexts valueOfScoreString(font, "", 30, sf::Color::Magenta, 85, 748);
    AllTexts endText(font, "     Koniec!!\n Twoj wynik to: ", 100, sf::Color::Red, 336, 396);
    endText.setOrigin(300, 150);

    typedef map<int, EveryPoints> mapOfPoints;
    mapOfPoints mapOfNormalEveryPoints;

    bool firstTape = true;
    Time t = sf::milliseconds(1000);

    vector<Ghosts> vectorOfGhosts;
    spawnGhosts((12 * 24) + 12, (11 * 24) + 12, 'I', vectorOfGhosts); //Inky
    spawnGhosts((14 * 24) + 12, (11 * 24) + 12, 'B', vectorOfGhosts); //Blinky
    spawnGhosts((10 * 24) + 12, (11 * 24) + 12, 'P', vectorOfGhosts); //Pinky
    spawnGhosts((16 * 24) + 12, (11 * 24) + 12, 'C', vectorOfGhosts); //Clyde
    GAClass geneticAlg;
    thread CountD(countingDown, ref(vectorOfGhosts));
    generateNormalPoint(colision, mapOfNormalEveryPoints);
    Event event;
    while (window.isOpen())
    {
        if (firstTape) {
            for (int i = 5; i > 0; i--) {
                cout << i << "   ";
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
            cout << "START!";
            firstTape = false;
        }
        window.clear(Color::Black);
        window.pollEvent(event);
        if (event.type == Event::Closed) {
            CountD.detach();
            window.close();
            break;
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            while (true) {
                if (Keyboard::isKeyPressed(Keyboard::P)) {
                    break;
                }
            }
        }
        pacman.pacmanMove(colision, mapOfNormalEveryPoints, pacman);
        ghostsMove(colision, vectorOfGhosts, mapOfNormalEveryPoints, geneticAlg);
        window.draw(set);
        for (mapOfPoints::iterator it = mapOfNormalEveryPoints.begin(); it != mapOfNormalEveryPoints.end(); it++) {
            window.draw((it->second));
        }
        valueOfScoreString.setString(pacman.playerScoreString);
        
        window.draw(pacman);
        window.draw(scoreString);
        window.draw(valueOfScoreString);
        for (auto i = vectorOfGhosts.begin(); i != vectorOfGhosts.end(); i++) {
            window.draw(i->ghostShape);
        }
        
        /*if (mapOfNormalEveryPoints.empty() || pacman.dead) {
            while (1) {
                window.pollEvent(event);
                window.clear(Color::Black);
                window.draw(endText);
                if (event.type == Event::Closed) {
                    CountD.detach();
                    window.close();
                    break;
                }
                valueOfScoreString.setString("240");
                valueOfScoreString.setPosition(236, 500);
                valueOfScoreString.setCharacterSize(100);
                window.draw(valueOfScoreString);
                window.display();
            }
        }*/

        window.display();
        

       /* if (CountD.joinable()) {
            thread CountD(countingDown, ref(vectorOfGhosts));
        }*/
        
        //itt++;
        //if (itt == 30) {
        //    itt = 0;
        //    //system("CLS");
        //    colision.showMap(colision);
        //}
    }

    return 0;
}