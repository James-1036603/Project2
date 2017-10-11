#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include "Player.h"
#include "Collisions.h"
#include <vector>
#include <SFML/System.hpp>
#include <iostream>
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
    PlayerManager(const sf::Vector2f& windowSize, const float& radius);
    virtual ~PlayerManager();
    void updatePlayer(const float& elapsedTime);//Update the player
	void checkPlayerCollisionss(std::vector<Enemy>& curEnemies);    
    void playerShoot(float& elapsedTime);
    void drawPlayerToWindow(sf::RenderWindow* currentWindow);
    void drawPlayerBullets(sf::RenderWindow* currentWindow);
    bool playerIsAlive() const;
    void movePlayer(MoveDirection dirToMove);//Move the player
    Player& theCurrentPlayer();//Return the active player. needed for collision checking in enemy
	
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
