#include "Player.h"
#include "Game.h"
#include "Bullet.h"

Player::Player(Game *game) : GameObject(game, glm::vec3(100))
{
    this->well = false;

    material.setDiffuseColor(ofColor::blue);

    faro.setParent(transform);
    faro.setDiffuseColor(ofColor::yellow);
    faro.setSpotlight();
    faro.move(0, 0, 50);
    faro.rotateDeg(-200, 1, 0, 0);
}

Player::~Player() {}

void Player::init()
{
    transform.setPosition(0, 0, 0);
    speed = 0;
    bLight = false;
    if (!this->well)
        coins = 0;
}

void Player::update()
{
    prevPos = transform.getPosition();
    transform.move(transform.getZAxis() * speed);

    if (speed > MAX_SPEED)
        speed = MAX_SPEED;
    if (speed < 0)
        speed = 0;
}

void Player::draw()
{

    faro.draw();
    if (bLight)
        faro.enable();
    else
        faro.disable();

    material.begin();
    {
        collider->draw();
    }
    material.end();
}

void Player::drawDebug()
{
    collider->drawDebug();

    transform.transformGL();
    ofDrawAxis(100);
    transform.restoreTransformGL();
}

void Player::checkCollisions()
{
    vector<GameObject *> collisions = game->getCollisions(this);
    for (auto c : collisions)
    {
        c->receiveCarCollision(this);
    }
}

void Player::steerLeft()
{
    transform.rotateDeg(1, 0, 2, 0);
}
void Player::steerRight()
{
    transform.rotateDeg(-1, 0, 2, 0);
}
void Player::accelerate()
{
    speed += 0.1;
}
void Player::brake()
{
    speed -= 0.1;
}

void Player::slow()
{
    if (speed > 0.6)
    {
        speed -= 0.5;
    }
}

void Player::getCrazy()
{
    for (int i = 0; i < 10; i++)
    {
        this->steerLeft();

        this->steerRight();
        this->steerRight();
        this->steerRight();

        this->steerLeft();
        this->steerLeft();
        this->steerRight();
    }
}

void Player::stop()
{
    speed = 0;
    transform.setPosition(prevPos);
}

void Player::wellFall()
{
    this->well = true;
    this->init();
}

void Player::toggleLight()
{
    bLight = !bLight;
}

float Player::getSpeed()
{
    return speed;
}

void Player::addCoins(int n)
{
    coins += n;
}

void Player::loseAllCoins()
{

    this->coins = 0;
}

int Player::getCoins()
{
    return coins;
}

void Player::shoot(){
    if(coins > 0){
        game->laserSound();
        game->addGameObject(new Bullet(game, transform));
        coins--;
    }
}

void Player::receiveBombCollision(GameObject *bomb)
{
    this->wellFall();
}
