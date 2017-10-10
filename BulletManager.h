#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H
#include "Bullet.h"
#include <vector>
/**
 * @class BulletManager
 * @author James Phillips (1036603)
 * @file BulletManager.h
 * @brief This class will manage any needed functions of the bullet. In this instance, it removes any inactive bullets
 */

class BulletManager
{
public:
    BulletManager();
    virtual ~BulletManager();
    std::vector<Bullet> deleteInactiveBullets(std::vector<Bullet>* bulletVector);

private:


};

#endif // BULLETMANAGER_H
