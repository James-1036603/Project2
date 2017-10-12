#ifndef BULLET_H
#define BULLET_H
#include "BulletMovement.h"
#include <SFML/Graphics.hpp>
#include <cmath>

/** An enum for the owner of the bullet
 * THe owner of the bullet is either the Player or an Enemy
 */
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
/**
 * @brief Bullet Constructor
 * @param startingPos Starting position of the bullet
 * @param rotation The rotation which the bullet should adopt
 * @param BulletOwner The owner of the bullet, either player or enemy
 * @param damage Damage for the bullet
 */

    Bullet(const sf::Vector2f& startingPos,  const float& rotation, Owner BulletOwner, int damage = 1);//Bullet will start at players position
/**
 * @brief Bullet Destructor
 */
	
    virtual ~Bullet();
/**
 * @brief Sprite of the bullet
 */
	
    sf::Sprite getSprite();

    /**
     * @brief Update the bullet over time. This will move the bullet, and evaluate its position on the screen.
     * @param elapsedTime How much time has passed since the last frame, this will evaluate how many pixels the bullet has to move
     */
    
    void updateBullet(const float& elapsedTime);
/**
 * @brief The state of the bullet, if it is active or not
 */
	
    bool bulletIsAlive();
/**
 * @brief The damage of the current bullet
 */
	
    int getBulletDamage();//Bullet Damage
/**
 * @brief Set the bullet inactive for any needed reason
 */
	
    void setInActive();//Disable the bullet
	
	

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
    Bullet();

    sf::Vector2f _bulletPos;/*! The current position of the bullet*/
    sf::Sprite _bulletSprite;/*! The current bullet sprite. This is what is represented to the window*/
    sf::Texture _bulletTexture;/*! The texture for the bullet*/
    float _speed;/*! The speed of the bullet*/
    float _rotation;/*! The rotation of the bullet*/
    int _damage;/*! The damage of the bullet*/
    bool _isAlive;/*! The bullet state, whether active or not*/
	Owner _bulletOwner;/*! The owner of the bullet*/
    
    static Bullet _default;/*! A static member of the bullet, the program only needs to load the texture once*/
/**
 * @brief Move the bullet based on the amount of time which has passed
 * @param elapsedTime The amount of time which has passed, this will determine how far the bullet has to move
 */
	
	void move(const float& elapsedTime);
	
    //sf::Vector2f _displaySize;



};

#endif // BULLET_H
