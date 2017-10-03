#ifndef BULLET_H
#define BULLET_H
#include "BulletMovement.h"
#include <SFML/Graphics.hpp>
#include <cmath>


enum class Owner{PLAYER, ENEMY};//Who owns the shot bullet
class bullet_FileNotFound {};

class Bullet
{
public:

    Bullet(const sf::Vector2f& startingPos,  const float& rotation, Owner BulletOwner, int damage = 1);//Bullet will start at players position
    virtual ~Bullet();
    sf::Sprite getSprite();

    void updatePlayerBullet(const float& elapsedTime);//Player Bullet update
    void updateEnemyBullet(const float& elapsedTime);//Enemy bullet update (different movement to the player)
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
