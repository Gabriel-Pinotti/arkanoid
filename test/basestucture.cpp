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
#define SPEED 250

#define STATIC 0
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

struct Ball {
    int direction = 4;
    int radius = 10;
    int speed = 200;
    Vector2 position = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
};

Ball ball;

struct Paddle {
    Vector2 paddle_position = {STARTING_X, STARTING_Y};
    int height = 20;
    int width = 100;
};

Paddle paddle;

void movePaddle(Vector2 &paddle_position, float &ft){
    int direction;
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

void moveBall(int direction, Vector2 &ball_position, float &ft){
    switch (direction){ 
        case UP:
            ball_position.x-=SPEED * ft;
            break;
        case DOWN:
            ball_position.x+=SPEED * ft;
            break;
        case STATIC:
            break;
    }
}

void paddle_wall_collision(Vector2 &paddle_position){
    if (paddle_position.x > SCREEN_WIDTH-PADDLE_WIDTH){
        paddle_position.x = SCREEN_WIDTH-PADDLE_WIDTH;
    }
    if (paddle_position.x < 0){
        paddle_position.x = 0;
    }
}

void paddle_ball_collision(Vector2 &paddle_position, Vector2 &ball_position){

}

int main(){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Arkanoid");
    SetTargetFPS(60);
    Vector2 paddle_position = {STARTING_X, STARTING_Y}; // starting paddle position
    Vector2 ball_position = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2}; // starting ball position
    int direction;  

    while (!WindowShouldClose()){
        float ft = GetFrameTime();
        movePaddle(paddle_position, ft);
        moveBall(direction, ball_position, ft);
        paddle_ball_collision(paddle_position, ball_position);
        paddle_wall_collision(paddle_position);
        DrawRectangle(paddle_position.x, paddle_position.y, PADDLE_WIDTH, PADDLE_HEIGHT, GRAY);
        
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}