#include <iostream>
#include "raylib.h"
using namespace std;
// compile using '$ g++ main.cpp -lraylib'

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 800

#define PADDLE_HEIGHT 20
#define PADDLE_WIDTH 100
#define STARTING_X (SCREEN_WIDTH/2)-(PADDLE_WIDTH/2)
#define STARTING_Y 650
#define SPEED 200

#define STATIC 0
#define LEFT 1
#define RIGHT 2

void movePaddle(int direction, Vector2 &paddle_position, float &ft){
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
        direction = RIGHT;
    }
    else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
        direction = LEFT;
    }
    else {
        direction = STATIC;
    }

    switch (direction){ 
        case LEFT:
            paddle_position.x-=SPEED * ft;
            break;
        case RIGHT:
            paddle_position.x+=SPEED * ft;
            break;
        case STATIC:
            break;
    }
}

void collision(){
    
}


int main(){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Arkanoid");
    SetTargetFPS(60);
    Vector2 paddle = {STARTING_X, STARTING_Y}; // starting position
    int direction;  

    while (!WindowShouldClose()){
        float ft = GetFrameTime();
        movePaddle(direction, paddle, ft);
        DrawRectangle(paddle.x, paddle.y, PADDLE_WIDTH, PADDLE_HEIGHT, GRAY);
        
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}