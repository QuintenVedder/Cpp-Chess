#ifndef PIECECLASS_H
#define PIECECLASS_H

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "utilities.h"
#include <algorithm>

class Piece{
    private:
        sf::FloatRect hitbox;
        std::vector<std::vector<int>> moves;

        bool checkEmptyMove(std::vector<int>& move, std::vector<Piece>& pieces){
            for(Piece& piece : pieces){
                if(piece.pos == move){
                    if(piece.team != team){
                        hits.push_back(move);
                    }
                    // std::cout << "Piece: " << piece.achronym << ", Piece Position: ";
                    // for (int val : piece.pos) {
                    //     std::cout << val << " ";
                    // }
                    // std::cout << ", Move: ";
                    // for (int val : move) {
                    //     std::cout << val << " ";
                    // }
                    // std::cout << std::endl;
                    return false;
                }
            }
            return true;
        }
    
    public:
        std::string role;
        std::string team;
        std::vector<int> pos;
        std::string achronym;
        std::vector<std::vector<int>> hits;
        bool captured = false;

        Piece(const std::vector<int>& pos, const std::string& achronym):pos(pos), achronym(achronym){
            team = achronym.substr(0, 1);
            role = achronym.substr(1, achronym.length()-1);
        }

        void calcMoves(std::vector<Piece>& pieces){
            moves.clear();
            hits.clear();
            std::vector<int> move;
            if(role == "p"){
                // pawns hit different then they move!!!!!
                // pawns cn only move 2 tiles in their first move
                for(int i = 1; i <= 2; ++i){
                    if (team == "b") {
                        move = {pos[0] + i, pos[1]};
                    } else if (team == "w") {
                        move = {pos[0] - i, pos[1]};
                    }

                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
            }else if(role == "r"){
                for(int i = 1; i <= 7; ++i){
                    move = {pos[0]+i, pos[1]};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
                for(int i = 1; i <= 7; ++i){
                    move = {pos[0], pos[1]+i};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
                for(int i = 1; i <= 7; ++i){
                    move = {pos[0]-i, pos[1]};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
                for(int i = 1; i <= 7; ++i){
                    move = {pos[0], pos[1]-i};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
            }else if(role == "b"){
                for (int i = 1; i <= 7; ++i) {
                    move = {pos[0] + i, pos[1] + i};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
                for (int i = 1; i <= 7; ++i) {
                    move = {pos[0] - i, pos[1] + i};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
                for (int i = 1; i <= 7; ++i) {
                    move = {pos[0] + i, pos[1] - i};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
                for (int i = 1; i <= 7; ++i) {
                    move = {pos[0] - i, pos[1] - i};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
            }else if(role == "kn"){
                moves.push_back({pos[0] + 2, pos[1] + 1});
                moves.push_back({pos[0] + 2, pos[1] - 1});
                moves.push_back({pos[0] - 2, pos[1] + 1});
                moves.push_back({pos[0] - 2, pos[1] - 1});

                moves.push_back({pos[0] + 1, pos[1] + 2});
                moves.push_back({pos[0] + 1, pos[1] - 2});
                moves.push_back({pos[0] - 1, pos[1] + 2});
                moves.push_back({pos[0] - 1, pos[1] - 2});

                for(std::vector<int>& move : moves){
                    if (!checkEmptyMove(move, pieces)) {
                        moves.erase(std::remove(moves.begin(), moves.end(), move), moves.end());
                    }
                }
            }else if(role == "k"){
                moves.push_back({pos[0] + 1, pos[1] + 1});
                moves.push_back({pos[0] + 1, pos[1] - 1});
                moves.push_back({pos[0] - 1, pos[1] + 1});
                moves.push_back({pos[0] - 1, pos[1] - 1});

                moves.push_back({pos[0] + 1, pos[1]});
                moves.push_back({pos[0] - 1, pos[1]});
                moves.push_back({pos[0], pos[1] + 1});
                moves.push_back({pos[0], pos[1] - 1});
                for(std::vector<int>& move : moves){
                    if (!checkEmptyMove(move, pieces)) {
                        moves.erase(std::remove(moves.begin(), moves.end(), move), moves.end());
                    }
                }
            }
            else if(role == "q"){
                for(int i = 1; i <= 7; ++i){
                    move = {pos[0]+i, pos[1]};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
                for(int i = 1; i <= 7; ++i){
                    move = {pos[0], pos[1]+i};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
                for(int i = 1; i <= 7; ++i){
                    move = {pos[0]-i, pos[1]};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
                for(int i = 1; i <= 7; ++i){
                    move = {pos[0], pos[1]-i};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
                
                for (int i = 1; i <= 7; ++i) {
                    move = {pos[0] + i, pos[1] + i};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
                for (int i = 1; i <= 7; ++i) {
                    move = {pos[0] - i, pos[1] + i};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
                for (int i = 1; i <= 7; ++i) {
                    move = {pos[0] + i, pos[1] - i};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
                for (int i = 1; i <= 7; ++i) {
                    move = {pos[0] - i, pos[1] - i};
                    if (checkEmptyMove(move, pieces)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
            }
            moves.erase(std::remove(moves.begin(), moves.end(), pos), moves.end());
        }

        void setHitboxFromTexture(sf::Texture& texture, float x, float y){
            sf::Vector2u textureSize = texture.getSize(); // some bs error when trying to store in signed integer vector
            hitbox = sf::FloatRect(x, y, textureSize.x, textureSize.y);
        }

        bool mouse2PieceCollision(const sf::RenderWindow& window) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            return hitbox.contains(static_cast<sf::Vector2f>(mousePos));
        }

        struct returnMoves{
            std::vector<std::vector<int>> moves;
            std::vector<int> pos;
        };

        returnMoves getMoves(){
            returnMoves r;
            r.moves = moves;
            r.pos = pos;
            return r;
        }
};
#endif //PIECECLASS_H