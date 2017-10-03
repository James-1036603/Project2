#include "EnemyMovement.h"

EnemyMovement::EnemyMovement()
{
    //ctor

}

EnemyMovement::~EnemyMovement()
{
    //dtor
}

void EnemyMovement::MoveEnemyScout(sf::Vector2f& enemyPos, const float& speed, const float& elapsedTime,float& rotation)
{   
	enemyPos.x += -(speed*elapsedTime) * std::cos(rotation);
	enemyPos.y += -(speed*elapsedTime) * std::sin(rotation);
}

void EnemyMovement::MoveEnemySoldier(sf::Vector2f& enemyPos, const float& speed, const float& elapsedTime,float& rotation)
{
	enemyPos.x += -(speed*elapsedTime) * std::cos(rotation);
	enemyPos.y += -(speed*elapsedTime) * std::sin(rotation);
	
}

void EnemyMovement::MoveEnemyRogue(sf::Vector2f& enemyPos, const float& speed, const float& elapsedTime,float& rotation)
{
	auto x = enemyPos.x-960;
	auto y = enemyPos.y-540;
	auto mod = sqrt((y*y)+(x*x));
	mod += speed*elapsedTime;
	rotation += 0.033;
	enemyPos.x = mod*std::cos(rotation)+960;
	enemyPos.y = mod*std::sin(rotation)+540;
}