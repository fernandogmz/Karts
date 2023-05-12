//
//  PauseState.cpp

#include "Game.h"
#include "PauseState.hpp"

#include "PlayState.h"

PauseState::PauseState(Game *game): State(game, "Pause State"){
    
};

PauseState::~PauseState(){};

void PauseState::update(){
    
};

void PauseState::draw(){
    ofBackground(127);
    ofDrawBitmapString(name, 10, 20);
};

void PauseState::next(){
    game->setState(new PlayState(game));
};

void PauseState::keyPressed(int key){
    if(key=='p')
        game->setState(new PlayState(game));    //TODO: BACK TO PREVIOUS GAME
}
