
#include "GameObjectGenerator.h"
#include "Game.h"
#include "Road.h"
#include "Wall.h"
#include "Soil.h"
#include "Oil.h"
#include "Well.h"
#include "Goal.h"
#include "Obstacle.h"
#include "Crane.h"
#include "Coin.h"
#include "Pedestrian.h"
#include "Barrier.hpp"
#include "Crosswalk.hpp"
#include "Arch.hpp"
#include "Streetlight.hpp"

GameObjectGenerator::GameObjectGenerator(Game *game) : game(game) {}

void GameObjectGenerator::generateWorld()
{
    const int W = game->ROAD_WIDTH;
    const int L = game->ROAD_LENGTH;

    const int wallSize = 100;

    ofImage circuito;
    circuito.load("circuito.png");

    int w = circuito.getWidth() / 16;
    int h = circuito.getHeight() / 16;
    circuito.resize(w, h);
    
    // ------------------------------------------------------------------ //
    
    // ROAD //

    glm::vec3 roadPos(0, -50.1, L / 2 - 1000);
    auto road = new Road(game, roadPos, glm::vec3(W, 0, L));

    game->addGameObject(road);

    // --- STREET LIGHTS //
    int streetLightDistance = 1000;
    for (int z = streetLightDistance; z < L; z += streetLightDistance)
    {
        auto streetLight = new Streetlight(game,glm::vec3(0, roadPos.y, z),glm::vec3(W, 100, 100));
        game->addGameObject(streetLight);
    }

    // --- WALLS //

    auto wall_r = new Wall(game,glm::vec3(-W / 2, roadPos.y, roadPos.z),glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_r);

    wall_r = new Wall(game,glm::vec3(-W / 2, roadPos.y, roadPos.z - L * 0.8),glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_r);

    auto wall_l = new Wall(game,glm::vec3(W / 2, roadPos.y, roadPos.z),glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_l);

    wall_l = new Wall(game,glm::vec3(W / 2, roadPos.y, roadPos.z - L * 0.8),glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_l);
    
    // CROSSWALK //

    auto crosswalk = new Crosswalk(game,glm::vec3(0, roadPos.y + 0.1, 0), glm::vec3(50, 150, 50));
    game->addGameObject(crosswalk);
    
    // ------------------------------------------------------------------ //
    
    // SOIL x 2
    auto soil = new Soil(game, glm::vec3(-W/4, roadPos.y + 0.1, 2500), glm::vec3(350, 2, 350), "rusty.jpg");
    game->addGameObject(soil);
    soil = new Soil(game, glm::vec3(W/4, roadPos.y + 0.1, 2500), glm::vec3(350, 2, 350), "rusty.jpg");
    game->addGameObject(soil);
    
    // OIL x 1
    auto oil = new Oil(game, glm::vec3(0, roadPos.y + 0.1, 4500), glm::vec3(600, 2, 300), "oil.jpeg");
    game->addGameObject(oil);
    
    // WELL x 1
    auto well = new Well(game,glm::vec3(0, roadPos.y + 0.1, 4800), glm::vec3(300, 1, 300), "rusty.jpg");
    game->addGameObject(well);
    
    // ------------------------------------------------------------------ //
    
    // CRAZY ARCH x 1
    auto arch = new Arch(game, glm::vec3(0, roadPos.y, 6800 ), glm::vec3(W, 100, 100));
    arch->isFixed = true;
    game->addGameObject(arch);
    
    // ------------------------------------------------------------------ //
    
    // CRANE x 2
    auto crane = new Crane(game, glm::vec3(0, roadPos.y, 9000), glm::vec3(200, 200, 400));
    game->addGameObject(crane);
    
    crane = new Crane(game, glm::vec3(0, roadPos.y, 11000), glm::vec3(200, 200, 400));
    game->addGameObject(crane);
    
    // OBSTACLES x N
    for(float z=7500; z < 13000; z+=600){
        auto obstacle = new Obstacle(game, glm::vec3(-W/2 + ofRandom(W-200), roadPos.y, z), glm::vec3(100, 100, 200), "rusty.jpg");
        game->addGameObject(obstacle);
    }
    
    // ------------------------------------------------------------------ //

    // BARRIER x 1

    auto barrier = new Barrier(game, glm::vec3(0, roadPos.y, 12500), glm::vec3(W, wallSize * 2, wallSize));
    game->addGameObject(barrier);
    
    // ------------------------------------------------------------------ //
    
    // CROSSWALK x 1
    crosswalk = new Crosswalk(game,glm::vec3(0, roadPos.y + 0.1, 13500), glm::vec3(50, 150, 50));
    game->addGameObject(crosswalk);

    // PEDESTRIAN x 1
    auto pedestrian = new Pedestrian(game,glm::vec3(W / 2 - 100, -25, 13500), glm::vec3(50, 150, 50));
    game->addGameObject(pedestrian);
    
    // SOIL x 1
    soil = new Soil(game, glm::vec3(-W/2 + ofRandom(W - 350), roadPos.y + 0.1, 15000), glm::vec3(350, 2, 350), "rusty.jpg");
    game->addGameObject(soil);
    
    // OIL x 2
    oil = new Oil(game, glm::vec3(ofRandom(W/2), roadPos.y + 0.1, 16200), glm::vec3(600, 2, 300), "oil.jpeg");
    game->addGameObject(oil);
    
    oil = new Oil(game, glm::vec3(-ofRandom(W/2), roadPos.y + 0.1, 17200), glm::vec3(600, 2, 300), "oil.jpeg");
    game->addGameObject(oil);
    
    // WELL x 1
    well = new Well(game,glm::vec3(-W/2 + ofRandom(W - 300), roadPos.y + 0.1, 18500), glm::vec3(300, 1, 300), "rusty.jpg");
    game->addGameObject(well);
    

    // ------------------------------------------------------------------ //
    
    // GOAL //
    auto goal = new Goal(game,glm::vec3(0, roadPos.y, roadPos.z + L / 2),glm::vec3(W, 100, 100));
    goal->isFixed = true;
    game->addGameObject(goal);

    // ------------------------------------------------------------------ //

    // COINS //

    int coinDistance = 1000;
    for (int z = coinDistance; z < L - 500; z += coinDistance)
    {
        int x = (int)ofRandom(2 * wallSize, W - 2 * wallSize);
        auto coin = new Coin(game,glm::vec3(-W / 2 + x, -25, z), glm::vec3(50));
        game->addGameObject(coin);
    }

    
}
