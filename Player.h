#ifndef Player_H
#define Player_H

#define PI 3.14
#include <vector>
#include <SFML/System.hpp>
#include "Bullet.h"
#include "BulletManager.h"
#include "PlayerMovement.h"
#include <cmath>

#include <iostream>

class player_FileNotFound {};
/**
 * @class Player
 * @author James Phillips (1036603)
 * @date 10/10/2017
 * @file Player.h
 * @brief Player class has the needed member functions for the player, such as their position, sprite, speed, rotation and their bullets active on the screen. The player's movement is determined by the current input. THe player is able to shoot as well
 */

class Player
{
public:
    Player(const sf::Vector2f& displaySize, const float& radius, BulletManager* BulMan, PlayerMovement* playerMover);
    virtual ~Player();
    sf::Sprite getSprite();//Get a copy of the current sprite


    void moveCounterClockwise();//Move the object left
    void moveClockwise();//Move the object right
    void stopCounterClockwise();//Stop moving left
    void stopClockwise();//Stop moving right



    void update(const float& elapsedTime);//Called once per frame
    std::vector<Bullet> getPlayerBullets();
    void drawBullets(sf::RenderWindow* currentWindow);

    void Shoot(float& dtAsSeconds);//Player shoots a bullet
    void getShot(int bulletDamage);

    sf::Vector2f getPlayerPos() const
    {
        return _curPosition;   //ONLY FOR TESTS
    }
    float getSpeed() const
    {
        return _speed;   //ONLY FOR TESTS
    }
    void setPositionOfBullet(int indexOfBullet, float x, float y)
    {
        _playerBullets[indexOfBullet].setBulletPosition(x,y);
    }
    
    void setPositionOfPlayer(float x, float y)//ONLY FOR TESTS
    {
        _curPosition.x = x;
        _curPosition.y = y;
        _objSprite.setPosition(_curPosition);
        
    }
    
    unsigned int getHealth()//ONLY FOR TESTS
    {
        return _playerLives;
    }
    
	

private:
    bool isAlive() const;//Is the player still alive, ie if lives are not 0
    void updateBullets(const float& elapsedTime);



private:
    sf::Vector2f _curPosition;//Where is the current object
    sf::Sprite _objSprite;//Sprite for the object
    sf::Texture _objTexture;//Texture for the object . Static because it is slow to load the texture each time from file!!
    float _speed;//Speed of pixels per second
    unsigned int _playerLives;//The amount of lives the player has
    bool _rightPressed;//Object is moving right
    bool _leftPressed;//Object is moving left

    float _circleRadius;
    float _curAngle;
	PlayerMovement* _playerMover;

    std::vector<Bullet> _playerBullets;
    BulletManager _playerBulletManager;
	


    sf::Vector2f _displaySize;//The resolution of the display. Ensure that out player does not go out of bounds (This will not be needed for the angular movement)
    friend class PlayerManager;//Player manager can access private data members
};

#endif // Player_H
