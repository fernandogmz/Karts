#include "Coin.h"
#include "Player.h"
#include "Game.h"


Coin::Coin(Game *game, glm::vec3 pos, glm::vec3 dim):
    GameObject(game, pos, dim){
    material.setDiffuseColor(ofColor::yellow);
        
 
    
}
Coin::~Coin(){
    
}


void Coin::update(){
    model.update();
    transform.rotateDeg(10, 0, 1, 0);
}

void Coin::draw(){
   
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
}

void Coin::receiveCarCollision(Player *car){
    car->addCoins(5);
    game->coinSound();
    kill();
}

void Coin::receiveBulletCollision(GameObject *bullet){
    bullet->kill();
    kill();
    game->getPlayer()->addCoins(1000);
}
