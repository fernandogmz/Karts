//
//  Barrier.hpp
//  Karts

#ifndef Barrier_hpp
#define Barrier_hpp

#include "GameObject.h"

class Barrier : public GameObject{
    
    
public:
    float barrierHeight;
    float speed = -1;
    bool movingDown = true;
    
    Barrier(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Barrier();
    
    void update() override;
    void draw() override;
    void receiveCarCollision(Player *car) override;
    void receiveBulletCollision(GameObject *bullet) override;
};


#endif /* Barrier_hpp */
