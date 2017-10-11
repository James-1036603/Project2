#ifndef COLLISIONS_H
#define COLLISIONS_H
#include <vector>
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include <iostream>
class Collisions
{
public:
	Collisions();
	~Collisions();
public:
	void checkPlayerCollisions(std::vector<Enemy>& currentEnemies, Player& currentPlayer);
	void checkEnemyCollisions(std::vector<Enemy>& currentEnemies, Player& currentPlayer);
private:
	void checkPlayerToEnemy(Player& currentPlayer, std::vector<Enemy>& currentEnemies);	
	void checkEnemyBulletsToPlayer(std::vector<Enemy>& currentEnemies, Player& currentPlayer);
	void checkEnemyPositionToPLayer(std::vector<Enemy>& currentEnemies, Player& currentPlayer);
};

#endif // COLLISIONS_H
