#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "piece.h"
#include "utilities.h"

void drawWindow(sf::RenderWindow& window){
    
    drawBoard(window);
    std::vector<std::vector<int>> positions = initPositions(window);
    std::vector<Piece> pieces = initPieces(positions);
    drawPieces(window, pieces);
}

int main()
{
    const int windowWidth = 800;
    const int windowHeight = 800;

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