
#ifndef MiniNuke_h
#define MiniNuke_h

#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class MiniNuke : public GameObject
{
    float currentPosition;

public:
    MiniNuke(Game *game, ofNode transform);
    ~MiniNuke();

    void update() override;
    void draw() override;
    void checkCollisions() override;
};
#endif
