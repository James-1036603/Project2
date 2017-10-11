#include "Collisions.h"

Collisions::Collisions()
{
}

Collisions::~Collisions()
{
}

void Collisions::checkPlayerCollisions(std::vector<Enemy>& currentEnemies, Player& currentPlayer)
{
	Collisions::checkPlayerToEnemy(currentPlayer, currentEnemies);	
}

void Collisions::checkEnemyCollisions(std::vector<Enemy>& currentEnemies, Player& currentPlayer)
{
	Collisions::checkEnemyBulletsToPlayer(currentEnemies, currentPlayer);
	Collisions::checkEnemyPositionToPLayer(currentEnemies, currentPlayer);
}

void Collisions::checkPlayerToEnemy(Player& currentPlayer, std::vector<Enemy>& currentEnemies)
{
	for(auto i = 0u; i != currentEnemies.size(); i++)
    {
        for(auto j = 0u; j != currentPlayer.getPlayerBullets().size(); j++)
        {

            if(currentEnemies.at(i).getSprite().getGlobalBounds().contains(currentPlayer.getPlayerBullets().at(j).getBulletPos()))
            {
                currentPlayer.setBulletInactiveAtPosition(j);
                currentEnemies.at(i).getShot();
            } 

        }
    }
}

void Collisions::checkEnemyBulletsToPlayer(std::vector<Enemy>& currentEnemies, Player& currentPlayer)
{
	 for(auto i = 0u; i != currentEnemies.size(); i++)
    {
          for(auto j = 0u; j != currentEnemies.at(i).getEnemyBullets().size(); j++)
          {
              if(currentPlayer.getSprite().getGlobalBounds().contains(currentEnemies[i].getEnemyBullets()[j].getBulletPos()))
                 {
					 auto tempBullet = currentEnemies[i].getEnemyBullets()[j];
                     currentPlayer.getShot(currentEnemies[i].getEnemyBullets()[j].getBulletDamage());
                     currentEnemies[i].setBulletInactiveAtPosition(j)                ;
                 }
          }
    }
	
}

void Collisions::checkEnemyPositionToPLayer(std::vector<Enemy>& currentEnemies, Player& currentPlayer)
{
	for(auto curEnemy : currentEnemies)
    {
        if(curEnemy.getSprite().getGlobalBounds().contains(currentPlayer.getPlayerPos()))
        {
			if(curEnemy.typeOfEnemy() == EnemyType::TANK) currentPlayer.getShot(10);//Tanks do substantial damage to player
			else currentPlayer.getShot(1);            
        }
    }
}