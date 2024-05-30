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

class TextureManager {
private:
    static std::unordered_map<std::string, sf::Texture> textures; // Store textures

public:
    static sf::Texture& loadTexture(const std::string& filePath) {
        if (textures.find(filePath) == textures.end()) { // Check if texture already loaded
            sf::Texture texture;
            if (!texture.loadFromFile(filePath)) {
                std::cerr << "Failed to load texture: " << filePath << std::endl;
            } else {
                textures[filePath] = texture; // Store texture
            }
        }
        return textures[filePath]; // Return reference to stored texture
    }
};

std::unordered_map<std::string, sf::Texture> TextureManager::textures; // Initialize static member


class Piece
{
    private:
        int positionIndex;
        std::vector<int> position;
        PieceTeam team;
        PieceType name;
        std::string image;
        sf::Sprite sprite;
        int scale;
        sf::Image pieceImage;
        sf::Texture* texturePtr;
        sf::RectangleShape hitBox;
    public:

        Piece(const int positionIndex, const std::vector<int>& position, const PieceTeam& team, const PieceType& name) : 
            positionIndex(positionIndex), 
            position(position), 
            team(team), 
            name(name), 
            scale(2),
            hitBox(sf::Vector2f(0, 0))
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
            image = "assets/" + teamStr + "/" + nameStr + ".png";
            texturePtr = &TextureManager::loadTexture(image);
            sprite.setTexture(*texturePtr);
            sprite.setScale(scale, scale);
            int xPos = position[0] - sprite.getLocalBounds().width;
            int yPos = position[1] - sprite.getLocalBounds().height;
            sprite.setPosition(xPos, yPos);

            initHitbox(xPos, yPos);
        }

        void draw(sf::RenderWindow& window){
            window.draw(sprite);
            window.draw(hitBox);
        }

        void initHitbox(int& xPos, int& yPos){
            hitBox.setSize(sf::Vector2f(sprite.getLocalBounds().width*scale, sprite.getLocalBounds().height*scale));
            hitBox.setPosition(xPos, yPos);
            hitBox.setFillColor(sf::Color::Transparent); // Set the fill color to transparent
            hitBox.setOutlineThickness(2); // Set the outline thickness
            hitBox.setOutlineColor(sf::Color::Red); // Set the outline color
        }

        bool checkMouseCollision(sf::RenderWindow& window) 
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f mousePos = window.mapPixelToCoords(mousePosition);

            return hitBox.getGlobalBounds().contains(mousePos);
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
                        for(int i = 1; i>3; i++){
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
};