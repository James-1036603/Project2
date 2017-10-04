#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H
#include <vector>
#include <SFML/System.hpp>
#include "Enemy.h"
#include "EnemyMovement.h"
#include "BulletManager.h"
#include "Player.h"


class EnemyManager
{
public:
    EnemyManager();
    virtual ~EnemyManager();
    void spawnEnemies(int& currentLevel);//Spawn new enemies in a level
    void updateEnemies(const float& elapsedTime);
    void drawEnemies(sf::RenderWindow* _curWindow);//Draw enemies to the current window
    void drawEnemyBullets(sf::RenderWindow* _curWindow);//Draw the enemy bullets to the window
    void checkEnemyBulletsToPlayer(Player& thePlayer);
    bool allEnemiesKilled();//If all the enemies are killed,
    std::vector<Enemy>& theEnemies();//Defined as a reference for correct passing to other functions
	void randomEvents(const float& elapsedTime);//Any random any events which need to take place will fall under here
private:
    std::vector<Enemy> _curEnemies;//The current enemies on display
    EnemyMovement _enemyMover;
    BulletManager _enemyBulletManager;
    std::vector<Enemy> removeInactiveEnemies();
	float _elapsedClockTime;
	float _generatedClockTime;	
	void generateRandomTime();//Generate a number for which the clock has to count to before a event
	void spawnEnemyTank(const float& elapsedTime);
};

#endif // ENEMYMANAGER_H
