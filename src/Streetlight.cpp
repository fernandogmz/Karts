//
//  Streetlight.cpp
//  Karts
//
//  Created by Fernando Gomez on 20/5/23.
//

#include "Streetlight.hpp"
#include "Game.h"

Streetlight::Streetlight(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos, dim){
    
    leftLight.setParent(transform);
    leftLight.setDiffuseColor(ofColor::lightGoldenRodYellow);
    leftLight.setSpotlight();
    leftLight.move(collider->getWidth()/2 - 100, 250, 0);
    leftLight.rotateDeg(-90, 1, 0, 0);
    leftLight.rotateDeg(-45, 0, 0, 1);
    
    rightLight.setParent(transform);
    rightLight.setDiffuseColor(ofColor::lightGoldenRodYellow);
    rightLight.setSpotlight();
    rightLight.move(-collider->getWidth()/2 + 100, 250, 0);
    rightLight.rotateDeg(-90, 1, 0, 0);
    rightLight.rotateDeg(45, 0, 0, 1);
    
    
    
    material.setEmissiveColor(ofColor::lightGreen);
    
}

Streetlight::~Streetlight(){}

void Streetlight::draw(){
    
    leftLight.draw();
    leftLight.enable();
    
    rightLight.draw();
    rightLight.enable();
    
    material.begin();
    {
        transform.transformGL();
        
        ofDrawBox(-collider->getWidth()/2, 150, 0, 50, 300, 50);
        ofDrawBox(-collider->getWidth()/2 + 75, 300, 0, 200, 50, 50);
        
        ofDrawBox(collider->getWidth()/2, 150, 0, 50, 300, 50);
        ofDrawBox(collider->getWidth()/2 - 75, 300, 0, 200, 50, 50);
        
        transform.restoreTransformGL();
    }
    material.end();
}

void Streetlight::drawDebug(){
    collider->drawDebug();
}
