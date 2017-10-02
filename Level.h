#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include <sstream>

class level_FileNotFound{};
class Level
{
public:
    Level();
    virtual ~Level();
    int currentLevel();//What is the current level?
    void nextLevel();//Get the next level
    bool maxLevel();//Maximum amount of levels reached
    void drawLevelsToWindow(sf::RenderWindow* currentWindow);
private:
    int _currentLevel;
    sf::Font font;
    sf::Text text;

    void setTextAndFont();
    void levelToText();

};

#endif // LEVEL_H
