#include "Player.h"
#include "GameObject.h"
#include "Obstacle.h"
#include <iostream>

Obstacle::Obstacle(Game *game, glm::vec3 pos, glm::vec3 dim, string imgName) : BoxTexture(game, pos, dim, imgName) {}
Obstacle::~Obstacle() {}

void Obstacle::receiveCarCollision(Player *car)
{
    car->stop();
}
void Obstacle::receiveBulletCollision(GameObject *bullet)
{
    cout << "llego";
    try
    {
        bullet->kill();
        kill();
        cout << this->bAlive << "holaa";
    }
    catch (...)
    {
        cout << "Se produjo una excepción: ";
    }
}