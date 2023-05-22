#include "Crane.h"
#include "Player.h"
#include "Game.h"

Crane::Crane(Game *game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim)
{

    craneModel.loadModel("Excavator.3ds");
    collider->move(0, 100, 55);
    craneModel.setRotation(0, 180, 1, 0, 0);

    craneModel.setScale(0.75, 0.75, 0.75);
}
Crane::~Crane() {}

void Crane::update()
{
    transform.rotateDeg(1.0f, 0, 1, 0);
};
void Crane::draw()
{
    transform.transformGL();
    craneModel.drawFaces();
    transform.restoreTransformGL();
};
void Crane::receiveCarCollision(Player *car)
{
    game->getPlayer()->loseAllCoins();
};
