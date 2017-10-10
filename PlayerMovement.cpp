#include "PlayerMovement.h"

PlayerMovement::PlayerMovement()
{
	
}

PlayerMovement::~PlayerMovement()
{
	
}

void PlayerMovement::MovePlayerClockwise(sf::Vector2f& curPos, const int& speed, const float& elapsedTime, const float& circleRadius, float& rotation)
{
	auto angle = rotation - ((speed*elapsedTime)/100);
    curPos.y = circleRadius * std::sin(angle)+540;
    curPos.x = circleRadius * std::cos(angle)+960;
    rotation = angle;
}

void PlayerMovement::MovePlayerCounterClockwise(sf::Vector2f& curPos, const int& speed, const float& elapsedTime, const float& circleRadius, float& rotation)
{
	auto angle = rotation + ((speed*elapsedTime)/100);
    curPos.y = circleRadius * std::sin(angle)+540;
    curPos.x = circleRadius * std::cos(angle)+960;
    rotation = angle;
}