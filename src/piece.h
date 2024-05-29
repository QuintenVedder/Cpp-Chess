enum class PieceType {
    Rook,
    Knight,
    Bishop,
    Queen,
    King,
    Pawn
};

enum class PieceTeam {
    Black,
    White,
};

class Piece
{
    public:
        Piece(const int positionIndex, const std::vector<int>& position, const PieceTeam& team, const PieceType& name) : positionIndex(positionIndex), position(position), team(team), name(name)
        {
            std::string nameStr;
            std::string teamStr;
            switch (name) {
                case PieceType::Rook:   nameStr = "Rook"; break;
                case PieceType::Knight: nameStr = "Knight"; break;
                case PieceType::Bishop: nameStr = "Bishop"; break;
                case PieceType::Queen:  nameStr = "Queen"; break;
                case PieceType::King:   nameStr = "King"; break;
                case PieceType::Pawn:   nameStr = "Pawn"; break;
            }
            switch (team) {
                case PieceTeam::Black:  teamStr = "Black"; break;
                case PieceTeam::White:  teamStr = "White"; break;
            }
            image = "assets/"+teamStr+"/"+nameStr+".png";
        }

        void draw(sf::RenderWindow& window){
            pieceImage.loadFromFile(image);

            texture.loadFromImage(pieceImage);

            sprite.setTexture(texture);
            sprite.setScale(scale,scale); //scaling does not change the stored size of the sprite!!
            sprite.setPosition(position[0] - (sprite.getLocalBounds().width), position[1] - (sprite.getLocalBounds().height));

            window.draw(sprite);
        }

        bool checkMouseCollision(sf::RenderWindow& window, sf::Vector2f mouse)
        {
            sf::FloatRect bounds = sprite.getGlobalBounds();

            // Convert mouse position to window coordinates
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f mousePositionF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
            if(bounds.contains(mousePositionF))
            {
                std::cout<< true<<std::endl;
                return true;
            }
            else
            {
                // std::cout<< position[0] - (sprite.getLocalBounds().width), (position[0] + sprite.getLocalBounds().width), position[1] - (sprite.getLocalBounds().height), (position[1] + sprite.getLocalBounds().height) > mouse.y;
                // std::cout<< mouse.x , mouse.y;
                return false;
            }
        }
        void showMoves(sf::RenderWindow& window, std::vector<std::vector<int>> positions)
        {
            std::vector<sf::CircleShape> moves;
            for(std::vector position : positions){
                switch (name) {
                case PieceType::Rook:
                //    nameStr = "Rook"; 

                break;
                case PieceType::Knight:
                //  nameStr = "Knight"; 

                break;
                case PieceType::Bishop:
                //  nameStr = "Bishop"; 

                break;
                case PieceType::Queen:
                //   nameStr = "Queen"; 

                break;
                case PieceType::King:
                //    nameStr = "King"; 

                break;
                case PieceType::Pawn:
                    if(team == PieceTeam::White)
                    {
                        for(int i = 0; i>1; i++){
                            sf::CircleShape circle;
                            circle.setRadius(4);
                            circle.setPosition(positions[positionIndex - (8*i)][0], positions[positionIndex - (8*i)][0]);
                            circle.setFillColor(sf::Color::Red);
                            moves.push_back(circle);
                        }
                    }else if(team == PieceTeam::Black)
                    {

                    }                  
                break;
                }
            }
            for(sf::CircleShape move : moves){
                window.draw(move);
            }
        }
    private:
        int positionIndex;
        std::vector<int> position;
        PieceTeam team;
        PieceType name;
        std::string image;
        sf::Sprite sprite;
        int scale = 2;
        sf::Image pieceImage;
        sf::Texture texture;
};