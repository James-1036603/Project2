#include "EnemyMovement.h"

EnemyMovement::EnemyMovement()
{
    //ctor

}

EnemyMovement::~EnemyMovement()
{
    //dtor
}

void EnemyMovement::MoveEnemy(sf::Vector2f& enemyPos, const float& speed, const float& elapsedTime, const float& rotation)
{
    enemyPos.x += -(speed*elapsedTime) * std::cos(rotation);
    enemyPos.y += -(speed*elapsedTime) * std::sin(rotation);
    std::cout<<"Enemy has moved: "<<enemyPos.x<<'\t'<<enemyPos.y<<'\n';

}

