#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <unordered_map> 
#include "piece.h"
#include "utilities.h"

void drawWindow(sf::RenderWindow& window, std::vector<std::vector<int>>& positions, std::vector<Piece>& pieces)
{
    drawBoard(window);
    drawPieces(window, pieces);
}

void interactionLogic(sf::RenderWindow& window, std::vector<std::vector<int>>& positions, std::vector<Piece>& pieces)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // Only check for collision when mouse button is pressed
    {
        for (Piece piece : pieces)
        {
            if (piece.checkMouseCollision(window))
            {
                piece.showMoves(window, positions);
            }
        }
    }
}

int main()
{
    const int windowWidth = 800;
    const int windowHeight = 800;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Chess");
    window.setSize(sf::Vector2u(windowWidth, windowHeight)); 

    window.setFramerateLimit(60);

    std::vector<std::vector<int>> positions = initPositions(window);
    std::vector<Piece> pieces = initPieces(positions);

    while (window.isOpen())
    {
        window.clear(sf::Color::Black);

        drawWindow(window, positions, pieces);

        interactionLogic(window, positions, pieces);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.display();
    }

    return 0;
}