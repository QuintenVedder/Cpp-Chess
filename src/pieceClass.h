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

        bool checkEmptyMove(std::vector<int>& move, std::vector<Piece>& pieces, bool canHit = true){
            for(Piece& piece : pieces){
                if(piece.pos == move){
                    if(piece.team != team){
                        if(canHit){
                            hits.push_back(move);
                        }
                    }
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
                int pawnMove = 2;
                if(team == "b"){
                    pos[0] == 1 ? pawnMove = 2 : pawnMove = 1; 
                } else if (team == "w") {
                    pos[0] == 6 ? pawnMove = 2 : pawnMove = 1; 
                }
                for(int i = 1; i <= pawnMove; ++i){
                    if (team == "b") {
                        move = {pos[0] + i, pos[1]};
                    } else if (team == "w") {
                        move = {pos[0] - i, pos[1]};
                    }

                    if (checkEmptyMove(move, pieces, false)) {
                        moves.push_back(move);
                    } else {
                        break;
                    }
                }
                if(team == "b"){
                    move = {pos[0] + 1 , pos[1] + 1};
                    checkEmptyMove(move, pieces);
                    move = {pos[0] + 1 , pos[1] - 1};
                    checkEmptyMove(move, pieces);
                } else if (team == "w") {
                    move = {pos[0] - 1 , pos[1] - 1};
                    checkEmptyMove(move, pieces);
                    move = {pos[0] - 1 , pos[1] + 1};
                    checkEmptyMove(move, pieces);
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
                std::vector<std::vector<int>> tmpMoves;
                tmpMoves.push_back({pos[0] + 2, pos[1] + 1});
                tmpMoves.push_back({pos[0] + 2, pos[1] - 1});
                tmpMoves.push_back({pos[0] - 2, pos[1] + 1});
                tmpMoves.push_back({pos[0] - 2, pos[1] - 1});

                tmpMoves.push_back({pos[0] + 1, pos[1] + 2});
                tmpMoves.push_back({pos[0] + 1, pos[1] - 2});
                tmpMoves.push_back({pos[0] - 1, pos[1] + 2});
                tmpMoves.push_back({pos[0] - 1, pos[1] - 2});

                for(std::vector<int>& tmpMove : tmpMoves){
                    if (checkEmptyMove(tmpMove, pieces)) {
                        moves.push_back(tmpMove);
                    }
                }
            }else if(role == "k"){
                std::vector<std::vector<int>> tmpMoves;
                tmpMoves.push_back({pos[0] + 1, pos[1] + 1});
                tmpMoves.push_back({pos[0] + 1, pos[1] - 1});
                tmpMoves.push_back({pos[0] - 1, pos[1] + 1});
                tmpMoves.push_back({pos[0] - 1, pos[1] - 1});

                tmpMoves.push_back({pos[0] + 1, pos[1]});
                tmpMoves.push_back({pos[0] - 1, pos[1]});
                tmpMoves.push_back({pos[0], pos[1] + 1});
                tmpMoves.push_back({pos[0], pos[1] - 1});

                for(std::vector<int>& tmpMove : tmpMoves){
                    if (checkEmptyMove(tmpMove, pieces)) {
                        moves.push_back(tmpMove);
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