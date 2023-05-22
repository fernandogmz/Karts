#include "PlayState.h"
#include "PauseState.hpp"
#include "ResultState.h"
#include "Player.h"
#include <map>

PlayState::PlayState(Game *game): State(game, "Play State"){
    game->init();
};

void PlayState::update(){
    game->update();
    
    if(ofGetKeyPressed(OF_KEY_LEFT))
        game->getPlayer()->steerLeft();
    if(ofGetKeyPressed(OF_KEY_RIGHT))
        game->getPlayer()->steerRight();
    if(ofGetKeyPressed(OF_KEY_UP))
        game->getPlayer()->accelerate();
    if(ofGetKeyPressed(OF_KEY_DOWN))
        game->getPlayer()->brake();
};
    
void PlayState::draw(){
    ofBackground(0);
    ofSetColor(ofColor::white);
    ofPushMatrix();
    {
        ofTranslate(10, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString("Fps: " + ofToString(ofGetFrameRate()), 0, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString(name, 0, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString("Time: " + ofToString(game->getEllapsedTime(), 2), 0, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString("Speed: " + ofToString(game->getPlayer()->getSpeed(), 2), 0, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString("Coins: " + ofToString(game->getPlayer()->getCoins(), 2), 0, 0);

    }
    ofPopMatrix();
    game->draw();
};

void PlayState::next(){
    game->setState(new ResultState(game));
};


void PlayState::keyPressed(int key){
    if(key == 'l')
        game->getPlayer()->toggleLight();
    if(key == 'd')
        game->toggleDebug();
    if(key == ' ')
        game->getPlayer()->shoot();
    if(key=='p'){
        game->saveAccTime();
        game->saveAndSetState(new PauseState(game));
    }
}

std::map<string,float> PlayState::getGameStats(){
    std::map<string,float> stats;
    stats["coins"] = (float)game->getPlayer()->getCoins();
    stats["time"] = game->getAccTime();
    
    return stats;
}
