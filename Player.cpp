#include "Player.h"

Player::Player(const sf::Vector2f& displaySize, const float& radius, BulletManager* BulMan)//IMPLEMENT THESE BETTER!
{
    //ctor
    _speed = 200;//How fast should the character move
    _playerLives = 100;//Player starts with 3 lives. Can be changed if needed
    if(!_objTexture.loadFromFile("PlayerCharacterSmall.png")) throw player_FileNotFound();//load texture
    _objSprite.setTexture(_objTexture);//set object texture

    //Starting position
//    _curPosition.x = displaySize.x/2-radius;
//    _curPosition.y = displaySize.y/2;
    _curPosition.x = 960-400;
    _curPosition.y = 540;

    _circleRadius = radius;
    _curAngle = PI;

    _playerBulletManager = *BulMan;


}

Player::~Player()
{
    //dtor
}

sf::Sprite Player::getSprite()
{
    return _objSprite;
}

void Player::moveRight()
{
    _rightPressed = true;
}

void Player::moveLeft()
{
    _leftPressed = true;
}

void Player::stopRight()
{
    _rightPressed = false;
}

void Player::stopLeft()
{
    _leftPressed = false;
}

void Player::Shoot(float& elapsedTime)
{
    if(elapsedTime>0.01)
    {
        std::cout<<"Player: "<<_curPosition.x<<"\t"<<_curPosition.y<<"\n";
        Bullet bulletShot(_curPosition,  _curAngle);//Create a new bullet
        _playerBullets.push_back(bulletShot);
    }

}

void Player::update(const float& elapsedTime)
{
    //Update the player postion
    if(_rightPressed) Player::moveClockwise(elapsedTime);

    if(_leftPressed) Player::moveCounterClockwise(elapsedTime);

    _objSprite.setPosition(_curPosition);
    _objSprite.setRotation((_curAngle * (180/PI)));//Rotate the sprite (degrees)
    std::cout<<"Moved Player: "<<_curPosition.x<<"\t"<<_curPosition.y<<'\n';

    Player::updateBullets(elapsedTime);//Update the bullets


}

void Player::updateBullets(const float& elapsedTime)
{
    //Update the bullets position
    for(auto i = 0u; i != _playerBullets.size(); i++)
    {
        _playerBullets.at(i).updatePlayerBullet(elapsedTime);
    }
    _playerBullets =  _playerBulletManager.deleteInactiveBullets(&_playerBullets);//Delete inactive Bullets
}

void Player::getShot(int bulletDamage)//The player was shot
{
    _playerLives -= bulletDamage;
}

bool Player::isAlive() const//Check player lives and evaluate if is alive or not
{
    if(_playerLives == 0 || _playerLives > 100) return false;
    else return true;
}

std::vector<Bullet> Player::getPlayerBullets()
{
    return _playerBullets;
}

void Player::moveClockwise(const float& elapsedTime)
{
    double angle = _curAngle - ((_speed*elapsedTime)/100);

    _curPosition.y = _circleRadius * std::sin(angle)+540;
    _curPosition.x = _circleRadius * std::cos(angle)+960;
    _curAngle = angle;
}

void Player::moveCounterClockwise(const float& elapsedTime)
{
    auto angle = _curAngle + ((_speed*elapsedTime)/100);

    _curPosition.y = _circleRadius * std::sin(angle)+540;
    _curPosition.x = _circleRadius * std::cos(angle)+960;
    _curAngle = angle;
}


void Player::drawBullets(sf::RenderWindow* currentWindow)
{
    for(auto currentBullet : _playerBullets)
        if(currentBullet.bulletIsAlive())currentWindow->draw(currentBullet.getSprite());//Draw the bullet to the screen, but only if it is active
}
