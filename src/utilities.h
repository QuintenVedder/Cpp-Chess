#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <vector>
#include "pieceClass.h"
#include <string>
#include <SFML/Graphics.hpp>

struct initReturn{
    std::vector<std::vector<int>> boardArray;
    std::vector<Piece> pieces;
};
initReturn initVars(){
    std::vector<std::vector<int>> boardArray(9, std::vector<int>(8));

    int value = 1;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            boardArray[i][j] = ((i+1)+(j+1))%2 == 0? 1 : 0;
        }
    }


    std::vector<Piece> pieces;
    pieces.emplace_back(std::vector<int>{0, 0}, "br");
    pieces.emplace_back(std::vector<int>{0, 1}, "bkn");
    pieces.emplace_back(std::vector<int>{0, 2}, "bb");
    pieces.emplace_back(std::vector<int>{0, 3}, "bq");
    pieces.emplace_back(std::vector<int>{0, 4}, "bk");
    pieces.emplace_back(std::vector<int>{0, 5}, "bb");
    pieces.emplace_back(std::vector<int>{0, 6}, "bkn");
    pieces.emplace_back(std::vector<int>{0, 7}, "br");

    for (int i = 0; i < 8; ++i) {
        pieces.emplace_back(std::vector<int>{1, i}, "bp");
        pieces.emplace_back(std::vector<int>{6, i}, "wp");
    }

    pieces.emplace_back(std::vector<int>{7, 0}, "wr");
    pieces.emplace_back(std::vector<int>{7, 1}, "wkn");
    pieces.emplace_back(std::vector<int>{7, 2}, "wb");
    pieces.emplace_back(std::vector<int>{7, 3}, "wq");
    pieces.emplace_back(std::vector<int>{7, 4}, "wk");
    pieces.emplace_back(std::vector<int>{7, 5}, "wb");
    pieces.emplace_back(std::vector<int>{7, 6}, "wkn");
    pieces.emplace_back(std::vector<int>{7, 7}, "wr");

    initReturn r;
    r.boardArray = boardArray;
    r.pieces = pieces;
    return r;
}

bool Mouse2MoveRectCollision(sf::RenderWindow& window, sf::RectangleShape& moveRect){
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    return moveRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

bool movePiece(std::vector<int>& clickedPiecePos, std::vector<Piece>& pieces, std::vector<int>& move){
    for( Piece& piece : pieces){
        if(piece.pos == clickedPiecePos){
            piece.pos = move;
            piece.calcMoves();
            return true;
        }
    }
    return false;
}

void drawBoard(sf::RenderWindow& window, std::vector<std::vector<int>>& boardArray, std::vector<Piece>& pieces, std::vector<std::vector<int>>& movesArray, std::vector<int>& clickedPiecePos, bool& turn){
    sf::Vector2f size(100, 100);

    for (int row = 0; row < boardArray.size(); ++row) {
            for (int col = 0; col < boardArray[row].size(); ++col) {
            sf::RectangleShape rect;
            rect.setSize(size);
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(2);
            float x = col*100;
            float y = row*100;
            rect.setPosition(x, y);
            rect.setFillColor(boardArray[row][col] == 1? sf::Color(255, 253, 208) : sf::Color(48, 25, 52));
            window.draw(rect);
            for(std::vector<int>& move : movesArray){
                if(move == std::vector<int>{row, col}){
                    sf::RectangleShape moveRect;
                    moveRect.setSize(size);
                    moveRect.setPosition(x, y);
                    moveRect.setFillColor(sf::Color(255, 0, 0, 120));
                    window.draw(moveRect);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        if(Mouse2MoveRectCollision(window, moveRect)){
                            if(movePiece(clickedPiecePos, pieces, move)){
                                movesArray.clear();
                                turn = !turn;
                            }
                        }
                    }
                }
            }
            for( Piece& piece : pieces){
                if(piece.pos == std::vector<int>{row, col}){
                    sf::Texture texture;
                    if(!texture.loadFromFile("assets/" + piece.achronym + ".png")){
                        std::cerr<< "was not able to load image -> " + piece.achronym + ".png"<<std::endl;
                    }

                    sf::Sprite sprite;
                    sprite.setTexture(texture);
                    sprite.setPosition(sf::Vector2f(x, y));

                    piece.setHitboxFromTexture(texture, x, y);

                    window.draw(sprite);
                }
            }
        }
    }
}
#endif //UTILITIES_H