#ifndef Oil_h
#define Oil_h

#include "BoxTexture.h"

class Oil : public BoxTexture
{
public:
    Oil(Game *game, glm::vec3 pos, glm::vec3 dim, string imgName);
    ~Oil();

    void receiveCarCollision(Player *car) override;
};
#endif