class Piece{
    public:
        Piece(const std::vector<int>& position, const std::string& team, const std::string& name) :
            position(position), team(team), name(name) {
                image = "assets/"+team+"/"+name+".png";
        }

        void draw(sf::RenderWindow& window){
            sf::Image pieceImage;
            if (!pieceImage.loadFromFile(image))
            {
            }

            sf::Texture texture;
            texture.loadFromImage(pieceImage);

            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setScale(2,2); //scaling does not change the stored size of the sprite!!
            sprite.setPosition(position[0] - (sprite.getLocalBounds().width), position[1] - (sprite.getLocalBounds().height));

            window.draw(sprite);
        }
    private:
        std::vector<int> position;
        std::string team;
        std::string name;
        std::string image;
};