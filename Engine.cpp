#include "Engine.h"

Engine::Engine():
    _window(sf::VideoMode(1920,1080),"Game", sf::Style::Fullscreen),
    _thePlayer(static_cast<sf::Vector2f>(_window.getSize()), 400, &_bulletManager),
    _bulletManager(),
    _gameLevels()
{
	//Window Settings
    _window.setVerticalSyncEnabled(true);
    _window.setMouseCursorVisible(false);
    _window.setFramerateLimit(60);
	
    Engine::drawScreen(ScreenType::SPLASH);//Draw the splashscreen
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

void Engine::drawScreen(ScreenType typeOfScreen)
{
    sf::RenderWindow Screen(sf::VideoMode(1920,1080), "Splash Screen", sf::Style::Default);
	Screen.setMouseCursorVisible(false);
    sf::Texture screenImage;
	switch(typeOfScreen)//Identify the type of image which has to be loaded
	{
		case ScreenType::SPLASH:
			if(!screenImage.loadFromFile("splashscreen.png")) throw FileNotFound();
			break;
		case ScreenType::WIN:
			if(!screenImage.loadFromFile("WinScreen.png")) throw FileNotFound();
			break;
		case ScreenType::LOSE:
			if(!screenImage.loadFromFile("LoseScreen.png")) throw FileNotFound();
	}
    
    sf::Sprite screenSprite;
    screenSprite.setTexture(screenImage);

    while(Screen.isOpen())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X) || sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) Screen.close();
        else
        {
            Screen.clear();
            Screen.draw(screenSprite);
            Screen.display();
        }
    }


}


