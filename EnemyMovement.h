#ifndef ENEMYMOVEMENT_H
#define ENEMYMOVEMENT_H
#include <cstdlib>
#include <SFML/System.hpp>
#include <cmath>

/**
 * @class EnemyMovement
 * @author James Phillips (1036603)
 * @file EnemyMovement.h
 * @brief This will move a specific enemy, based on it's type
 */

class EnemyMovement
{
public:
    /**
     * @brief Enemy Movement Constructor
     */
    EnemyMovement();
    /**
     * @brief Enemy Movement Destructor
     */
    virtual ~EnemyMovement();
	
    /**
     * @brief Enemy Scout Movement
     * @param enemyPos
     * @param speed
     * @param elapsedTime
     * @param rotation
     */
    void MoveEnemyScout(sf::Vector2f& enemyPos, const float& speed, const float& elapsedTime, float& rotation);
/**
 * @brief Enemy Soldier Movement
 * @param enemyPos
 * @param speed
 * @param elapsedTime
 * @param rotation
 */
	void MoveEnemySoldier(sf::Vector2f& enemyPos, const float& speed, const float& elapsedTime, float& rotation);
/**
 * @brief Enemy Rogue Movement
 * @param enemyPos
 * @param speed
 * @param elapsedTime
 * @param rotation
 */
	void MoveEnemyRogue(sf::Vector2f& enemyPos, const float& speed, const float& elapsedTime, float& rotation);
/**
 * @brief Enemy Tank Movement
 * @param enemyPos
 * @param speed
 * @param elapsedTime
 * @param rotation
 */
	void MoveEnemyTank(sf::Vector2f& enemyPos, const float& speed, const float& elapsedTime, float& rotation);


private:
};

#endif // ENEMYMOVEMENT_H
