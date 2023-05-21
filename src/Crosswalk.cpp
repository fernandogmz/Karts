//
//  Crosswalk.cpp
//  Karts

#include "Crosswalk.hpp"
#include "Game.h"

Crosswalk::Crosswalk(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos){
    
    material.setDiffuseColor(ofColor::lightSeaGreen);
    plane.setParent(transform);
    transform.rotateDeg(-90, 1, 0, 0);
    plane.set(game->ROAD_WIDTH, 200);
    
    light.setPosition(0, 0, pos.z);
    light.setDiffuseColor(ofColor::white);
}
Crosswalk::~Crosswalk(){}

void Crosswalk::draw(){
    
    //light.enable();
    material.begin();
    {
        plane.draw();
    }
    material.end();
}


void Crosswalk::drawDebug(){
    plane.drawWireframe();
}


