#ifndef GAMEMUSIC_H
#define GAMEMUSIC_H
#include <SFML/Audio.hpp>

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
/**
 * @brief Game Music Constructor
 */

    GameMusic();
/**
 * @brief GameMusic Destructor
 */
	
	virtual ~GameMusic();
/**
 * @brief Load an audio file from the provided path
 * @param AudioPath
 */
	
    void loadFromFile(char AudioPath[]);//Load audio file from current path
/**
 * @brief Start or Play the current sound file
 */
	
    void play();//Play the music
/**
 * @brief Change the volume of the current sound file
 * @param volume
 */

    void changeVolume(int volume);//Change the current volume
/**
 * @brief Toggle the music between play and pause
 */
	
    void toggleMusic();//Switch between playing and pause

private:
    sf::Music _gameMusic;//Music for the game
	void pause();//Pause the music
};

#endif // GAMEMUSIC_H
