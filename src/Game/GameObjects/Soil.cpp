#include "Soil.h"
#include "Player.h"
#include "Pedestrian.h"

Soil::Soil(Game *game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim)
{
    model.loadModel("astroBoy_walk.dae");

    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(0, -25, 0);
    model.setScale(0.25, 0.25, 0.25);
    transform.rotateDeg(90, 0, 1, 0);
}
Soil::~Soil() {}

void Soil::draw()
{
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}

void Soil::receiveCarCollision(Player *car)
{
    car->slow();
}
