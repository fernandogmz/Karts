#ifndef Game_h
#define Game_h

#include "ofMain.h"
#include "StateMachine.h"
#include "GameObjectContainer.h"
#include "GameObjectGenerator.h"

class Player;

class Game : public StateMachine{
    ofEasyCam cam;
    Player *player;
    GameObjectContainer *gameObjects = nullptr;
    GameObjectGenerator *generator  = nullptr;
    bool bDebug;
    bool bPlayerFinish;
    float initTime, accTime=0;
    
    ofSoundPlayer scream, coin, laser;

    
public:
    int ROAD_LENGTH;
    int ROAD_WIDTH;
    
    Game();
    ~Game();
    void init();
    void update();
    void draw();
    void finishGame();
    void toggleDebug();
    bool isFinished();
    void setFinished(bool v);
    
    Player *getPlayer();
    vector<GameObject *> getCollisions(GameObject *gameObject);
    void addGameObject(GameObject *gameobject);
    
    float getEllapsedTime();
    void saveAccTime();
    float getAccTime();
    void doScream();
    void coinSound();
    void laserSound();
    
};
#endif
