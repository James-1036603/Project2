#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include "GameMusic.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "BulletManager.h"
#include "Level.h"

enum class ScreenType{SPLASH,WIN,LOSE};
class FileNotFound {};

class Engine
{
public:
    Engine();
    virtual ~Engine();
    void start();

private:
    sf::RenderWindow _window;//Regular Window
    sf::Sprite _backgroundSprite;//Sprite for background
    sf::Texture _backgroundTexture;//Background texture
    GameMusic _gameMusic;//Music for the game

    PlayerManager _thePlayer;//Instance for player
    EnemyManager _theEnemies;//Instance of all enemies
    BulletManager _bulletManager;
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
