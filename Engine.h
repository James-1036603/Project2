#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include "GameMusic.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "Level.h"
/** An enum for the type of splash screen to be displayed
 */
enum class ScreenType{SPLASH,WIN,LOSE};
/**
 * @class FileNotFound
 * @file Engine.h
 * @brief File Not Found for engine. Used in error catching
 */

class FileNotFound {};
/**
 * @class Engine
 * @author James Phillips (1036603)
 * @file Engine.h
 * @brief The engine is an instance of the game itself. The engine is the interface to the player, with the play window and player input
 */

class Engine
{
public:
/**
 * @brief Engine Constructor
 */
	
    Engine();
/**
 * @brief Engine Destructor
 */
	
    virtual ~Engine();
/**
 * @brief Start the current engine, ie start the game
 */
	
    void start();

private:
    sf::RenderWindow _window;//Regular Window
    sf::Sprite _backgroundSprite;//Sprite for background
    sf::Texture _backgroundTexture;//Background texture
    GameMusic _gameMusic;//Music for the game

    PlayerManager _thePlayer;//Instance for player
    EnemyManager _theEnemies;//Instance of all enemies
    Level _gameLevels;

    const int _height = sf::VideoMode::getDesktopMode().height;
    const int _width = sf::VideoMode::getDesktopMode().width;

    void drawScreen(ScreenType typeOfScreen);
   
    void input(float& dtAsSeconds);
    void update(float& dtAsSeconds);
    void draw();
    void progressGame();//Conditions for the next level, or game to end
};

#endif // ENGINE_H
