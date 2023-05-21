
#include "GameObjectGenerator.h"
#include "Game.h"
#include "Road.h"
#include "Wall.h"
#include "Soil.h"
#include "Oil.h"
#include "Well.h"
#include "Goal.h"
#include "Coin.h"
#include "Pedestrian.h"
#include "Barrier.hpp"
#include "Crosswalk.hpp"
#include "Arch.hpp"
#include "Streetlight.hpp"

GameObjectGenerator::GameObjectGenerator(Game *game) : game(game) {}

void GameObjectGenerator::generateWorld(){
    const int W = game->ROAD_WIDTH;
    const int L = game->ROAD_LENGTH;
    
    const int wallSize = 100;
    
    ofImage circuito;
    circuito.load("circuito.png");

    int w = circuito.getWidth() / 16;
    int h = circuito.getHeight() / 16;
    circuito.resize(w, h);
    
    // ROAD //
    
    glm::vec3 roadPos(0, -50.1, L/2 - 1000);
    auto road = new Road(game, roadPos, glm::vec3(W, 0, L));
    
    game->addGameObject(road);
    
    int streetLightDistance = 1000;
    for(int z=streetLightDistance; z < L; z+=streetLightDistance){
        auto streetLight = new Streetlight(game,
                        glm::vec3(0, roadPos.y, z),
                               glm::vec3(W, 100, 100));
        game->addGameObject(streetLight);
    }
    
    // WALLS //

    auto wall_r = new Wall(game,
                           glm::vec3(-W / 2, roadPos.y, roadPos.z),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_r);

    wall_r = new Wall(game,
                      glm::vec3(-W / 2, roadPos.y, roadPos.z - L * 0.8),
                      glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_r);

    auto wall_l = new Wall(game,
                           glm::vec3(W / 2, roadPos.y, roadPos.z),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_l);

    wall_l = new Wall(game,
                      glm::vec3(W / 2, roadPos.y, roadPos.z - L * 0.8),
                      glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_l);

    // BARRIER //
    
    auto barrier = new Barrier(game,
                            glm::vec3(0,roadPos.y,roadPos.z),
                            glm::vec3(W,wallSize*2,wallSize));
    game->addGameObject(barrier);
    
    // GOAL //

    auto goal = new Goal(game,
                         glm::vec3(0, roadPos.y, roadPos.z + L / 2),
                         glm::vec3(W, 100, 100));
    goal->isFixed = true;
    game->addGameObject(goal);

    auto soil = new Soil(game,
                         glm::vec3(0, -25, 1000), glm::vec3(100, 2, 100), "rusty.jpg");
    game->addGameObject(soil);

    auto oil = new Oil(game,
                       glm::vec3(50, -25, 2000), glm::vec3(100, 2, 200), "oil.jpeg");
    game->addGameObject(oil);

    auto well = new Well(game,
                         glm::vec3(-50, -25, 2500), glm::vec3(100, 20, 200), "rusty.jpg");
    game->addGameObject(well);
  
    auto arch = new Arch(game,
                         glm::vec3(0,roadPos.y, roadPos.z + 200),
                         glm::vec3(W,100,100));
    arch->isFixed = true;
    game->addGameObject(arch);
  
    // COINS //
    
    int coinDistance = 1500;
    for(int z=coinDistance; z < L; z+=coinDistance){
        int x = (int) ofRandom(2*wallSize,W - 2*wallSize);
        auto coin = new Coin(game,
            glm::vec3(-W/2 + x, -25, z), glm::vec3(50));
        game->addGameObject(coin);
    }
    
    // CROSSWALK //
    
    auto crosswalk = new Crosswalk(game,
       glm::vec3(0, roadPos.y+0.1, 500), glm::vec3(50, 150, 50));

    game->addGameObject(crosswalk);
    
    // PEDESTRIAN //
    
    auto pedestrian = new Pedestrian(game,
                                     glm::vec3(W / 2 - 100, -25, 500), glm::vec3(50, 150, 50));

    game->addGameObject(pedestrian);
}
