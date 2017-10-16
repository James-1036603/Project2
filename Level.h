#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>

class level_FileNotFound{};
/**
 * @class Level
 * @author James Phillips (1036603)
 * @file Level.h
 * @brief The levels for the game as an integer type, up to a certain maximum level
 */

class Level
{
public:
/**
 * @brief Level Constructor
 */

    Level();
/**
 * @brief Level Destructor
 */
	
    virtual ~Level();
/**
 * @brief Return the current level
 */
	
    int currentLevel();
    /**
     * @brief Go to the next Level
     */
    void nextLevel();
    /**
     * @brief Evaluate whether the maximum level has been reached or not
     */
    bool maxLevel();
/**
 * @brief Draw the current level to the current window
 * @param currentWindow
 */
	
    void drawLevelsToWindow(sf::RenderWindow* currentWindow);
private:
    int _currentLevel;
    sf::Font font;
    sf::Text text;

    void setTextAndFont();
    void levelToText();

};

#endif // LEVEL_H
