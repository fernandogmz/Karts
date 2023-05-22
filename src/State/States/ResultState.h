#ifndef ResultState_h
#define ResultState_h

#include "State.h"
class Game;

class ResultState: public State{
public:
    // Fonts
    ofTrueTypeFont gameplayS, gameplayM, gameplayL, gameplayXL;
    void drawCenteredText(ofTrueTypeFont font, float y, string text);
    
    ResultState(Game *game);
    
    ~ResultState();
    
    void update();
    void draw();
    void next();
    void keyPressed(int key);
    
    ofFile records;
    map<string,float> stats;
    vector<string> scores;
        
};

#endif /* ResultState_h */
