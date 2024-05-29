#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "utilities.h"

void drawWindow(sf::RenderWindow& window){
    //drawboard
    drawBoard(window);
    //draw position dots
    std::vector<std::vector<int>> positions = initPositions(window);
    //....
}

int main()
{
    const unsigned int windowWidth = 800;
    const unsigned int windowHeight = 800;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Chess");
    window.setSize(sf::Vector2u(windowWidth, windowHeight)); 

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        drawWindow(window);

        window.display();
    }

    return 0;
}