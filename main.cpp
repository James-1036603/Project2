/*! \mainpage Home
 *
 * \section intro_sec Introduction
 *
 * This is a game which is based on Gyruss. You, a player, move around a circular path and shoot the enemies in the center. There are 3 types of enemies, and allmove differently. The blue deal the least damage, and red the most. Random Tanks will spawn, and avoid them! They deal a lot of damage. You win if you survive all 10 levels, and lose if you run out of health.
 *
 */
#include "Engine.h"
using namespace std;

int main()
{
    Engine gameEngine;
	gameEngine.start();    
    return 0;
}
