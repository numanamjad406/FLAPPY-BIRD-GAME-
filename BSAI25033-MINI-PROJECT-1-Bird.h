#pragma once
#include "raylib.h"


class Bird
{
   
    float velocity;
    float gravity;
    float rotation;
    Texture2D texture;
    int screenWidth;
    int screenHeight;
public:
    float x, y;
    Bird();   

    void setScreenSize(int w, int h);  
   

    void reset();
    void flap();
    void update(float dt);
    void draw();
    Rectangle getRect();
    bool hitBoundary();
};
