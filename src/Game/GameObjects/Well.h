#ifndef Well_h
#define Well_h

#include "BoxTexture.h"

class Well : public BoxTexture
{
public:
    Well(Game *game, glm::vec3 pos, glm::vec3 dim, string imgName);
    ~Well();

    void receiveCarCollision(Player *car) override;
};
#endif