#ifndef PLAYERMOVEMENT_H
#define PLAYERMOVEMENT_H
#include <SFML/System.hpp>
/**
 * @class PlayerMovement
 * @author James Phillips (1036603)
 * @file PlayerMovement.h
 * @brief The movement of the player. The player will either move clockwise or counter clockwise along the radial path
 */

class PlayerMovement
{
public:
	PlayerMovement();
	virtual ~PlayerMovement();
	void MovePlayerClockwise(sf::Vector2f& curPos, const int& speed, const float& elapsedTime, const float& circleRadius, float& rotation);
	void MovePlayerCounterClockwise(sf::Vector2f& curPos, const int& speed, const float& elapsedTime, const float& circleRadius, float& rotation);
private:
};


#endif // PLAYERMOVEMENT_H