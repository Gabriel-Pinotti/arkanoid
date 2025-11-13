#include <iostream>
#include "raylib.h"
using namespace std;
// compile using '$ g++ main.cpp -lraylib'

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 800

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
    int height = 20;
    int width = 100;
    int speed = 250;
    float starting_x = (SCREEN_WIDTH/2)-(width/2);
    float starting_y = 650;
    Vector2 position = {starting_x, starting_y};
};

Paddle paddle;

void movePaddle(float &ft){
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
            paddle.position.x-=paddle.speed * ft;
            break;
        case RIGHT:
            paddle.position.x+=paddle.speed * ft;
            break;
        case STATIC:
            break;
    }
}

void moveBall(float &ft){
    switch (ball.direction){ 
        case UP:
            ball.position.y-=ball.speed * ft;
            break;
        case DOWN:
            ball.position.y+=ball.speed * ft;
            break;
        case STATIC:
            break;
    }
}

void paddle_wall_collision(Vector2 &paddle_position){
    if (paddle_position.x > SCREEN_WIDTH-paddle.width){
        paddle_position.x = SCREEN_WIDTH-paddle.width;
    }
    if (paddle_position.x < 0){
        paddle_position.x = 0;
    }
}

void ball_collision(){
    if (paddle.position.y-ball.radius < ball.position.y){
        ball.direction = UP;
    }
    if (ball.position.y < ball.radius){
        ball.direction = DOWN;
    }
}

int main(){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Arkanoid");
    SetTargetFPS(60);
    int direction;  

    while (!WindowShouldClose()){
        float ft = GetFrameTime();
        movePaddle(ft);
        moveBall(ft);
        ball_collision();
        paddle_wall_collision(paddle.position);
        DrawRectangle(paddle.position.x, paddle.position.y, paddle.width, paddle.height, GRAY);
        
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}