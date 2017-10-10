#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	_elapsedClockTime = 0;
	EnemyManager::generateRandomTime();
}

EnemyManager::~EnemyManager()
{
    
}

void EnemyManager::spawnEnemies(int& currentLevel)
{
    _curEnemies.clear();
    sf::Vector2f displaySize(1920,1080);
  for(auto i = 0; i<10-currentLevel; i++)
    {
        Enemy aNewEnemy(displaySize, &_enemyBulletManager,  &_enemyMover,EnemyType::SCOUT);
        _curEnemies.push_back(aNewEnemy);
    }
    for(auto i = 0; i<currentLevel; i++)
    {
        Enemy aNewEnemy(displaySize, &_enemyBulletManager, &_enemyMover, EnemyType::SOLDIER);
        _curEnemies.push_back(aNewEnemy);
    }
    for(auto i = 0; i<currentLevel/2; i++)
    {
        Enemy aNewEnemy(displaySize, &_enemyBulletManager, &_enemyMover,  EnemyType::ROGUE);
        _curEnemies.push_back(aNewEnemy);
    }

}

void EnemyManager::updateEnemies(const float& elapsedTime)
{
    for(auto i = 0u; i != _curEnemies.size(); i++) _curEnemies[i].update(elapsedTime);
    _curEnemies =  EnemyManager::removeInactiveEnemies();
}

void EnemyManager::drawEnemies(sf::RenderWindow* _curWindow)
{
    for(auto curEnemy : _curEnemies) _curWindow->draw(curEnemy.getSprite());

}

void EnemyManager::drawEnemyBullets(sf::RenderWindow* _curWindow)
{
    for(auto curEnemy : _curEnemies) curEnemy.drawBullets(_curWindow);
}

std::vector<Enemy>& EnemyManager::theEnemies()
{
    return _curEnemies;
}

std::vector<Enemy> EnemyManager::removeInactiveEnemies()
{
    std::vector<Enemy> activeEnemies;
    for(auto curEnemy : _curEnemies) if(curEnemy.isAlive()) activeEnemies.push_back(curEnemy);
    return activeEnemies;
}

bool EnemyManager::allEnemiesKilled()
{
    if(_curEnemies.size()==0) return true;
    else return false;
}

void EnemyManager::checkEnemyBulletsToPlayer(Player& thePlayer)
{
    for(auto i = 0u; i != _curEnemies.size(); i++)
    {
          for(auto j = 0u; j != _curEnemies[i]._enemyBullets.size(); j++)
          {
              if(thePlayer.getSprite().getGlobalBounds().contains(_curEnemies[i]._enemyBullets[j].getBulletPos()))
                 {
                     thePlayer.getShot(_curEnemies[i]._enemyBullets[j].getBulletDamage());
                     _curEnemies[i]._enemyBullets[j].setInActive();                     
                 }
          }
    }
}

void EnemyManager::randomEvents(const float& elapsedTime)
{
	EnemyManager::spawnEnemyTank(elapsedTime);
}

void EnemyManager::spawnEnemyTank(const float& elapsedTime)//Generate a tanak based on the level, using a random number and modulus 11 (less occuring divisor)
{
	_elapsedClockTime += elapsedTime;	
	if(_elapsedClockTime > _generatedClockTime){
		sf::Vector2f displaySize(1920,1080);
		Enemy aNewEnemy(displaySize, &_enemyBulletManager, &_enemyMover, EnemyType::TANK);
		_curEnemies.push_back(aNewEnemy);        
		EnemyManager::generateRandomTime();//Generate a new random time
		_elapsedClockTime = 0;//Reset the elapsed clock time		
	}

}

void EnemyManager::generateRandomTime()
{
	_generatedClockTime = rand()%5+1;//Generate a number between 1 and 5
	_generatedClockTime = _generatedClockTime*5;//Multiply by 20 to give larger increments	
}