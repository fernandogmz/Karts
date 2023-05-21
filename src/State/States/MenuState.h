#ifndef MenuState_h
#define MenuState_h

#include "State.h"
#include "Game.h"

class MenuState: public State{
public:
    // Fonts
    ofTrueTypeFont gameplayS, gameplayM, gameplayL, gameplayXL;
    
    MenuState(Game *game): State(game, "Menu State"){
        
        // Fonts
        ofTrueTypeFont::setGlobalDpi(72);
        gameplayS.load("BirdyGame.ttf", 24);
        gameplayM.load("BirdyGame.ttf", 48);
        gameplayL.load("BirdyGame.ttf", 72);
        gameplayXL.load("BirdyGame.ttf", 128);
    };
    
    ~MenuState(){};
    
    void update();
    void draw();
    void next();
    void keyPressed(int key);
    
    void drawCenteredText(ofTrueTypeFont font, float y, string text);
    void drawTextXY(ofTrueTypeFont font, float x, float y, string text);
    
        
};
#endif 
