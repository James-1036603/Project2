#include "Bullet.h"
Bullet Bullet::_default {};

Bullet::Bullet()
{
    _isAlive = 1;
    _speed = 1000;
	_bulletOwner = Owner::PLAYER;
    if(!_bulletTexture.loadFromFile("Bullet.png")) throw bullet_FileNotFound();
    _bulletSprite.setTexture(_bulletTexture);
}

Bullet::Bullet(const sf::Vector2f& startingPos, const float& rotation,Owner BulletOwner, int damage )
{
    //ctor
	_bulletOwner = BulletOwner;
    _speed=_default._speed;
    _damage = damage;
    _isAlive = _default._isAlive;
    _rotation = rotation;
    _bulletSprite=_default.getSprite();
    _bulletPos = startingPos;
    _bulletSprite.setRotation((rotation*180/3.14)+90);
	
}

Bullet::~Bullet()
{
    //dtor
}

bool Bullet::bulletIsAlive()
{
    return _isAlive;
};

void Bullet::updatePlayerBullet(const float& elapsedTime)
{
    
    Bullet::move(elapsedTime);
    _bulletSprite.setPosition(_bulletPos);
    
}

void Bullet::updateEnemyBullet(const float& elapsedTime)
{
    Bullet::move(elapsedTime);
    _bulletSprite.setPosition(_bulletPos);
}

void Bullet::move(const float& elapsedTime)
{
		_bulletPos.x += -(_speed*elapsedTime) * std::cos(_rotation);
		_bulletPos.y += -(_speed*elapsedTime) * std::sin(_rotation);        
	switch (_bulletOwner)
	{
		case Owner::PLAYER:
			if(_bulletPos.x > 950 && _bulletPos.x < 970)
			{
				_isAlive = 0; //If the bullet is at the center of the screen, set inactive				
			}
			break;
            
		case Owner::ENEMY:        
			if(_bulletPos.x > 1920 || _bulletPos.x <0 || _bulletPos.y > 1080 || _bulletPos.y < 0) _isAlive = 0; //If the bullet is at the center of the screen, set inactive
			break;		
	}
		
}

sf::Sprite Bullet::getSprite()
{
    return _bulletSprite;
}

void Bullet::setInActive()
{
    _isAlive = false;
}

int Bullet::getBulletDamage()
{
    return _damage;
}
