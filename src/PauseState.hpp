//
//  PauseState.hpp

#ifndef PauseState_hpp
#define PauseState_hpp

#include "State.h"

class Game;

class PauseState : public State{
public:
    PauseState(Game *game);
    ~PauseState();
    
    void update();
    void draw();
    void next();
    void keyPressed(int key);
};

#endif /* PauseState_hpp */
