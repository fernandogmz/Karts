#ifndef Well_h
#define Well_h

#include "GameObject.h"
#include "ofxAssimpModelLoader.h"
class Soil : public GameObject
{

public:
    Soil(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Soil();

    void draw() override;
    void receiveCarCollision(Player *car) override;
    ofxAssimpModelLoader model;
};

#endif
