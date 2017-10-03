#include "BulletMovement.h"

BulletMovement::BulletMovement(const sf::Vector2f& bulletStartingPosition)
{
    //ctor
    _bulletStartPos = bulletStartingPosition;
    _gradient = BulletMovement::gradient();
    _yIntercept= BulletMovement::yIntercept();
}

BulletMovement::~BulletMovement()
{
    //dtor
}

float BulletMovement::gradient()
{
    auto y1 = _bulletStartPos.y;
    auto x1 = _bulletStartPos.x;

    return((CENTER_Y-y1)/(CENTER_X-x1));
}

float BulletMovement::yIntercept()
{
    return CENTER_Y - (_gradient * CENTER_X);
}

void BulletMovement::MovePlayerBullet(sf::Vector2f* curPos, const float& elapsedTime, bool& bulletSatus)
{
	
    
}
void BulletMovement::MoveEnemyBullet(sf::Vector2f* curPos, const float& elapsedTime, bool& bulletSatus, const float& rotation, const float& speed)
{
    curPos->x += -(speed*elapsedTime) * std::cos(rotation);
    curPos->y += -(speed*elapsedTime) * std::sin(rotation);
    if(curPos->x>1920 || curPos->x<0 || curPos->y > 1080 || curPos->y <0) bulletSatus = 0; //If the bullet has gone off the screen, set inactive
}
