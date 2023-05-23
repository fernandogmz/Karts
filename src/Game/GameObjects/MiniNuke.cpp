
#include "MiniNuke.h"
#include "Game.h"

MiniNuke::MiniNuke(Game *game, ofNode otherTransform)
    : GameObject(game, otherTransform.getGlobalPosition(), glm::vec3(30))
{
    transform.setGlobalOrientation(otherTransform.getGlobalOrientation());
    material.setEmissiveColor(ofColor::darkRed);
    this->currentPosition = 500;
}

MiniNuke::~MiniNuke() {}

void MiniNuke::update()
{
    transform.move(transform.getYAxis() * -5);
    this->currentPosition -= 5;
    if (this->currentPosition == 0)
    {
        kill();
        return;
    }
};

void MiniNuke::draw()
{
    material.begin();
    {
        collider->draw();
    }
    material.end();
};

void MiniNuke::checkCollisions()
{
    vector<GameObject *> collisions = game->getCollisions(this);
    for (auto c : collisions)
    {
        c->receiveBombCollision(this);
    }
}
