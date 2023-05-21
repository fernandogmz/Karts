#ifndef Soil_h
#define Soil_h

#include "BoxTexture.h"

class Soil : public BoxTexture
{

public:
    Soil(Game *game, glm::vec3 pos, glm::vec3 dim, string imgName);
    ~Soil();

    void receiveCarCollision(Player *car) override;
};
#endif