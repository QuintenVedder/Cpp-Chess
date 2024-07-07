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
    
    public:
        std::string role;
        std::string team;
        std::vector<int> pos;
        std::string achronym;

        Piece(const std::vector<int>& pos, const std::string& achronym):pos(pos), achronym(achronym){
            team = achronym.substr(0, 1);
            role = achronym.substr(1, achronym.length()-1);

            calcMoves();
        }

        void calcMoves(){
            moves.clear();
            if(role == "p"){
                for(int i = 0; i < 2; ++i){
                    team == "b" ? moves.push_back({pos[0]+i, pos[1]}) : moves.push_back({pos[0]-i, pos[1]});
                }
            }else if(role == "r"){
                for(int i = 0; i < 8; ++i){
                    moves.push_back({i, pos[1]});
                    moves.push_back({pos[0], i});
                }
            }else if(role == "b"){
                for (int i = 1; i < 8; ++i) {
                    if (pos[0] + i < 8 && pos[1] + i < 8) {
                        moves.push_back({pos[0] + i, pos[1] + i});
                    } if (pos[0] - i >= 0 && pos[1] + i < 8) {
                        moves.push_back({pos[0] - i, pos[1] + i});
                    } if (pos[0] + i < 8 && pos[1] - i >= 0) {
                        moves.push_back({pos[0] + i, pos[1] - i});
                    } if (pos[0] - i >= 0 && pos[1] - i >= 0) {
                        moves.push_back({pos[0] - i, pos[1] - i});
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