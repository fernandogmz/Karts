//
//  Streetlight.hpp
//  Karts


#ifndef Streetlight_hpp
#define Streetlight_hpp

#include "GameObject.h"

class Streetlight : public GameObject{
public:
    Streetlight(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Streetlight();
    
    void draw() override;
    void drawDebug() override;
    
    ofLight leftLight;
    ofLight rightLight;
};


#endif /* Streetlight_hpp */
