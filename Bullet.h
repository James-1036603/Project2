#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <cmath>

/** An enum for the owner of the bullet
 * The owner of the bullet is either the Player or an Enemy
 */
enum class Owner{PLAYER, ENEMY};//Who owns the shot bullet
/**
 * @class bullet_FileNotFound
 * @file Bullet.h
 * @brief File Not Found for Bullet. Used in error catching
 */

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
 * @param startingPos 
 * @param rotation 
 * @param BulletOwner 
 * @param damage 
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
     * @param elapsedTime 
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

    sf::Vector2f _bulletPos;
    sf::Sprite _bulletSprite;
    sf::Texture _bulletTexture;
    float _speed;
    float _rotation;
    int _damage;
    bool _isAlive;
	Owner _bulletOwner;    
    static Bullet _default;	
	void move(const float& elapsedTime);



};

#endif // BULLET_H
