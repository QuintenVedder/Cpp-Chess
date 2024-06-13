#ifndef PIECECLASS_H
#define PIECECLASS_H

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Piece{
    private:
        std::string role;
        std::string team;
        sf::FloatRect hitbox;
        std::vector<std::vector<int>> moves;
    
    public:
        std::vector<int> pos;
        std::string achronym;

        Piece(const std::vector<int>& pos, const std::string& achronym):pos(pos), achronym(achronym){
            team = achronym.substr(0, 1);
            role = achronym.substr(1, achronym.length()-1);

            std::vector<int> startPos = pos;
            if(role == "p"){
                if(team == "w"){
                }else if(team == "b"){
                    for(int i = 1; i < 3; ++i){
                        moves.push_back({startPos[0]+i, startPos[1]});
                    }
                }
            }
            //add other pieces

        }

        void setHitboxFromTexture(sf::Texture& texture, float x, float y){
            sf::Vector2u textureSize = texture.getSize(); // some bs error when trying to store in signed integer
            hitbox = sf::FloatRect(x, y, textureSize.x, textureSize.y);
        }

        bool mouse2PieceCollision(const sf::RenderWindow& window) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            return hitbox.contains(static_cast<sf::Vector2f>(mousePos));
        }

        std::vector<std::vector<int>> getMoves(){
            return moves;
        }
};

#endif //PIECECLASS_H