#pragma once
#include "raylib.h"
#include "BSAI25033-MINI-PROJECT-1-Bird.h "

class Pipe {
    float x;
    float gapY;
    float gapSize;
    float speed;
    bool passed;
    int screenWidth;  
    int screenHeight; 
public:
    Texture2D pipeTex;

    void init(float startX, float gap, float spd, int scrW, int scrH); 
    void reset();
    void update(float dt);
    void draw();
    bool collision(Bird& b);
    bool checkPassed(Bird& b);
};
