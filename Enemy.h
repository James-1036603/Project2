#ifndef ENEMY_H
#define ENEMY_H
#include <vector>
#include <SFML/System.hpp>
#include "EnemyMovement.h"
#include "Bullet.h"
#include "BulletManager.h"
#define PI 3.14

#include <iostream>

class enemy_FileNotFound {};
enum class EnemyType {SCOUT,SOLDIER,ROGUE,TANK}; //Three enemy types
/**
 * @class Enemy
 * @author James Phillips (1036603)
 * @file Enemy.h
 * @brief Enemy class, which has 4 types of enemies. Each enemy has a postion, sprite, speed, rotation, bullet damage and the amount of steps taken. The enemy is moved based on its current type
 */

class Enemy
{
public:
    
/**
 * @brief Constructor for enemy
 * @param displaySize The size of the current display
 * @param BulMan Bullet manager, to remove any inactive bullets
 * @param EnemyMover The movement of the enemy
 * @param enemyType The type of enemy. Either SCOUT, SOLDIER, ROGUE, or TANK
 */
	
    Enemy(const sf::Vector2f& displaySize, BulletManager* BulMan, EnemyMovement* EnemyMover, EnemyType enemyType);
/**
 * @brief Enemy Destructor
 */
	
    virtual ~Enemy();
/**
 * @brief Returns the sprite of the current enemy.
 */
	
    sf::Sprite getSprite() const;
/**
 * @brief Allow the enemy to shoot
 */
	
    void Shoot();
/**
 * @brief Allow the current enemy to take damage
 */
	
    void getShot();
    /**
     * @brief Evaluate whether the enemy is alive or not
     */
    bool isAlive() const;
    /**
     * @brief Return the type of enemy
     */
    EnemyType typeOfEnemy();
    /**
     * @brief Update the enemy based on the amount of passed time.
     * @param elapsedTime How much time has passed
     */
    void update(const float& elapsedTime);//Called once per frame
    /**
     * @brief Return the active enemy bullets
     */
    std::vector<Bullet> getEnemyBullets();
/**
 * @brief Draw the enemy's bullets to the provided window
 * @param currentWindow The active window to draw to
 */
	
    void drawBullets(sf::RenderWindow* currentWindow);
/**
 * @brief Set the bullet to inactive at the provided index
 * @param index The index of the bullet to be marked as inactive
 */
	void setBulletInactiveAtPosition(int index);



    sf::Vector2f getEnemyPos() const
    {
        return _curPosition;   //ONLY FOR TESTS
    }
    float getSpeed() const
    {
        return _speed;   //ONLY FOR TESTS
    }
    float getDamageForBullet() const
    {
        return _damageForBullet; //ONLY FOR TESTS
    }
    void setStepsTaken(int num)
    {
        _stepsTaken = num;//ONLY FOR TESTS
    }
    void setRotation(float num)
    {
        _objSprite.setRotation(num);//ONLY FOR TESTS
		_rotation=num;
	}
	
	void setEnemyPosition(float x, float y)
	{
		_curPosition.x = x;//ONLY FOR TESTS
		_curPosition.y = y;
        _objSprite.setPosition(_curPosition);
	}
    
    void setPositionOfBullet(int indexOfBullet, float x, float y)//ONLY FOR TESTS
    {
        _enemyBullets[indexOfBullet].setBulletPosition(x,y);
    }

private:
	Enemy(EnemyType enemyType);//Constructor used by static enemies, not for use of playable enemies
    sf::Vector2f _curPosition;//Where is the current object
    sf::Sprite _objSprite;//Sprite for the object
    sf::Texture _objTexture;//Texture for the object . Static because it is slow to load the texture each time from file!!
    float _speed;//Speed of pixels per second
    float _rotation;
    int _stepsTaken;//The idea is, a bullet will be shot every 5 steps taken
    int _damageForBullet;//Damage for the bullet (related to the type of enemy)
    EnemyType _typeOfEnemy;



    std::vector<Bullet> _enemyBullets;
    void updateBullets(const float& elapsedTime);
    void checkBounds();//Check if the enemy has moved out of bounds

    static Enemy _defaultScout;//Static enemy for Scout
    static Enemy _defaultSoldier;//Static enemy for Soldier
    static Enemy _defaultRogue;//Static enemy for Rogue
	static Enemy _defaultTank;//Static enemy for Tank
	
	EnemyMovement* _moveEnemy;
    BulletManager* _BulletManager;    

    sf::Vector2f _displaySize;//When the enemy goes off the screen

    bool _isAlive;
    void generateRotation();//Generate a random angle for the sprite
    friend class EnemyManager;

};

#endif // ENEMY_H
