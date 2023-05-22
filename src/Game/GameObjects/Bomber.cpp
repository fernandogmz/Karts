

#include "Bomber.h"
#include "Game.h"
#include "MiniNuke.h"

Bomber::Bomber(Game *game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim)
{
    bomberModel.loadModel("bomber.obj");

    bomberModel.setRotation(0, 180, 1, 0, 0);
    bomberModel.setScale(0.5, 0.5, 0.5);

    transform.rotateDeg(90, 0, 1, 0);
    speed = 10;
    width = game->ROAD_WIDTH;
}
Bomber::~Bomber()
{
}

void Bomber::update()
{
    bomberModel.update();
    this->curentPosition += speed;
    if (this->curentPosition >= this->width)
    {
        turn();
    }
    transform.move(transform.getZAxis() * -speed);
    if (int(this->curentPosition) % 500 == 0)
        game->addGameObject(new MiniNuke(game, transform));
};
void Bomber::draw()
{
    transform.transformGL();
    bomberModel.drawFaces();
    transform.restoreTransformGL();
};

void Bomber::turn()
{
    transform.rotateDeg(180, 0, 1, 0);
    transform.move(transform.getZAxis() * -speed);
    this->curentPosition = 0;
}
