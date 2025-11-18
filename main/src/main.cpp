#include <iostream>
#include <vector>
#include <math.h>
#include "raylib.h"
#include "../includes/paddle.h"
#include "../includes/global.h"
#include "../includes/textures.h"
#include "../includes/ball.h"
#include "../includes/bricks.h"
using namespace std;
// compile using '$ g++ ./src/main.cpp ./includes/*.cpp -lraylib'

int main(){
    SetTargetFPS(60);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Arkanoid");
    initializeGame();
    while (!WindowShouldClose()){ // while the game is running
        float ft = GetFrameTime();
        movements(ft);
        collisions();
        draw();
    }

    CloseWindow();
    return 0;
}