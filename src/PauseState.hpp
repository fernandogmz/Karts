//
//  PauseState.hpp

#ifndef PauseState_hpp
#define PauseState_hpp

#include "State.h"

class Game;

class PauseState : public State{
public:
    // Fonts
    ofTrueTypeFont gameplayS, gameplayM, gameplayL, gameplayXL;
    
    PauseState(Game *game);
    ~PauseState();
    
    void update();
    void draw();
    void next();
    void keyPressed(int key);
    
    void drawCenteredText(ofTrueTypeFont font, float y, string text);
};

#endif /* PauseState_hpp */
