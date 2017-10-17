#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H
#include <vector>
#include <SFML/System.hpp>
#include "Enemy.h"
#include "Collisions.h"

/**
 * @class EnemyManager
 * @author James Phillips (1036603)
 * @file EnemyManager.h
 * @brief Manager class for an enemy. This class will maintain the amount of enemies in the game, the enemy's bullets, and the enemy's bullets to the player.
 */

class EnemyManager
{
public:
    /**
     * @brief Constructor for Enemy Manager
     */
    EnemyManager();
    /**
     * @brief Destructor for Enemy Manager
     */
    virtual ~EnemyManager();
    /**
     * @brief Spawn enemies based on the current level
     * @param currentLevel 
     */
    void spawnEnemies(int& currentLevel);//Spawn new enemies in a level
    /**
     * @brief Update the enemies based on the elapsed time
     * @param elapsedTime
     */
    void updateEnemies(const float& elapsedTime);
    /**
     * @brief Draw the enemies to the provided window
     * @param _curWindow
     */
    void drawEnemies(sf::RenderWindow* _curWindow);
   
    
	/**
	 * @brief Check the needed Enemy collisions to the player
	 * @param currentPlayer
	 */
	void checkEnemyCollisions(Player& currentPlayer);
    /**
     * @brief Evaluate if all the enemies are killed or not
     */
    bool allEnemiesKilled();
    /**
     * @brief The current active enemies
     */
    std::vector<Enemy>& theEnemies();
/**
 * @brief Any random events which need to take place, based on the passed time
 * @param elapsedTime
 */
	
	void randomEvents(const float& elapsedTime);
    
    
    void setFirstEnemyPosition(float x, float y)//ONLY FOR TESTS
	{
		_curEnemies[0].setEnemyPosition(x,y);
	}
	
	sf::Vector2f getFirstBulletPos()//ONLY FOR TESTS
	{
		return _curEnemies[0]._enemyBullets[0].getBulletPos();
	}
    void setFirstBulletPos(float x, float y)//ONLY FOR TESTS
    {
        _curEnemies[0]._enemyBullets[0].setBulletPosition(x,y);
    }
    
    void addEnemyToVector(Enemy theEnemy)//ONLY FOR TESTS
    {
        _curEnemies.push_back(theEnemy);
    }
    
    void setGeneratedClockTime(float clockTime)//ONLY FOR TESTS
    {
        _generatedClockTime = clockTime;
    }
    
    
private:
    std::vector<Enemy> _curEnemies;//The current enemies on display
    EnemyMovement _enemyMover;
    BulletManager _enemyBulletManager;
    std::vector<Enemy> removeInactiveEnemies();
	Collisions _collisionDetector;
	float _elapsedClockTime;
	float _generatedClockTime;	
	void generateRandomTime();//Generate a number for which the clock has to count to before a event
	void spawnEnemyTank(const float& elapsedTime);
	void drawEnemyBullets(sf::RenderWindow* _curWindow);//Draw the enemy bullets to the window
};

#endif // ENEMYMANAGER_H
