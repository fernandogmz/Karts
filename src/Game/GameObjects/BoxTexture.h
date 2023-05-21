#ifndef Box_Texture_h
#define Box_Texture_h

#include "GameObject.h"
#include "ofxAssimpModelLoader.h"
class BoxTexture : public GameObject
{
    bool cilinder;

public:
    BoxTexture(Game *game, glm::vec3 pos, glm::vec3 dim, string imgName, bool cilinder = false);
    ~BoxTexture();

    void draw() override;
    ofImage img;
    ofTexture texture;
    ofPlanePrimitive plane;
    ofBoxPrimitive box;
    ofCylinderPrimitive cylinder;
};

#endif
