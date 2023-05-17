//
//  Barrier.cpp
//  Karts

#include "Barrier.hpp"
#include "Player.h"

Barrier::Barrier(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos, dim){
    this->barrierHeight = dim.y;
    cout << "HEIGHT " << this->barrierHeight << endl;
    material.setEmissiveColor(ofColor::darkRed);
}
Barrier::~Barrier(){}

void Barrier::update(){
    if(movingDown && transform.getY() < barrierHeight*-1){
        movingDown = false;
        speed *= -1;
    }else if(!movingDown && transform.getY() > barrierHeight){
        movingDown = true;
        speed *= -1;
    }
    
    transform.move(transform.getYAxis() * speed);
    
}

void Barrier::draw(){
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
}

void Barrier::receiveCarCollision(Player *car){
    car->stop();
}

void Barrier::receiveBulletCollision(GameObject *bullet){
    bullet->kill();
    kill();
}
