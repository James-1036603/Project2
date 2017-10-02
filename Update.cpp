#include "Engine.h"

void Engine::update(float& dtAsSeconds)
{
    _thePlayer.updatePlayer(dtAsSeconds);
    _theEnemies.updateEnemies(dtAsSeconds);

    _thePlayer.checkPlayerBulletsToEnemy(_theEnemies.theEnemies());
    _theEnemies.checkEnemyBulletsToPlayer(_thePlayer.theCurrentPlayer());
    _thePlayer.checkEnemyPositionToPlayer(_theEnemies.theEnemies());


}

void Engine::progressGame()
{
    if(!_thePlayer.playerIsAlive())//if the player is dead, end the game
    {
        _window.close();
        Engine::loseScreen();
    }
    if(_theEnemies.allEnemiesKilled())//No more enemies are on the screen
    {
        _gameLevels.nextLevel();
        auto currentLevel = _gameLevels.currentLevel();//spawn enemies was giving problems if not implemented this way
        std::cout<<currentLevel<<'\n';
        _theEnemies.spawnEnemies(currentLevel);

    }
    if(_gameLevels.maxLevel())
    {
        _window.close();
        Engine::winScreen();
    }
}
