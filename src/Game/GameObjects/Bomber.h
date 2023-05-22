
#ifndef Bomber_h
#define Bomber_h

#include "GameObject.h"

#include "ofxAssimpModelLoader.h"

class Bomber : public GameObject
{
    float speed = 10, curentPosition;
    int width;

public:
    Bomber(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Bomber();

    void update() override;
    void draw() override;
    void turn();
    ofxAssimpModelLoader bomberModel;
};

#endif
