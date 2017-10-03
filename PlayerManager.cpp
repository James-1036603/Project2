#include "PlayerManager.h"

PlayerManager::PlayerManager(const sf::Vector2f& windowSize, const float& radius, BulletManager* bullet_manager):
    _curPlayer(windowSize, radius, bullet_manager)
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

    //const sf::Keyboard::Key& curPressedKey
}

void PlayerManager::updatePlayer(const float& elapsedTime)
{

    _curPlayer.update(elapsedTime);
    std::stringstream livesText;//Convert the lives to a string stream (int to string method)
    livesText << _curPlayer._playerLives;
    text.setString(livesText.str().c_str());//Set the text to lives
}

void PlayerManager::playerShoot(float& elapsedTime)
{
    _curPlayer.Shoot(elapsedTime);
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

void PlayerManager::checkPlayerBulletsToEnemy(std::vector<Enemy>& curEnemies)//This is not a good method. What if bullet was implemented other to a vector? plus you reveal that enemy has a vector of bullets
{
    for(auto i = 0u; i != curEnemies.size(); i++)
    {
        for(auto j = 0u; j != _curPlayer.getPlayerBullets().size(); j++)
        {

            if(curEnemies.at(i).getSprite().getGlobalBounds().contains(_curPlayer.getPlayerBullets().at(j).getBulletPos()))
            {
                _curPlayer._playerBullets[j].setInActive();//Set the player bullet to inactive once it has hit an enemy
                curEnemies.at(i).getShot();//Enemy was shot
            }



//            if(_curPlayer.getSprite().getGlobalBounds().contains(curBullet->getBulletPos()))//global bounds considers the rotation of the sprite
//            {
//                _curPlayer.getShot(curBullet->getBulletDamage());
//                curBullet->setInActive();//Disable the bullet once it has hit the player
//            }
        }
    }
    //Note, the bullets are not being set inactive yet, thus causing more damage than once to the player. This is likely due to the fact that the returned vectors are CONSTANT, thus no changes to the bullet can be made
}

void PlayerManager::checkEnemyPositionToPlayer(const std::vector<Enemy>& curEnemies)
{
    for(auto curEnemy : curEnemies)
    {
        if(curEnemy.getSprite().getGlobalBounds().contains(_curPlayer.getPlayerPos()))
        {
			if(curEnemy.typeOfEnemy() == EnemyType::TANK) _curPlayer.getShot(10);//Tanks do substantial damage to player
			else _curPlayer.getShot(1);
            
        }
    }


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
