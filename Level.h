#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include <sstream>

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
    Level();
    virtual ~Level();
    int currentLevel();
    void nextLevel();
    bool maxLevel();
    void drawLevelsToWindow(sf::RenderWindow* currentWindow);
private:
    int _currentLevel;
    sf::Font font;
    sf::Text text;

    void setTextAndFont();
    void levelToText();

};

#endif // LEVEL_H
