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

class Enemy
{
public:
    Enemy(EnemyType enemyType);
    Enemy(const sf::Vector2f& displaySize, BulletManager* BulMan, EnemyMovement* EnemyMover, EnemyType enemyType);
    virtual ~Enemy();
    sf::Sprite getSprite() const;//Get a copy of the current sprite

    void Shoot();
    void getShot();
    bool isAlive() const;//Check if the enemy is alive
    EnemyType typeOfEnemy();//Return the type of enemy for damage calculation

    void update(const float& elapsedTime);//Called once per frame
    std::vector<Bullet> getEnemyBullets() const;
    void drawBullets(sf::RenderWindow* currentWindow);

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
    void setRotation(int num)
    {
        _objSprite.setRotation(num);//ONLY FOR TESTS
    }


private:
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
