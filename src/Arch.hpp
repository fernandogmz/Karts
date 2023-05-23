//
//  Arch.hpp
//  Karts

#ifndef Arch_hpp
#define Arch_hpp

#include "GameObject.h"

class Arch : public GameObject{
    
    
public:
    Arch(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Arch();
    
    void update() override;
    void draw() override;
    void drawDebug() override;
    void receiveCarCollision(Player *car) override;
    
    ofFbo fbo;
    int prize;
    bool prizeGiven = false;
    
    
    // Fonts
    ofTrueTypeFont gameplay128;
    
};

#endif /* Arch_hpp */
