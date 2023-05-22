#ifndef Player_h
#define Player_h

#include "ofMain.h"
#include "GameObject.h"
class Game;

// TODO add speed settings
#define MAX_SPEED 100

class Player : public GameObject
{
    bool well;
    ofLight faro;
    float speed;
    bool bLight;
    glm::vec3 prevPos;
    int coins;

public:
    Player(Game *game);
    ~Player();

    void init();
    void update() override;
    void draw() override;
    void drawDebug() override;
    void checkCollisions() override;
    float getSpeed();

    void wellFall();
    void loseAllCoins();
    void steerLeft();
    void steerRight();
    void accelerate();
    void toggleLight();
    void shoot();
    void brake();
    void slow();
    void stop();
    void getCrazy();
    void addCoins(int n = 1);
    int getCoins();
};

#endif
