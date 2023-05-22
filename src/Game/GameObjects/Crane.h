
#ifndef Crane_h
#define Crane_h

#include "GameObject.h"

#include "ofxAssimpModelLoader.h"

class Crane : public GameObject
{
    ofNode palaNode;
    float angle, initialPalaY;

public:
    Crane(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Crane();

    void update() override;
    void draw() override;
    void receiveCarCollision(Player *car) override;
    ofxAssimpModelLoader craneModel;
    float getPalaYOffset();
};

#endif /* Person_h */
