#ifndef BULLET_H
#define BULLET_H
#include "BulletMovement.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>


enum class Owner{PLAYER, ENEMY};//Who owns the shot bullet
class bullet_FileNotFound {};


/**
 * @class Bullet
 * @author James Phillips (1036603)
 * @file Bullet.h
 * @brief A class that will contain the characteristics of the needed bullet, such as its position, damage, speed, rotation, sprite, owner and so forth.
 */
class Bullet
{
public:

    Bullet(const sf::Vector2f& startingPos,  const float& rotation, Owner BulletOwner, int damage = 1);//Bullet will start at players position
    virtual ~Bullet();
    sf::Sprite getSprite();

    
    void updateBullet(const float& elapsedTime);
    bool bulletIsAlive();
    int getBulletDamage();//Bullet Damage
    void setInActive();//Disable the bullet
	void move(const float& elapsedTime);//Move the 

    sf::Vector2f getBulletPos() const
    {
        return _bulletPos;   //ONLY USED FOR TESTING
    }
    float getSpeed() const
    {
        return _speed;   //ONLY FOR TESTING
    }
    void setActive(bool val)
    {
        _isAlive = val;   //ONLY FOR TESTING
    }
    void setBulletPosition(float x, float y)
    {
        _bulletPos.x = x; //ONLY FOR TESTING
        _bulletPos.y = y;
        _bulletSprite.setPosition(_bulletPos);
    }


private:
    Bullet();//Private default constructor for static

    sf::Vector2f _bulletPos;//Bullet Position
    sf::Sprite _bulletSprite;//Bullet Sprite
    sf::Texture _bulletTexture;//Bullet Texture
    float _speed;//Speed of bullet
    float _rotation;
    int _damage;//The bullet will deal a certain amount of damage
    bool _isAlive;
	Owner _bulletOwner;//Who owns the bullet
    
    static Bullet _default;//Default bullet, so only load from file once.

    sf::Vector2f _displaySize;



};

#endif // BULLET_H
