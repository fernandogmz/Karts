#include "PlayState.h"
#include "MenuState.h"
#include "Coin.h"

void MenuState::drawCenteredText(ofTrueTypeFont font, float y, string text){
    font.drawString(text, 0.5*(ofGetWidth() - font.stringWidth(text)), y);
}

void MenuState::drawTextXY(ofTrueTypeFont font, float x, float y, string text){
    font.drawString(text, x, y);
}

void MenuState::update(){
};
    
void MenuState::draw(){
    //ofDrawBitmapString(name, 10, 20);
    ofBackground(ofColor::darkSlateBlue);
    
    float x = 50;
    float y = gameplayL.getLineHeight();
    
    // TITLE
    ofSetColor(ofColor::lightSkyBlue);
    drawCenteredText(gameplayL, y, "MENU PRINCIPAL");
    
    
    // LEFT PANEL
    y = 2* gameplayL.getLineHeight();
    ofSetColor(ofColor::lightGreen);
    drawTextXY(gameplayM,x, y, "OBJETIVO");
    y += 2*gameplayM.getLineHeight();
    
    ofSetColor(ofColor::silver);
    string goal[] = {
        "Conducir el coche por toda la pista hasta",
        "la linea de meta evitando los obstáculos.",
    };
    for(string t: goal){
        drawTextXY(gameplayS, x, y, t);
        y+= 2*gameplayS.getLineHeight();
    }
    
    ofSetColor(ofColor::lightGreen);
    y+= gameplayM.getLineHeight();
    drawTextXY(gameplayM,x, y, "CONTROLES");
    y+= gameplayM.getLineHeight();
    
    string controls[] = {
        "LEFT & RIGHT: direccion hacia los lados",
        "UP: aumentar velocidad",
        "DOWN: reducir velocidad",
        "L: Encender/Apagar luz del coche",
        "SPACE: Disparar ( 1 moneda por bala )"
    };
    for(string t: controls){
        x = 50;
        auto delimiter = t.find(":");
        
        string key = t.substr(0,delimiter+1);
        ofSetColor(ofColor::lightSkyBlue);
        drawTextXY(gameplayS, x, y, key);
        
        x += gameplayS.stringWidth(key);
        
        string action = t.substr(delimiter+1);
        ofSetColor(ofColor::silver);
        drawTextXY(gameplayS, x, y, action);
        
        y+= 2*gameplayS.getLineHeight();
    }
    
    // RIGHT PANEL
    x = ofGetWidth() * 0.5 + 50;
    y = 2* gameplayL.getLineHeight();
    
    ofSetColor(ofColor::lightGreen);
    drawTextXY(gameplayM,x, y, "PUNTAJE");
    y += gameplayM.getLineHeight();
    
    ofSetColor(ofColor::silver);
    string score[] = {
        "Llega a la meta en el menor tiempo posible",
        "recogiendo las monedas por el camino. Cada",
        "bloque de monedas vale por cinco."
    };
    for(string t: score){
        drawTextXY(gameplayS, x, y, t);
        y+= 2*gameplayS.getLineHeight();
    }
    
    ofSetColor(ofColor::lightGreen);
    y+= gameplayM.getLineHeight();
    drawTextXY(gameplayM,x, y, "OBSTÁCULOS");
    y+= gameplayM.getLineHeight();
    
    string obstacles[] = {
        "TIERRA: Reduce tu velocidad",
        "ACEITE: Cambia tu dirección",
        "PEATÓN: Ganas 100 monedas",
        "ARCO: Bonus de monedas",
        "POZO: Vuelves al inicio",
        "BARRERA: Te detendrás. Dispárale.",
    };
    for(string t: obstacles){
        x = ofGetWidth() * 0.5 + 50;
        auto delimiter = t.find(":");
        
        string key = t.substr(0,delimiter+1);
        ofSetColor(ofColor::lightSkyBlue);
        drawTextXY(gameplayS, x, y, key);
        
        x += gameplayS.stringWidth(key);
        
        string action = t.substr(delimiter+1);
        ofSetColor(ofColor::silver);
        drawTextXY(gameplayS, x, y, action);
        
        //drawTextXY(gameplay16, x, y, t);
        
        y+= 2*gameplayS.getLineHeight();
    }
    
    if( (int)ofGetElapsedTimef() % 2 == 0){
        ofSetColor(ofColor::lightGreen);
        drawCenteredText(gameplayS, ofGetHeight()-gameplayS.getLineHeight(), "Presiona 'S' para iniciar");
    }
    
};

void MenuState::next(){
    game->setState(new PlayState(game));
};

void MenuState::keyPressed(int key){
    if(key == 's'){
        next();
    }
}
