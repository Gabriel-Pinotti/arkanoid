#include <iostream>
#include "raylib.h"
#include <vector>
#include <math.h>
using namespace std;
// compile using '$ g++ main.cpp -lraylib'

// ----- GLOBAL VARIABLES -----
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 800
const int brickRows = 3;
const int bricksPerRow = 4;


struct Ball {
    int radius = 10;
    Vector2 speed = {0, -5};
    Vector2 position = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
};

Ball ball;

struct Paddle {
    int speed = 250;
    Vector2 size = {150, 20};
    Vector2 position = {((SCREEN_WIDTH/2)), 650};
};

Paddle paddle;

struct Brick {
    Vector2 position;
    int health;
    Vector2 size;
};

Brick brick[brickRows][bricksPerRow];


void initializeBricks(){
    float x_margins = 30;
    float y_margin = 40;
    float brick_y = 35;
    float brick_x = (SCREEN_WIDTH-(2*x_margins))/bricksPerRow;

    for (int i = 0; i < brickRows; i++) {
        for (int j = 0; j < bricksPerRow; j++) {
            brick[i][j].size = {brick_x, brick_y};
            brick[i][j].position = { (j*brick[i][j].size.x + brick[i][j].size.x/2)+x_margins, i*brick[i][j].size.y + y_margin };
            brick[i][j].health = 1; // TODO create bricks with different health based on difficulty
        }
    }
}

void drawBricks(){
    for (int i = 0; i < brickRows; i++){
        for (int j = 0; j < bricksPerRow; j++)
        {
            if (brick[i][j].health >= 1){
                if ((i + j) % 2 == 0) { // TODO update to render sprites based on health
                    DrawRectangle(brick[i][j].position.x - brick[i][j].size.x/2, brick[i][j].position.y - brick[i][j].size.y/2, brick[i][j].size.x, brick[i][j].size.y, BLACK);
                }
                else {
                    DrawRectangle(brick[i][j].position.x - brick[i][j].size.x/2, brick[i][j].position.y - brick[i][j].size.y/2, brick[i][j].size.x, brick[i][j].size.y, DARKPURPLE);
                }         
            }
        }
        
    }
};

void movePaddle(float &ft){
    char direction;
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
        direction = 'r';
    }
    else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
        direction = 'l';
    }
    else {
        direction = 's';
    }

    switch (direction){ 
        case 'l':
            paddle.position.x-=paddle.speed * ft;
            break;
        case 'r':
            paddle.position.x+=paddle.speed * ft;
            break;
        case 's':
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
    if (CheckCollisionCircleRec(ball.position, ball.radius, // ball x paddle collision
        (Rectangle){ paddle.position.x - paddle.size.x/2, paddle.position.y - paddle.size.y/2, paddle.size.x, paddle.size.y}))
    {
        if (ball.speed.y > 0) {
            ball.speed.y *= -1;
            ball.speed.x = (ball.position.x - paddle.position.x)/(paddle.size.x/2)*5;
        }
    }

    // ball x bricks collision

    for (int i = 0; i < brickRows; i++) {
        for (int j = 0; j < bricksPerRow; j++) {
            if (brick[i][j].health >= 1) {
                // Hit below
                if (((ball.position.y - ball.radius) <= (brick[i][j].position.y + brick[i][j].size.y/2)) &&
                    ((ball.position.y - ball.radius) > (brick[i][j].position.y + brick[i][j].size.y/2 + ball.speed.y)) &&
                    ((fabs(ball.position.x - brick[i][j].position.x)) < (brick[i][j].size.x/2 + ball.radius*2/3)) && (ball.speed.y < 0))
                {
                    brick[i][j].health -= 1;
                    ball.speed.y *= -1;
                }
                // Hit above
                else if (((ball.position.y + ball.radius) >= (brick[i][j].position.y - brick[i][j].size.y/2)) &&
                        ((ball.position.y + ball.radius) < (brick[i][j].position.y - brick[i][j].size.y/2 + ball.speed.y)) &&
                        ((fabs(ball.position.x - brick[i][j].position.x)) < (brick[i][j].size.x/2 + ball.radius*2/3)) && (ball.speed.y > 0))
                {
                    brick[i][j].health -= 1;
                    ball.speed.y *= -1;
                }
                // Hit left
                else if (((ball.position.x + ball.radius) >= (brick[i][j].position.x - brick[i][j].size.x/2)) &&
                        ((ball.position.x + ball.radius) < (brick[i][j].position.x - brick[i][j].size.x/2 + ball.speed.x)) &&
                        ((fabs(ball.position.y - brick[i][j].position.y)) < (brick[i][j].size.y/2 + ball.radius*2/3)) && (ball.speed.x > 0))
                {
                    brick[i][j].health -= 1;
                    ball.speed.x *= -1;
                }
                // Hit right
                else if (((ball.position.x - ball.radius) <= (brick[i][j].position.x + brick[i][j].size.x/2)) &&
                        ((ball.position.x - ball.radius) > (brick[i][j].position.x + brick[i][j].size.x/2 + ball.speed.x)) &&
                        ((fabs(ball.position.y - brick[i][j].position.y)) < (brick[i][j].size.y/2 + ball.radius*2/3)) && (ball.speed.x < 0))
                {
                    brick[i][j].health -= 1;
                    ball.speed.x *= -1;
                }
            }
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

void draw(Texture2D paddle_texture, Texture2D ball_texture){
    DrawTexture(ball_texture, ball.position.x-ball.radius, ball.position.y-ball.radius, WHITE);
    DrawTexture(paddle_texture, paddle.position.x-paddle.size.x/2, paddle.position.y-paddle.size.y/2, WHITE);
    drawBricks();
    
    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();
}

int main(){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Arkanoid");
    SetTargetFPS(60);
    int direction;  
    Texture2D paddle_texture = LoadTexture("../assets/paddle_texture.png");
    Texture2D ball_texture = LoadTexture("../assets/ball_texture.png");
    initializeBricks();

    while (!WindowShouldClose()){ // while the game is running
        float ft = GetFrameTime();
        movements(ft);
        collisions(); // TODO add bricks collision
        draw(paddle_texture, ball_texture);
    }

    CloseWindow();
    return 0;
}