#include "GameMusic.h"

GameMusic::GameMusic()
{
    //ctor

}

GameMusic::~GameMusic()
{
    //dtor
}

void GameMusic::loadFromFile(char AudioPath[])
{
    if(!_gameMusic.openFromFile(AudioPath)) throw Music_FileNotFound();
}

void GameMusic::play()
{
    _gameMusic.play();
}

void GameMusic::pause()
{
    _gameMusic.pause();
}

void GameMusic::changeVolume(int volume)
{
    _gameMusic.setVolume(volume);
}

void GameMusic::toggleMusic()
{
    if(_gameMusic.getStatus() == sf::Music::Playing) GameMusic::pause();
    else GameMusic::play();
}
