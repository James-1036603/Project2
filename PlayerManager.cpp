#include "PlayerManager.h"

PlayerManager::PlayerManager(const sf::Vector2f& windowSize, const float& radius):
	_curPlayer(windowSize, radius, &_playerBulletMananger, &_playerMover),
	_playerBulletMananger()
	
{
    //ctor
    PlayerManager::SetTextAndFont();
}

PlayerManager::~PlayerManager()
{
    //dtor

}

void PlayerManager::movePlayer(MoveDirection dirToMove)//Move the player
{
    if(dirToMove == MoveDirection::RIGHT) _curPlayer.moveRight();
    else if(dirToMove == MoveDirection::STOP_RIGHT) _curPlayer.stopRight();

    if(dirToMove == MoveDirection::LEFT) _curPlayer.moveLeft();
    else if(dirToMove == MoveDirection::STOP_LEFT) _curPlayer.stopLeft();

}

void PlayerManager::updatePlayer(const float& elapsedTime)
{

    _curPlayer.update(elapsedTime);
    std::stringstream livesText;//Convert the lives to a string stream (int to string method)
    livesText << _curPlayer._playerLives;
    text.setString(livesText.str().c_str());//Set the text to lives
}

void PlayerManager::playerShoot()
{
    _curPlayer.Shoot();
}

void PlayerManager::drawPlayerToWindow(sf::RenderWindow* currentWindow)//Draw player to window
{
    currentWindow->draw(_curPlayer.getSprite());
    currentWindow->draw(text);//Draw the lives to the screen
}

void PlayerManager::drawPlayerBullets(sf::RenderWindow* currentWindow)//Draw player bullets to window
{
    _curPlayer.drawBullets(currentWindow);
}

bool PlayerManager::playerIsAlive() const
{
    return _curPlayer.isAlive();
}

void PlayerManager::checkPlayerCollisionss(std::vector<Enemy>& curEnemies)
{
	_collisionDetector.checkPlayerCollisions(curEnemies, _curPlayer);
}

Player& PlayerManager::theCurrentPlayer()
{
    return _curPlayer;
}

void PlayerManager::SetTextAndFont()
{
    if(!font.loadFromFile("arial.ttf")) throw player_FileNotFound();//Load font
    //Set text characteristics
    text.setFont(font);
    text.setCharacterSize(24);
    text.setPosition(1850,0);
    text.setStyle(sf::Text::Regular);
//    text.setFillColor(sf::Color::Red);

}
