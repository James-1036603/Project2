#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include <doctest.h>
#include <SFML/System.hpp>
#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "BulletMovement.h"
#include <iostream>

TEST_CASE("Bullet Initialised Correctly")
{
    std::cout<<"Test 1"<<"\n";
    sf::Vector2f position(500.0f, 500.0f);
    auto speed = 1000.0;
    Bullet bullet1(position, 0, Owner::PLAYER);


    CHECK(bullet1.getBulletPos() == position);
    CHECK(bullet1.getSpeed() == speed);


}

TEST_CASE("Bullet Texture Found")
{
    std::cout<<"Test 2"<<"\n";
    CHECK_NOTHROW(Bullet bullet1(sf::Vector2f(50.0f,50.0f),0, Owner::PLAYER));
}

//Bullet Movement
TEST_CASE("Player Bullet Moved Correct Amount")
{
    std::cout<<"Test 3"<<"\n";
    Bullet bullet1(sf::Vector2f(50.0f,50.0f),0, Owner::PLAYER);
    bullet1.updatePlayerBullet(1);
    CHECK(bullet1.getBulletPos().x == doctest::Approx(-950.0));
    CHECK(bullet1.getBulletPos().y == doctest::Approx(50.0));
}

TEST_CASE("Enemy Bullet Moved Correct Amount")
{
    std::cout<<"Test 4"<<"\n";
Bullet bullet1(sf::Vector2f(50.0f,50.0f),0, Owner::ENEMY);
    bullet1.updateEnemyBullet(1);
    CHECK(bullet1.getBulletPos().x == doctest::Approx(-950.0));
    CHECK(bullet1.getBulletPos().y == doctest::Approx(50.0));

}

//Player Tests

TEST_CASE("Player is initialised correctly")
{
    std::cout<<"Test 5"<<"\n";
    Player player1(sf::Vector2f(1920,1080),400, NULL);
    sf::Vector2f playerStartPos(560,540);
    auto speed = 200.0;

    CHECK(player1.getPlayerPos().x==playerStartPos.x);
    CHECK(player1.getSpeed() == speed);

}

TEST_CASE("Player found correct texture")
{
    std::cout<<"Test 6"<<"\n";
    CHECK_NOTHROW(Player player1(sf::Vector2f(1920,1080),400, NULL));
}


TEST_CASE("Player moves along circular path")
{
    std::cout<<"Test 7"<<"\n";
    Player player1(sf::Vector2f(1920,1080),400, NULL);

    player1.moveRight();
    player1.update(1);


    CHECK(player1.getPlayerPos().x == doctest::Approx(560.0f));
    CHECK(player1.getPlayerPos().y == doctest::Approx(540.637f));

    player1.stopRight();
    player1.moveLeft();
    player1.update(1);


    CHECK(player1.getPlayerPos().x == doctest::Approx(1125.879));
    CHECK(player1.getPlayerPos().y == doctest::Approx(176.016f));

}

TEST_CASE("Player can shoot a bullet")
{
    std::cout<<"Test 8"<<"\n";
    Player player1(sf::Vector2f(1920,1080),400, NULL);
    auto elapsedTime = 1.0f;
    player1.Shoot(elapsedTime);
    std::vector<Bullet> bulletsCur = player1.getPlayerBullets();
    CHECK(bulletsCur.size()==1);
}

//Enemy Tests

TEST_CASE("Scout Enemy is initialised correctly")
{
    std::cout<<"Test 9"<<"\n";
sf::Vector2f displaySize(1920,1080);
sf::Vector2f startingPos(960,540);
Enemy Scout(displaySize, NULL, NULL, EnemyType::SCOUT);
CHECK(Scout.typeOfEnemy() == EnemyType::SCOUT);
CHECK(Scout.getEnemyPos() == startingPos);
CHECK(Scout.getSpeed() == 50);
CHECK(Scout.getDamageForBullet()==1);

}

TEST_CASE("Soldier Enemy is initialised correctly")
{
    std::cout<<"Test 11"<<"\n";
sf::Vector2f displaySize(1920,1080);
sf::Vector2f startingPos(960,540);
Enemy Soldier(displaySize, NULL, NULL, EnemyType::SOLDIER);
CHECK(Soldier.typeOfEnemy() == EnemyType::SOLDIER);
CHECK(Soldier.getEnemyPos() == startingPos);
CHECK(Soldier.getSpeed() == 100);
CHECK(Soldier.getDamageForBullet()==2);
}

TEST_CASE("Rogue Enemy is initialised correctly")
{
    std::cout<<"Test 12"<<"\n";
sf::Vector2f displaySize(1920,1080);
sf::Vector2f startingPos(960,540);
Enemy Rogue(displaySize, NULL, NULL, EnemyType::ROGUE);
CHECK(Rogue.typeOfEnemy() == EnemyType::ROGUE);
CHECK(Rogue.getEnemyPos() == startingPos);
CHECK(Rogue.getSpeed() == 150);
CHECK(Rogue.getDamageForBullet()==3);
}

TEST_CASE("Enemy Can Shoot")
{
    std::cout<<"Test 13"<<"\n";
    sf::Vector2f displaySize(1920,1080);
    Enemy Soldier(displaySize, NULL, NULL, EnemyType::SOLDIER);
    Soldier.setStepsTaken(50);
    Soldier.Shoot();
    std::vector<Bullet> bulletsCur = Soldier.getEnemyBullets();
    CHECK(bulletsCur.size()==1);
}

TEST_CASE("Enemy Soldier Moves Correctly")
{
    sf::Vector2f displaySize(1920,1080);
    Enemy aEnemy(displaySize, NULL, NULL, EnemyType::SCOUT);
    aEnemy.setRotation(60);
    aEnemy.update(1);
    CHECK(aEnemy.getEnemyPos().x == doctest::Approx(978.508));
    CHECK(aEnemy.getEnemyPos().y == doctest::Approx(586.448));
    
}

TEST_CASE("Enemy Soldier moves correctly along path of 60 degrees")
{
    sf::Vector2f displaySize(1920,1080);
    Enemy aEnemy(displaySize, NULL, NULL, EnemyType::SOLDIER);
    aEnemy.setRotation(60);
    aEnemy.update(1);
    CHECK(aEnemy.getEnemyPos().x == doctest::Approx(953.345));
    CHECK(aEnemy.getEnemyPos().y == doctest::Approx(440.202));
}

TEST_CASE("Enemy Rogue moves correctly along path of 60 degrees")
{
    sf::Vector2f displaySize(1920,1080);
    Enemy aEnemy(displaySize, NULL, NULL, EnemyType::ROGUE);
    aEnemy.setRotation(60);
    aEnemy.update(1);
    CHECK(aEnemy.getEnemyPos().x == doctest::Approx(992.590));
    CHECK(aEnemy.getEnemyPos().y == doctest::Approx(393.583));
}

TEST_CASE("Enemy Tank moves correctly")
{
    sf::Vector2f displaySize(1920,1080);
    Enemy aEnemy(displaySize, NULL, NULL, EnemyType::TANK);
    aEnemy.setRotation(60);
    aEnemy.update(1);
    CHECK(aEnemy.getEnemyPos().x == doctest::Approx(1025.790));
    CHECK(aEnemy.getEnemyPos().y == doctest::Approx(576.010));
}


// Player/Enemy interaction

TEST_CASE("Player bullet impacts enemy, enemy takes damage or is killed")
{
    
}

TEST_CASE("Enemy bullet impacts player, player takes damage or is killed")
{
    
}

TEST_CASE("Enemy colliding with player will damage the player")
{
    
}