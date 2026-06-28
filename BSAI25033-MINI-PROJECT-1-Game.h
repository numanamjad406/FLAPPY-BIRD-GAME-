#pragma once
#include "raylib.h"
#include "BSAI25033-MINI-PROJECT-1-Bird.h "
#include "BSAI25033-MINI-PROJECT-1-Pipe.h "

# define PIPE_COUNT 3

class Game
{
      
    enum State { MENU, PLAYING, GAMEOVER };
    Bird bird;
    Pipe pipes[PIPE_COUNT];

    Texture2D bg1;
    Texture2D bg2;
    float bg1X, bg2X;
    int screenWidth;
    int screenHeight;
    int score;
    int level;
    bool level2Unlocked;
public:
 
    State state;
    Game();

    
    

    void startGame(int lvl);
    void update(float dt);
    void draw();
    void input();
};
