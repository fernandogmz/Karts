
#ifndef StateMachine_h
#define StateMachine_h

#include "State.h"

class StateMachine{
    
    State *state = nullptr;
    State *savedState = nullptr;
    
public:
    
    void setState(State *s){
        auto prevState = state;
        state = s;
        if (prevState != nullptr)
            delete prevState;
    }
    
    State *currentState(){
        return state;
    }
    
    State *getSavedState(){
        return savedState;
    }
    
    void saveState(State *s){
        savedState = state;
    }
    
    void saveAndSetState(State *s){
        savedState = state;
        state = s;
    }
    
    void restoreState(){
        if(state != nullptr){
            delete state;
        }
        state = savedState;
    }
};

#endif
