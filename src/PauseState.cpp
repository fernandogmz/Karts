//
//  PauseState.cpp

#include "Game.h"
#include "PauseState.hpp"
#include "MenuState.h"
#include "PlayState.h"

void PauseState::drawCenteredText(ofTrueTypeFont font, float y, string text){
    font.drawString(text, 0.5*(ofGetWidth() - font.stringWidth(text)), y);
}

PauseState::PauseState(Game *game): State(game, "Pause State"){
    // Fonts
    ofTrueTypeFont::setGlobalDpi(72);
    gameplayS.load("BirdyGame.ttf", 24);
    gameplayM.load("BirdyGame.ttf", 48);
    gameplayL.load("BirdyGame.ttf", 72);
    gameplayXL.load("BirdyGame.ttf", 128);
};

PauseState::~PauseState(){};

void PauseState::update(){
    
};

void PauseState::draw(){
    float y = 0;
    ofBackground(ofColor::darkSlateGray);
    
    ofSetColor(ofColor::lightCoral);
    y = gameplayXL.getLineHeight();
    drawCenteredText(gameplayXL, y, "JUEGO PAUSADO");
    y += gameplayXL.getLineHeight();
    
    // STATS
    std::map<string,float> stats = game->getSavedState()->getGameStats();
    
    ofSetColor(ofColor::goldenRod);
    drawCenteredText(gameplayM, y, "COINS: " + ofToString((int)stats["coins"]));
    y+= gameplayL.getLineHeight();
    
    
    ofSetColor(ofColor::deepSkyBlue);
    drawCenteredText(gameplayM, y, "TIME: " + ofToString( roundf(stats["time"]*100)/100 ) + " S");
    y+= gameplayXL.getLineHeight();
    
    
    // CONTINUAR
    ofSetColor(ofColor::lightSkyBlue);
    drawCenteredText(gameplayM, y, "CONTINUAR JUGANDO");
    y+= gameplayM.getLineHeight();
    
    ofSetColor(ofColor::silver);
    drawCenteredText(gameplayS, y, "PRESIONA 'P'");
    y += gameplayM.getLineHeight();
    
    // REINICIAR
    ofSetColor(ofColor::lightSkyBlue);
    drawCenteredText(gameplayM, y, "REINICIAR PARTIDA");
    y+= gameplayM.getLineHeight();
    
    ofSetColor(ofColor::silver);
    drawCenteredText(gameplayS, y, "PRESIONA 'R'");
    y += gameplayM.getLineHeight();
    
    // SALIR AL MENU
    ofSetColor(ofColor::lightSkyBlue);
    drawCenteredText(gameplayM, y, "SALIR AL MENU PRINCIPAL");
    y+= gameplayM.getLineHeight();
    
    ofSetColor(ofColor::silver);
    drawCenteredText(gameplayS, y, "PRESIONA 'S'");
    y += gameplayM.getLineHeight();
    
    
    
    
    
    
    
    
    
    
};

void PauseState::next(){
    game->setState(new PlayState(game));
};

void PauseState::keyPressed(int key){
    if(key=='p'){
        game->restoreState();
        ofResetElapsedTimeCounter();
    }
    
    if(key=='r')
        game->setState(new PlayState(game));
    
    if(key=='s')
        game->setState(new MenuState(game));
}
