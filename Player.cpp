#include "Player.h"

Player::Player(const sf::Vector2f& displaySize, const float& radius, BulletManager* BulMan, PlayerMovement* playerMover)
{
    //ctor
    _speed = 200;
    _playerLives = 100;
    if(!_objTexture.loadFromFile("PlayerCharacterSmall.png")) throw player_FileNotFound();
    _objSprite.setTexture(_objTexture);//set object texture

    //Starting position
    _curPosition.x = 960-radius;
    _curPosition.y = 540;

    _circleRadius = radius;
    _curAngle = PI;

    _playerBulletManager = *BulMan;
	_playerMover = playerMover;


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

void Player::Shoot()
{
		Bullet bulletShot(_curPosition,  _curAngle, Owner::PLAYER);
        _playerBullets.push_back(bulletShot);    
}

void Player::update(const float& elapsedTime)
{
    //Update the player postion
    if(_rightPressed) _playerMover->MovePlayerClockwise(_curPosition, _speed, elapsedTime, _circleRadius, _curAngle);

    if(_leftPressed) _playerMover->MovePlayerCounterClockwise(_curPosition, _speed, elapsedTime, _circleRadius, _curAngle);

    _objSprite.setPosition(_curPosition);
    _objSprite.setRotation((_curAngle * (180/PI))); 

    Player::updateBullets(elapsedTime);


}

void Player::updateBullets(const float& elapsedTime)
{
    //Update the bullets position
    for(auto i = 0u; i != _playerBullets.size(); i++)
    {
        _playerBullets.at(i).updateBullet(elapsedTime);
    }
    _playerBullets =  _playerBulletManager.deleteInactiveBullets(&_playerBullets);
}

void Player::getShot(int bulletDamage)
{
    _playerLives -= bulletDamage;
}

bool Player::isAlive() const
{
    if(_playerLives == 0 || _playerLives > 100) return false;
    else return true;
}

std::vector<Bullet> Player::getPlayerBullets()
{
    return _playerBullets;
}



void Player::drawBullets(sf::RenderWindow* currentWindow)
{
    for(auto currentBullet : _playerBullets)
        if(currentBullet.bulletIsAlive())currentWindow->draw(currentBullet.getSprite());//Draw the bullet to the screen, but only if it is active
}

void Player::setBulletInactiveAtPosition(int index)
{
	_playerBullets[index].setInActive();
}