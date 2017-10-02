#include "Engine.h"

Engine::Engine():
    _window(sf::VideoMode(1920,1080),"Game", sf::Style::Default),
    _thePlayer(static_cast<sf::Vector2f>(_window.getSize()), 400, &_bulletManager),
    _bulletManager(),
    _gameLevels()
{
	//Window Settings
    _window.setVerticalSyncEnabled(true);
    _window.setMouseCursorVisible(false);
    _window.setFramerateLimit(60);
	
    Engine::drawSplashScreen();
    if(!_backgroundTexture.loadFromFile("background.png")) throw FileNotFound();//Load background texture)
    _backgroundSprite.setTexture(_backgroundTexture);//Set background texture
    _backgroundSprite.setScale(1.8f,1.6f);
    //Music
    _gameMusic.loadFromFile("theme.wav");
    _gameMusic.play();

    
    //Spawn the enemies
    auto level = _gameLevels.currentLevel();
    _theEnemies.spawnEnemies(level);
}

Engine::~Engine()
{
    //dtor
}

void Engine::start()
{
    //Timing
    std::cout<<"Window getSize: "<<_window.getSize().x<<"\n";
    sf::Clock sysClock;
    while(_window.isOpen())
    {
        sf::Time dt = sysClock.restart();

        float dtAsSeconds = dt.asSeconds();
        input(dtAsSeconds);
        update(dtAsSeconds);
        draw();
        progressGame();//Game will end once the player loses 3 lives
    }
}

void Engine::drawSplashScreen()
{
    sf::RenderWindow splashScreen(sf::VideoMode(1920,1080), "Splash Screen", sf::Style::Default);
	splashScreen.setMouseCursorVisible(false);
    sf::Texture splashImage;
    if(!splashImage.loadFromFile("splashscreen.png")) throw FileNotFound();
    sf::Sprite splashscreenSprite;
    splashscreenSprite.setTexture(splashImage);

    while(splashScreen.isOpen())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) splashScreen.close();
        else
        {
            splashScreen.clear();
            splashScreen.draw(splashscreenSprite);
            splashScreen.display();
        }
    }


}


void Engine::winScreen()
{
    sf::RenderWindow splashScreen(sf::VideoMode(1920,1080), "Win Screen", sf::Style::Default);
    sf::Texture splashImage;
    if(!splashImage.loadFromFile("WinScreen.png")) throw FileNotFound();
    sf::Sprite splashscreenSprite;
    splashscreenSprite.setTexture(splashImage);

    while(splashScreen.isOpen())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) splashScreen.close();
        else
        {
            splashScreen.clear();
            splashScreen.draw(splashscreenSprite);
            splashScreen.display();
        }
    }
}

void Engine::loseScreen()
{
sf::RenderWindow splashScreen(sf::VideoMode(1920,1080), "Lose Screen", sf::Style::Default);
    sf::Texture splashImage;
    if(!splashImage.loadFromFile("LoseScreen.png")) throw FileNotFound();
    sf::Sprite splashscreenSprite;
    splashscreenSprite.setTexture(splashImage);

    while(splashScreen.isOpen())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) splashScreen.close();
        else
        {
            splashScreen.clear();
            splashScreen.draw(splashscreenSprite);
            splashScreen.display();
        }
    }
}
