#include "Player.h"
#include "Oil.h"

Oil::Oil(Game *game, glm::vec3 pos, glm::vec3 dim, string imgName) : BoxTexture(game, pos, dim, imgName) {}
Oil::~Oil() {}

void Oil::receiveCarCollision(Player *car)
{
    car->getCrazy();
}
