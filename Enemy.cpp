#include "Enemy.h"


Enemy Enemy::_defaultScout {EnemyType::SCOUT};
Enemy Enemy::_defaultSoldier {EnemyType::SOLDIER};
Enemy Enemy::_defaultRogue {EnemyType::ROGUE};

Enemy::Enemy(EnemyType enemyType)
{
    //ctor

    switch(enemyType)//Identify the correct type of enemy for the correct texture and speed
    {
    case EnemyType::SCOUT:
        if (!_objTexture.loadFromFile("EnemyCharacterScout.png")) throw enemy_FileNotFound();
        _speed = 50;
        _typeOfEnemy = EnemyType::SCOUT;
        _damageForBullet = 1;
        break;
    case EnemyType::SOLDIER:
        if (!_objTexture.loadFromFile("EnemyCharacterSoldier.png")) throw enemy_FileNotFound();
        _speed = 100;
        _typeOfEnemy = EnemyType::SOLDIER;
        _damageForBullet = 2;
        break;
    case EnemyType::ROGUE:
        if (!_objTexture.loadFromFile("EnemyCharacterRogue.png")) throw enemy_FileNotFound();
        _speed = 150;
        _typeOfEnemy = EnemyType::ROGUE;
        _damageForBullet = 3;
        break;
    }

    _objSprite.setTexture(_objTexture);
    _curPosition.x = 960;
    _curPosition.y = 540;
    _isAlive = 1;
    _stepsTaken = 0;
}

Enemy::Enemy(const sf::Vector2f& displaySize, BulletManager* BulMan, EnemyMovement* EnemyMover, EnemyType enemyType)
{

    switch(enemyType)//Identify the correct type of enemy for the correct sprite and speed
    {
    case EnemyType::SCOUT:
        _objSprite = _defaultScout._objSprite;
        _speed = _defaultScout._speed;
        _typeOfEnemy = _defaultScout._typeOfEnemy;
        _damageForBullet = _defaultScout._damageForBullet;
        break;
    case EnemyType::SOLDIER:
        _objSprite = _defaultSoldier._objSprite;
        _speed = _defaultSoldier._speed;
        _typeOfEnemy = _defaultSoldier._typeOfEnemy;
        _damageForBullet = _defaultSoldier._damageForBullet;
        break;
    case EnemyType::ROGUE:
        _objSprite = _defaultRogue._objSprite;
        _speed = _defaultRogue._speed;
        _typeOfEnemy = _defaultRogue._typeOfEnemy;
        _damageForBullet = _defaultRogue._damageForBullet;
        break;
    }

    //All the other enemies start at the same center position and use the same other methods, thus we can use any of the default objects
    Enemy::generateRotation();
    _curPosition.x = _defaultScout._curPosition.x;
    _curPosition.y = _defaultScout._curPosition.y;
    _stepsTaken = _defaultScout._stepsTaken;
    _objSprite.setRotation(_rotation*(180/PI));
    _objSprite.setPosition(_curPosition);


    _BulletManager = BulMan;
    _moveEnemy = EnemyMover;
    _displaySize = displaySize;


}

Enemy::~Enemy()
{
    //dtor
}

sf::Sprite Enemy::getSprite() const
{
    return _objSprite;
}

void Enemy::update(const float& elapsedTime)
{
    //Move the enemy
    _moveEnemy->MoveEnemy(_curPosition,_speed,elapsedTime, _rotation);
    Enemy::checkBounds();
    _objSprite.setPosition(_curPosition);
    //Enemy Shoot
    _stepsTaken++;
    Enemy::Shoot();
    //Update Bullets
    Enemy::updateBullets(elapsedTime);


}

void Enemy::generateRotation()
{
    float random = rand()%100;
    _rotation = 2 * PI * (random/100);
}

void Enemy::checkBounds()
{
    if(_curPosition.x >= _displaySize.x || _curPosition.x <= 0 ||
            _curPosition.y >= _displaySize.y || _curPosition.y <= 0)
    {
        _curPosition.x = 960;//Reset if out of bounds x
        _curPosition.y = 540;//Reset if out of bounds y
        Enemy::generateRotation();//Another random line once moved off screen
        _objSprite.setRotation(_rotation *(180/PI) );
    }

}

void Enemy::Shoot()
{
    int steps = _stepsTaken;
    if(steps == 50)//Shoot a bullet after every X amount of steps
    {
        Bullet newBullet(_curPosition, _rotation, _damageForBullet);
        _enemyBullets.push_back(newBullet);
        _stepsTaken = 0;
    }

}

void Enemy::updateBullets(const float& elapsedTime)
{
    for(auto i = 0u; i != _enemyBullets.size(); i++)
    {
        _enemyBullets[i].updateEnemyBullet(elapsedTime);
    }
    _enemyBullets = _BulletManager->deleteInactiveBullets(&_enemyBullets);

}

void Enemy::drawBullets(sf::RenderWindow* currentWindow)
{
    for(auto currentBullet : _enemyBullets)  if(currentBullet.bulletIsAlive())  currentWindow->draw(currentBullet.getSprite());

}

std::vector<Bullet> Enemy::getEnemyBullets() const
{
    return _enemyBullets;
}

void Enemy::getShot()
{
    _isAlive = false;
}

bool Enemy::isAlive() const
{
    return _isAlive;
}

EnemyType Enemy::typeOfEnemy()
{
    return _typeOfEnemy;
}
