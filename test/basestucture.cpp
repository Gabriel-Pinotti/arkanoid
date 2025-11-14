#include <iostream>
#include "raylib.h"
using namespace std;
// compile using '$ g++ main.cpp -lraylib'

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 800

#define STATIC 0
#define LEFT 1
#define RIGHT 2

struct Ball {
    int radius = 10;
    Vector2 speed = {0, -5};
    Vector2 position = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
};

Ball ball;

struct Paddle {
    int speed = 250;
    Vector2 size = {100, 20};
    Vector2 position = {((SCREEN_WIDTH/2)-(size.x/2)), 650}; // defines initial position
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

void moveBall(){
    ball.position.x += ball.speed.x;
    ball.position.y += ball.speed.y;
}

void paddle_wall_collision(Vector2 &paddle_position){
    if ((paddle.position.x - paddle.size.x/2) <= 0) {
        paddle.position.x = paddle.size.x/2;
    }
    if ((paddle.position.x + paddle.size.x/2) >= SCREEN_WIDTH) {
        paddle.position.x = SCREEN_WIDTH - paddle.size.x/2;
    }
}

void ball_collision(){
    if (((ball.position.x + ball.radius) >= SCREEN_WIDTH) || ((ball.position.x - ball.radius) <= 0)) { // left and right
        ball.speed.x *= -1;
    }
    if ((ball.position.y - ball.radius) <= 0) { // up
        ball.speed.y *= -1;
    }
    if ((ball.position.y + ball.radius) >= SCREEN_HEIGHT) { // down
        // TODO add logic to floor collision
    }
    if (CheckCollisionCircleRec(ball.position, ball.radius, // ball - paddle collision
        (Rectangle){ paddle.position.x - paddle.size.x/2, paddle.position.y - paddle.size.y/2, paddle.size.x, paddle.size.y}))
    {
        if (ball.speed.y > 0) {
            ball.speed.y *= -1;
            ball.speed.x = (ball.position.x - paddle.position.x)/(paddle.size.x/2)*5;
        }
    }
}

void movements(float &ft){
    movePaddle(ft);
    moveBall();
}

void collisions(){
    ball_collision();
    paddle_wall_collision(paddle.position);
}

void draw(){
    DrawRectangle(paddle.position.x - paddle.size.x/2, paddle.position.y - paddle.size.y/2, paddle.size.x, paddle.size.y, GRAY);
    DrawCircleV(ball.position, ball.radius, BLUE);
    
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
}

int main(){ // TODO add bricks
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Arkanoid");
    SetTargetFPS(60);
    int direction;  

    while (!WindowShouldClose()){ // while the game is running
        float ft = GetFrameTime();
        movements(ft);
        collisions();
        draw();
    }

    CloseWindow();
    return 0;
}