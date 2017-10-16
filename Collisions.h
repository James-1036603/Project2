#ifndef COLLISIONS_H
#define COLLISIONS_H
#include <vector>
#include "Enemy.h"
#include "Player.h"
/**
 * @class Collisions
 * @author James Phillips (1036603)
 * @file Collisions.h
 * @brief A class to evaluate the needed collisions. Currently they are enemy bullets to player, player bullets to enemy, enemy position to player
 */

class Collisions
{
public:
/**
 * @brief Collisions Constructor
 */

	Collisions();
/**
 * @brief Collisions Destructor
 */
	
	~Collisions();
public:
/**
 * @brief Check the Player orientated collisions
 * @param currentEnemies The active enemies
 * @param currentPlayer	The active player
 */

	void checkPlayerCollisions(std::vector<Enemy>& currentEnemies, Player& currentPlayer);
/**
 * @brief Check the Enemy orientated collisions
 * @param currentEnemies The active enemies
 * @param currentPlayer The active player
 */
	
	void checkEnemyCollisions(std::vector<Enemy>& currentEnemies, Player& currentPlayer);
private:
	void checkPlayerToEnemy(Player& currentPlayer, std::vector<Enemy>& currentEnemies);	
	void checkEnemyBulletsToPlayer(std::vector<Enemy>& currentEnemies, Player& currentPlayer);
	void checkEnemyPositionToPLayer(std::vector<Enemy>& currentEnemies, Player& currentPlayer);
};

#endif // COLLISIONS_H
