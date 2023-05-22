//
//  Crosswalk.hpp
//  Karts

#ifndef Crosswalk_hpp
#define Crosswalk_hpp

#include "GameObject.h"

class Crosswalk : public GameObject{
    
    ofLight light;
    ofPlanePrimitive plane;
public:
    Crosswalk(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Crosswalk();
    
    void draw() override;
    void drawDebug() override;
    
};


#endif /* Crosswalk_hpp */
