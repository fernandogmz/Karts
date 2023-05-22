#include "Game.h"
#include "ResultState.h"
#include "PlayState.h"
#include "MenuState.h"

void ResultState::drawCenteredText(ofTrueTypeFont font, float y, string text){
    font.drawString(text, 0.5*(ofGetWidth() - font.stringWidth(text)), y);
}
 
ResultState::ResultState(Game *game): State(game, "Result State"){
    // Fonts
    ofTrueTypeFont::setGlobalDpi(72);
    gameplayS.load("BirdyGame.ttf", 24);
    gameplayM.load("BirdyGame.ttf", 48);
    gameplayL.load("BirdyGame.ttf", 72);
    gameplayXL.load("BirdyGame.ttf", 128);
    
    // Get saved scores
    records.open(ofToDataPath("records.txt"),ofFile::ReadWrite);
    string rawscores = records.readToBuffer().getText();
    records.close();
    records.remove();
    
    stats = game->getSavedState()->getGameStats(); //{{"coins",25},{"time",8.35}};//
    
    cout << stats["coins"] << endl;
    
    scores = ofSplitString(rawscores, "\n",true,true);
    string entry = ofToString(stats["coins"]) + " " + ofToString(stats["time"]) + " " + ofGetTimestampString();
    bool appended = false;
    
    if(scores.size() == 0 ){
        scores.insert(scores.begin(),entry);
        appended = true;
    }else{
        for(int si=0; si < scores.size(); si++){
            vector<string> p = ofSplitString(scores[si], " ");
            if(stats["coins"] > ofToFloat(p[0]) ){
                scores.insert(scores.begin()+si,entry);
                appended = true;
                break;
            }else if(stats["coins"] == ofToFloat(p[0]) && stats["time"] < ofToFloat(p[1])){
                scores.insert(scores.begin()+si,entry);
                appended = true;
                break;
            }
        }
    }
    
    if(scores.size() > 5) scores.pop_back();
    else if(scores.size() < 5 && !appended) scores.insert(scores.end(),entry);
    
    string outraw = "";
    for(string i: scores) outraw+= i + "\n";
    outraw.pop_back();
    
    // Write to file
    ofBuffer out(outraw.c_str(),outraw.size());
    ofBufferToFile(ofToDataPath("records.txt"), out);
    
};

ResultState::~ResultState(){};

void ResultState::update(){
};

void ResultState::draw(){
    float y = 0;
    ofBackground(ofColor::darkSlateGray);
    
    ofSetColor(ofColor::white);
    y = gameplayL.getLineHeight();
    drawCenteredText(gameplayL, y, "FIN DEL JUEGO");
    y += gameplayL.getLineHeight();
    
    ofSetColor(ofColor::white);
    drawCenteredText(gameplayM, y, "Monedas: " + ofToString((int)stats["coins"]));
    y+= gameplayM.getLineHeight();
    
    ofSetColor(ofColor::white);
    drawCenteredText(gameplayM, y, "Tiempo: " + ofToString( roundf(stats["time"]*100)/100 ) + " S");
    y+= gameplayXL.getLineHeight();
    
    ofSetColor(ofColor::lightGreen);
    drawCenteredText(gameplayL, y, "TOP 5");
    y+= gameplayL.getLineHeight();
    
    ofColor colors[] = {ofColor::gold,ofColor::silver,ofColor::sandyBrown,ofColor::white,ofColor::white};
    for(int i=0; i<scores.size(); i++){
        ofSetColor(colors[i]);
        vector<string> tmp = ofSplitString(scores[i], " ");
        drawCenteredText(gameplayS, y, tmp[0] + " monedas en "+tmp[1]+" s  ["+tmp[2]+"]");
        y += gameplayM.getLineHeight();
    }
    
    y+= gameplayL.getLineHeight();
    ofSetColor(ofColor::lightSkyBlue);
    drawCenteredText(gameplayS, y, "(M) MENU PRINCIPAL      (R) REINICIAR PARTIDA");
    y+= gameplayM.getLineHeight();
    
};

void ResultState::next(){
    game->setState(new MenuState(game));
};

void ResultState::keyPressed(int key){
    if(key=='r')
        game->setState(new PlayState(game));
    
    if(key=='m')
        game->setState(new MenuState(game));
}
