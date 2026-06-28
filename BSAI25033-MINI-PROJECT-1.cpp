
#include "BSAI25033-MINI-PROJECT-1-Game.h"

const int SCREEN_WIDTH = 1590;
const int SCREEN_HEIGHT = 890;
# define PIPE_COUNT  3

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird ");
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose() )
    {
       

        game.input();
     
        float dt = 0.016;
        game.update(dt);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        game.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}








