void drawBoard(sf::RenderWindow& window){
    sf::Vector2u windowSize = window.getSize();
    sf::Texture texture;

    texture.loadFromFile("assets/Board.png", sf::IntRect(0, 0, windowSize.x, windowSize.y));
    texture.setSmooth(true);

    sf::Sprite sprite;
    sprite.setTexture(texture);

    sprite.setScale(
    windowSize.x / sprite.getLocalBounds().width, 
    windowSize.y / sprite.getLocalBounds().height);

    window.draw(sprite);
}
std::vector<std::vector<int>> initPositions(sf::RenderWindow& window) {
    int startPostition[2] = {80,85};
    int positionDifference[2] = {90,90};
    std::vector<std::vector<int>> positions(64, std::vector<int>(2));

    for(int j=0; j<8; j++){
        for(int i=0; i<8; i++){
            sf::CircleShape circle;
            circle.setRadius(4);
            circle.setPosition((startPostition[0]+(positionDifference[0]*i)), startPostition[1]+(positionDifference[1]*j));
            circle.setFillColor(sf::Color::Red);
            positions[(j*8)+i][0] = circle.getPosition().x;
            positions[(j*8)+i][1] = circle.getPosition().y;
            window.draw(circle);
        }
    }
    return positions;
}