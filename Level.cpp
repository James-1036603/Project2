#include "Level.h"

Level::Level()
{
    //ctor
    _currentLevel = 1;
    Level::setTextAndFont();
    Level::levelToText();
}

Level::~Level()
{
    //dtor
}

int Level::currentLevel()
{
    return _currentLevel;
}

void Level::nextLevel()
{
    _currentLevel++;
    Level::levelToText();

}

bool Level::maxLevel()
{
    if(_currentLevel>=10) return true;
    else return false;
}

void Level::setTextAndFont()
{
    if(!font.loadFromFile("arial.ttf")) throw level_FileNotFound();//Load font
    //Set text characteristics
    text.setFont(font);
    text.setCharacterSize(24);
    text.setPosition(0,0);
    text.setStyle(sf::Text::Regular);
    //text.setFillColor(sf::Color::Red);
}

void Level::drawLevelsToWindow(sf::RenderWindow* currentWindow)
{
    currentWindow->draw(text);
}

void Level::levelToText()
{
   std::stringstream levelText;//Convert the lives to a string stream (int to string method)
    levelText << _currentLevel;
    text.setString(levelText.str().c_str());//Set the text to level
}
