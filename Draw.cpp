#include "Engine.h"

void Engine::draw()
{
    _window.clear(sf::Color::Black);
    _window.draw(_backgroundSprite);
	
    //Draw the player
    _thePlayer.drawPlayerToWindow(&_window);

    //Draw the enemy
    _theEnemies.drawEnemies(&_window);
    //_theEnemies.drawEnemyBullets(&_window);

    //Draw the Level
    _gameLevels.drawLevelsToWindow(&_window);

    _window.display();
}
