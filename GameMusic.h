#ifndef GAMEMUSIC_H
#define GAMEMUSIC_H
#include<SFML/Audio.hpp>

class Music_FileNotFound {};
/**
 * @class GameMusic
 * @author James Phillips (1036603)
 * @file GameMusic.h
 * @brief The background music for the game. This class adds for extra functionality than the SFML music library, such as pause
 */

class GameMusic
{
public:
    GameMusic();
    void loadFromFile(char AudioPath[]);//Load audio file from current path
    void play();//Play the music
    void pause();//Pause the music
    void changeVolume(int volume);//Change the current volume
    void toggleMusic();//Switch between playing and pause
    virtual ~GameMusic();

private:
    sf::Music _gameMusic;//Music for the game
};

#endif // GAMEMUSIC_H
