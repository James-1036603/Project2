#include "Engine.h"

void Engine::update(float& dtAsSeconds)
{
    _thePlayer.updatePlayer(dtAsSeconds);
    _theEnemies.updateEnemies(dtAsSeconds);

	_thePlayer.checkPlayerCollisionss(_theEnemies.theEnemies());
	_theEnemies.checkEnemyCollisions(_thePlayer.theCurrentPlayer());
	_theEnemies.randomEvents(dtAsSeconds);
	


}

void Engine::progressGame()
{
    if(!_thePlayer.playerIsAlive())//if the player is dead, end the game
    {
        _window.close();
        Engine::drawScreen(ScreenType::LOSE);
    }
    if(_theEnemies.allEnemiesKilled() && !_gameLevels.maxLevel())//No more enemies are on the screen
    {
        _gameLevels.nextLevel();
        auto currentLevel = _gameLevels.currentLevel();     
        _theEnemies.spawnEnemies(currentLevel);

    }
    if(_gameLevels.maxLevel())
    {
        _window.close();
        Engine::drawScreen(ScreenType::WIN);
    }
}
