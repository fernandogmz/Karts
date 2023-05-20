#include "Player.h"
#include "Soil.h"
Soil::Soil(Game *game, glm::vec3 pos, glm::vec3 dim, string imgName) : BoxTexture(game, pos, dim, imgName) {}
Soil::~Soil() {}

void Soil::receiveCarCollision(Player *car)
{
    car->slow();
}
