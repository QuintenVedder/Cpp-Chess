void drawBoard(sf::RenderWindow& window)
{
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
std::vector<std::vector<int>> initPositions(sf::RenderWindow& window)
{
    int startPostition[2] = {80,85};
    int positionDifference[2] = {90,90};
    std::vector<std::vector<int>> positions(64, std::vector<int>(2));

    for(int j=0; j<8; j++){
        for(int i=0; i<8; i++){
            positions[(j*8)+i][0] = startPostition[0]+(positionDifference[0]*i);
            positions[(j*8)+i][1] = startPostition[1]+(positionDifference[1]*j);
        }
    }
    return positions;
}
std::vector<Piece> initPieces(const std::vector<std::vector<int>>& positions)
{
    std::vector<Piece> pieces;

    for (int j = 0; j < 8; j++)
{
    for (int i = 0; i < 8; i++)
    {
        if(j == 0)
        {
            switch(i)
            {
                case 0:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::Black, PieceType::Rook));
                break;
                case 1:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::Black, PieceType::Knight));
                break;
                case 2:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::Black, PieceType::Bishop));
                break;
                case 3:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::Black, PieceType::Queen));
                break;
                case 4:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::Black, PieceType::King));
                break;
                case 5:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::Black, PieceType::Bishop));
                break;
                case 6:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::Black, PieceType::Knight));
                break;
                case 7:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::Black, PieceType::Rook));
                break;
                default:
                break;
            }
        }
        else if(j == 1)
        {
            pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::Black, PieceType::Pawn));
        }
        else if(j == 6)
        {
            pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::White, PieceType::Pawn));
        }
        if(j == 7)
        {
            switch(i)
            {
                case 0:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::White, PieceType::Rook));
                break;
                case 1:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::White, PieceType::Knight));
                break;
                case 2:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::White, PieceType::Bishop));
                break;
                case 3:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::White, PieceType::Queen));
                break;
                case 4:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::White, PieceType::King));
                break;
                case 5:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::White, PieceType::Bishop));
                break;
                case 6:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::White, PieceType::Knight));
                break;
                case 7:
                    pieces.push_back(Piece((j*8)+i, positions[(j*8)+i], PieceTeam::White, PieceType::Rook));
                break;
                default:
                break;
            }
        }
    }
}
    return pieces;
}
void drawPieces(sf::RenderWindow& window, std::vector<Piece>& pieces)
{
    for(Piece piece : pieces){
        piece.draw(window);
    }
}