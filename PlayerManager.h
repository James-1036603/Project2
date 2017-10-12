#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include "Player.h"
#include "Collisions.h"
#include <vector>
#include <SFML/System.hpp>
#include <sstream>

enum class MoveDirection {RIGHT, LEFT, STOP_RIGHT, STOP_LEFT};
/**
 * @class PlayerManager
 * @author James Phillips (1036603)
 * @file PlayerManager.h
 * @brief The playermanager will maintain all updates and events to the player, such as player input, collision detection, drawing the player to the active window
 */

class PlayerManager
{
public:
/**
 * @brief Player Manager Constructor
 * @param windowSize
 * @param radius
 */

    PlayerManager(const sf::Vector2f& windowSize, const float& radius);
    /**
     * @brief Player Manager Destructor
     */
    virtual ~PlayerManager();
    /**
     * @brief Update the player over a certain amount of time
     * @param elapsedTime
     */
    void updatePlayer(const float& elapsedTime);
/**
 * @brief Check the Player's collisions to the enemies
 * @param curEnemies
 */
	void checkPlayerCollisionss(std::vector<Enemy>& curEnemies);    
    /**
     * @brief Allow the player to shoot
     * @param elapsedTime
     */
    void playerShoot();
    /**
     * @brief Draw the player to the provided window
     * @param currentWindow
     */
    void drawPlayerToWindow(sf::RenderWindow* currentWindow);
    /**
     * @brief Draw the player's bullets to the provided window
     * @param currentWindow
     */
    void drawPlayerBullets(sf::RenderWindow* currentWindow);
    /**
     * @brief Evaluate that the player is alive or not
     */
    bool playerIsAlive() const;
    /**
     * @brief Move the player in a given direction. Left, Right or Stop
     * @param dirToMove
     */
    void movePlayer(MoveDirection dirToMove);
    /**
     * @brief Return a reference to the current player
     */
    Player& theCurrentPlayer();
	
	
	
	void setPlayerPosition(float x, float y)//ONLY FOR TESTS
	{
		_curPlayer._curPosition.x = x;
		_curPlayer._curPosition.y = y;
	}
	
	sf::Vector2f getFirstBulletPos()//ONLY FOR TESTS
	{
		return _curPlayer.getPlayerBullets().at(0).getBulletPos();
	}
    void setFirstBulletPos(float x, float y)//ONLY FOR TESTS
    {
        _curPlayer.setPositionOfBullet(0, x, y);
    }
    unsigned int getPlayerHealth()//ONLY FOR TESTS
    {
        return _curPlayer._playerLives;
    }
private:
    Player _curPlayer;
    sf::Font font;//For lives to the screen
    sf::Text text;
	PlayerMovement _playerMover;
	BulletManager _playerBulletMananger;
	Collisions _collisionDetector;
	
    void SetTextAndFont();




};

#endif // PLAYERMANAGER_H
