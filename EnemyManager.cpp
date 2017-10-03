#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
    //ctor
}

EnemyManager::~EnemyManager()
{
    //dtor
}

void EnemyManager::spawnEnemies(int& currentLevel)//First spawn one enemy, then 10 later, then use a level seed
{
    _curEnemies.clear();//Delete all enemies from vector
    sf::Vector2f displaySize(1920,1080);
	Enemy aNewEnemy(displaySize, &_enemyBulletManager, &_enemyMover, EnemyType::TANK);
	_curEnemies.push_back(aNewEnemy);
	
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
    for(auto i = 0u; i != _curEnemies.size(); i++) _curEnemies[i].update(elapsedTime); //Update all the enemies in the vector
    _curEnemies =  EnemyManager::removeInactiveEnemies();
}

void EnemyManager::drawEnemies(sf::RenderWindow* _curWindow)
{
    for(auto curEnemy : _curEnemies) _curWindow->draw(curEnemy.getSprite());//Draw all enemies in the vector to the screen

}

void EnemyManager::drawEnemyBullets(sf::RenderWindow* _curWindow)
{
    for(auto curEnemy : _curEnemies) curEnemy.drawBullets(_curWindow);//Draw all enemy's in the vector to the screen
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
