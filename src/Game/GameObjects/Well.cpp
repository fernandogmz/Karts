#include "Player.h"
#include "Well.h"

Well::Well(Game *game, glm::vec3 pos, glm::vec3 dim, string imgName) : BoxTexture(game, pos, dim, imgName, true) {}
Well::~Well() {}

void Well::receiveCarCollision(Player *car)
{
    car->wellFall();
}
