/*
 *  PlayState_Solution.h
 *  Bruno Brandelli, Renata Bueno, Yago Vieira
 *
 */

#ifndef PLAY_STATE_H_
#define PLAY_STATE_H_

#include "GameState.h"
#include "Sprite.h"
#include "InputManager.h"
#include <tmx/MapLoader.h>
#include <string>

class PlayState : public cgf::GameState
{
    public:

    void init();
    void cleanup();

    void pause();
    void resume();

    void handleEvents(cgf::Game* game);
    void update(cgf::Game* game);
    void draw(cgf::Game* game);
    void createObjectives();
    void reachedObjective();
    void createEnemies();
    void checkEnemyWallColision(cgf::Game* game);
    void checkPlayerEnemyColision();
    bool finishedLevel();

    // Implement Singleton Pattern
    static PlayState* instance()
    {
        return &m_PlayState;
    }

    protected:

    PlayState() {}

    private:

    static PlayState m_PlayState;

    enum { RIGHT=0, LEFT, UP, DOWN };
    std::string walkStates[4];
    int currentDir;

    int dirx, diry;

    cgf::Sprite player;
    cgf::Sprite enemy[5];
    cgf::Sprite star[5];
    bool bStar[5];
    int starPosition[5];

    int level = 1;
    int enemySpeed = 50;


    sf::RenderWindow* screen;
    cgf::InputManager* im;

    tmx::MapLoader* map;

    sf::Font font;
    sf::Text text;

    // Checks collision between a sprite and a map layer
    bool checkCollision(uint8_t layer, cgf::Game* game, cgf::Sprite* obj);

    // get a cell GID from the map (x and y in world coords)
    sf::Uint16 getCellFromMap(uint8_t layernum, float x, float y);
};

#endif
