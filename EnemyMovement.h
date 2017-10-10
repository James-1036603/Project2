#ifndef ENEMYMOVEMENT_H
#define ENEMYMOVEMENT_H
#include <cstdlib>
#include <SFML/System.hpp>
#include <cmath>
#include <iostream>

/**
 * @class EnemyMovement
 * @author James Phillips (1036603)
 * @file EnemyMovement.h
 * @brief This will move a specific enemy, based on it's type
 */

class EnemyMovement
{
public:
    EnemyMovement();
    virtual ~EnemyMovement();

    void MoveEnemyScout(sf::Vector2f& enemyPos, const float& speed, const float& elapsedTime, float& rotation);
	void MoveEnemySoldier(sf::Vector2f& enemyPos, const float& speed, const float& elapsedTime, float& rotation);
	void MoveEnemyRogue(sf::Vector2f& enemyPos, const float& speed, const float& elapsedTime, float& rotation);
	void MoveEnemyTank(sf::Vector2f& enemyPos, const float& speed, const float& elapsedTime, float& rotation);


private:
};

#endif // ENEMYMOVEMENT_H
