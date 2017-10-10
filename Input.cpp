#include "Engine.h"

void Engine::input(float& dtAsSeconds)
{
    sf::Event event;
    while(_window.pollEvent(event))
    {
        switch (event.type)//Polling an event does not work well for movement with shooting, but does work well for muting the music, pausing, etc.
        {
        case sf::Event::KeyPressed://If a key was pressed
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) _window.close();//Quit the game

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) _gameMusic.toggleMusic();//Pause the music if M is pressed
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) _thePlayer.playerShoot(dtAsSeconds);
        default:
            break;
        }



    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _thePlayer.movePlayer(MoveDirection::LEFT); //Player moves left
    else _thePlayer.movePlayer(MoveDirection::STOP_LEFT);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _thePlayer.movePlayer(MoveDirection::RIGHT); //Player moves right
    else _thePlayer.movePlayer(MoveDirection::STOP_RIGHT);


}
