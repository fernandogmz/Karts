#ifndef Obstacle_h
#define Obstacle_h

#include "BoxTexture.h"

class Obstacle : public BoxTexture
{
public:
    Obstacle(Game *game, glm::vec3 pos, glm::vec3 dim, string imgName);
    ~Obstacle();

    void receiveCarCollision(Player *car) override;
    void receiveBulletCollision(GameObject *bullet) override;
};
#endif