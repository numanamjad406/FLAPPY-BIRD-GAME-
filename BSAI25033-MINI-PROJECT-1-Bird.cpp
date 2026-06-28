#include "BSAI25033-MINI-PROJECT-1-Bird.h "

Bird::Bird()
{
    texture = LoadTexture("birds.png");
    gravity = 900;

    screenWidth = 0;
    screenHeight = 0;
}
void Bird::setScreenSize(int w, int h)
{
    screenWidth = w;
    screenHeight = h;
}


void Bird::reset() 
{
    x = 300;
    y = screenHeight / 2;
    velocity = 0;
    rotation = 0;
}

void Bird::flap() 
{
    velocity = -380;
}

void Bird::update(float dt) 
{
    velocity += gravity * dt;
    y += velocity * dt;

    rotation = velocity * 0.05;
    if (rotation > 30) 
    {
        rotation = 30;
    }
    if (rotation < -25)
    {
        rotation = -25;
    }
}

void Bird::draw()
{
    Rectangle src = { 0, 0, texture.width, texture.height };
    Rectangle dst = { x, y, 60, 45 };

    DrawTexturePro(texture,src,dst,{ 30, 22 },rotation, WHITE );
}


Rectangle Bird::getRect()
{
    const float width = 60;
    const float height = 45;

    return Rectangle{
        x - width / 2,
        y - height / 2,
        width,
        height
    };
}

bool Bird::hitBoundary() 
{
    return (y < 0 || y >  screenHeight);
}

