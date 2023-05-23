//
//  Arch.cpp
//  Karts

#include "Arch.hpp"
#include "Player.h"
#include "Game.h"

Arch::Arch(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos, dim){
    // Fonts
    ofTrueTypeFont::setGlobalDpi(72);
    gameplay128.load("BirdyGame.ttf", 64);
    
    material.setEmissiveColor(ofColor::lightGray);
    
    ofEnableDepthTest();
    ofEnableNormalizedTexCoords();
    ofDisableArbTex();
    
    fbo.allocate(400, 400);
}
Arch::~Arch(){}

void Arch::update(){
    fbo.begin();
    {
        prize = (int) ofRandom(1,200);
        
        for(int i = 0; i < 100; i ++){
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
            //ofDrawCircle(ofRandom(400), ofRandom(400),10);
            
        }
        
        ofSetColor(ofColor::darkRed);
        gameplay128.drawString(ofToString(prize), 100, 200);
        
        
    }
    fbo.end();
    
}

void Arch::draw(){
    
    material.begin();
    {
        fbo.getTexture().bind();
        {
            transform.transformGL();
            
            ofDrawBox(-collider->getWidth()/2,300, 0, 75, 600, 50);
            
            ofDrawBox(collider->getWidth()/2,300, 0, 75, 600, 50);
            
            ofDrawBox(0,500, 0, collider->getWidth(), 200, 50);
            
            transform.restoreTransformGL();
        }
        fbo.getTexture().unbind();
    }
    material.end();
}

void Arch::drawDebug(){
    collider->drawDebug();
}

void  Arch::receiveCarCollision(Player *car){
    if(!prizeGiven){
        game->getPlayer()->addCoins(prize);
        prizeGiven = true;
    }
}

