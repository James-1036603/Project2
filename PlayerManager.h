#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

enum class MoveDirection {RIGHT, LEFT, STOP_RIGHT, STOP_LEFT};

class PlayerManager
{
public:
    PlayerManager(const sf::Vector2f& windowSize, const float& radius, BulletManager* bullet_manager);
    virtual ~PlayerManager();
    void updatePlayer(const float& elapsedTime);//Update the player
    void checkPlayerBulletsToEnemy(std::vector<Enemy>& curEnemies);//Check if the player is shoots an enemy
    void checkEnemyPositionToPlayer(const std::vector<Enemy>& curEnemies);//Check if an enemy collides with the player
    void playerShoot(float& elapsedTime);
    void drawPlayerToWindow(sf::RenderWindow* currentWindow);
    void drawPlayerBullets(sf::RenderWindow* currentWindow);
    bool playerIsAlive() const;
    void movePlayer(MoveDirection dirToMove);//Move the player
    Player& theCurrentPlayer();//Return the active player. needed for collision checking in enemy

private:
    Player _curPlayer;
    sf::Font font;//For lives to the screen
    sf::Text text;

    void SetTextAndFont();




};

#endif // PLAYERMANAGER_H
