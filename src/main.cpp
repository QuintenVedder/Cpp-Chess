#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "utilities.h"

void gameLoop(sf::RenderWindow& window, std::vector<std::vector<int>>& boardArray, std::vector<Piece>& pieces, std::vector<std::vector<int>>& movesArray, std::vector<int>& clickedPiecePos, bool& turn){
    drawBoard(window, boardArray, pieces, movesArray, clickedPiecePos, turn);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        for(Piece& piece : pieces){
            if(turn && piece.team == "w"){
                if(piece.mouse2PieceCollision(window)){
                    movesArray = piece.getMoves().moves;
                    clickedPiecePos = piece.getMoves().pos;
                }
            }else if(!turn && piece.team == "b"){
                if(piece.mouse2PieceCollision(window)){
                    movesArray = piece.getMoves().moves;
                    clickedPiecePos = piece.getMoves().pos;
                }
            }
        }
    }
}

int main(){
    const int windowWidth = 800;
    const int windowHeight = 800;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Chess");
    window.setSize(sf::Vector2u(windowWidth, windowHeight)); 

    initReturn r = initVars();
    std::vector<std::vector<int>> boardArray = r.boardArray;
    std::vector<Piece> pieces = r.pieces;

    std::vector<std::vector<int>> movesArray;
    std::vector<int> clickedPiecePos;

    bool turn = false;

    while (window.isOpen())
    {
        window.clear(sf::Color::Black);

        gameLoop(window, boardArray, pieces, movesArray, clickedPiecePos, turn);

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