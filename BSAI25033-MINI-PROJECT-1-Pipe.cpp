#include "BSAI25033-MINI-PROJECT-1-Pipe.h "
#include <cstdlib>  
#include <ctime>    
void Pipe::init(float startX, float gap, float spd, int scrW, int scrH)
{
    x = startX;
    gapSize = gap;
    speed = spd;
    screenWidth = scrW;    
    screenHeight = scrH;   
    pipeTex = LoadTexture("pipe.png");
    reset();
}




void Pipe::reset()
{
    int minY = 200;
    int maxY = screenHeight - 200 - gapSize; 
    gapY = minY + rand() % (maxY - minY + 1);
    passed = false;
}



void Pipe::update(float dt)
{
    x -= speed * dt;
    if (x < -100)
    {
        x = screenWidth + 400;
        reset();
    }
}

void Pipe::draw()
{
   
    DrawTexture(pipeTex, x + (100 - pipeTex.width) / 2, gapY - pipeTex.height, WHITE);


    DrawTexture(pipeTex, x + (100 - pipeTex.width) / 2, gapY + gapSize, WHITE);
}





bool Pipe::collision(Bird& b) 
{
    Rectangle top = { x, 0, 100, gapY };
    Rectangle bottom = {x,gapY + gapSize,100,screenHeight - (gapY + gapSize) };

    return CheckCollisionRecs(b.getRect(), top) or
        CheckCollisionRecs(b.getRect(), bottom);
}

bool Pipe::checkPassed(Bird& b) 
{
    if (!passed and x + 100 < b.x) 
    {
        passed = true;
        return true;
    }
    return false;
}
