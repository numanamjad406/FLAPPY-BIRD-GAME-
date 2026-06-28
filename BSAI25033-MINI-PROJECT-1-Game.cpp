#include "BSAI25033-MINI-PROJECT-1-Game.h "

Game::Game()
{
    screenWidth = 1590;  
    screenHeight = 890;  

    bird.setScreenSize(screenWidth, screenHeight);

    bg1 = LoadTexture("Background.png");
    bg2 = LoadTexture("Background.png");

    bg1X = 0;
    bg2X = screenWidth;

    state = MENU;
    score = 0;
    level = 1;
    level2Unlocked = false;
}

void Game::startGame(int lvl) 
{
    score = 0;
    level = lvl;
    bird.reset();

    float speed;
    float gap;

    if (lvl == 1)
    {
        speed = 260;
        gap = 220;
    }
    else
    {
        speed = 360;
        gap = 160;
    }

    for (int i = 0; i < PIPE_COUNT; i++)
    {
        pipes[i].init(screenWidth + i * 500, gap, speed, screenWidth, screenHeight);
    }


    state = PLAYING;
}

void Game::update(float dt) 
{
    if (state != PLAYING)
        return;

    float scrollSpeed = 120;
    bg1X -= scrollSpeed * dt;
    bg2X -= scrollSpeed * dt;

    if (bg1X <= -screenWidth)
    {
        bg1X = screenWidth;
    }
    if (bg2X <= -screenWidth) 
    {
        bg2X = screenWidth;
    }

    if (IsKeyPressed(KEY_SPACE))
    {
        bird.flap();
    }

    bird.update(dt);

    if (bird.hitBoundary())
    {
        state = GAMEOVER;
    }

    for (int i = 0; i < PIPE_COUNT; i++)
    {
        pipes[i].update(dt);

        if (pipes[i].collision(bird))
        {
            state = GAMEOVER;
        }

        if (pipes[i].checkPassed(bird))
        {
            score++;
        }
    }

    if (score >= 10)
    {
        level2Unlocked = true;
    }
}

void Game::draw()
{
    DrawTexture(bg1, bg1X, 0, WHITE);
    DrawTexture(bg2, bg2X, 0, WHITE);

    if (state == MENU)
    {
        DrawText("FLAPPY BIRD", 600, 200, 70, DARKGREEN);
        DrawText("SPACE : FLAP", 640, 320, 40, BLACK);
        DrawText("1 : START LEVEL 1", 620, 390, 40, RED);

        if (level2Unlocked)
        {
            DrawText("2 : START LEVEL 2", 620, 450, 40, RED);
        }

        DrawText("Q : QUIT", 620, 520, 40, BLACK);
    }
    else if (state == PLAYING)
    {
        bird.draw();

        for (int i = 0; i < PIPE_COUNT; i++)
        {
            pipes[i].draw();
        }

        DrawText(TextFormat("Score: %d", score), 30, 30, 40, BLACK);
    }
    else if (state == GAMEOVER) 
    {
        DrawText("GAME OVER", 600, 350, 70, RED);
        DrawText(TextFormat("Final Score: %d", score), 650, 450, 40, BLACK);
        DrawText("R : Restart", 620, 520, 40, BLUE);
        DrawText("M : Menu", 620, 580, 40, RED);
        DrawText("Q : Quit", 620, 640, 40, RED);
    }
}

void Game::input()
{
    if (state == MENU)
    {
        if (IsKeyPressed(KEY_ONE))
        {
            startGame(1);
        }

        if (IsKeyPressed(KEY_TWO) && level2Unlocked)
        {
            startGame(2);
        }

        if (IsKeyPressed(KEY_Q))
        {
            CloseWindow();
        }
    }

    if (state == GAMEOVER) 
    {
        if (IsKeyPressed(KEY_R))
        {
            startGame(level);
        }

        if (IsKeyPressed(KEY_M))
        {
            state = MENU;
        }

        if (IsKeyPressed(KEY_Q))
        {
            CloseWindow();
        }
    }
}
