#include <iostream>
#include <vector>
#include <math.h>
#include "raylib.h"
#include "../includes/paddle.h"
#include "../includes/global.h"
#include "../includes/textures.h"
#include "../includes/ball.h"
using namespace std;
// compile using '$ g++ ./src/main.cpp [./includes/everycppfile.cpp] -lraylib'

void initializeBricks(){
    float x_margins = 30;
    float y_margin = 40; // blocks are 68x40px
    float brick_y = 35;
    float brick_x = (SCREEN_WIDTH-(2*x_margins))/bricksPerRow;

    for (int i = 0; i < brickRows; i++) {
        for (int j = 0; j < bricksPerRow; j++) {
            brick[i][j].size = {brick_x, brick_y};
            brick[i][j].position = { (j*brick[i][j].size.x + brick[i][j].size.x/2)+x_margins, i*brick[i][j].size.y + y_margin };
            brick[i][j].health = 6; // TODO randomize with a recursive function, based on difficulty and level
        }
    }
}

void initializeTextures(){
    game_background = LoadTexture("../assets/backgrounds/game_background.png");
    paddle_texture = LoadTexture("../assets/paddles/paddle_normal_texture.png");
    ball_texture = LoadTexture("../assets/misc/ball_texture.png");
    brick_1hp_texture = LoadTexture("../assets/bricks/1hpbrick.png");
    brick_2hp_texture = LoadTexture("../assets/bricks/2hpbrick.png");
    brick_3hp_texture = LoadTexture("../assets/bricks/3hpbrick.png");
    brick_4hp_texture = LoadTexture("../assets/bricks/4hpbrick.png");
    brick_5hp_texture = LoadTexture("../assets/bricks/5hpbrick.png");
    brick_6hp_texture = LoadTexture("../assets/bricks/6hpbrick.png");
}

void drawBricks(){
    for (int i = 0; i < brickRows; i++){
        for (int j = 0; j < bricksPerRow; j++)
        {
            if (brick[i][j].health == 1){
                DrawTexture(brick_1hp_texture, brick[i][j].position.x-brick[i][j].size.x/2, brick[i][j].position.y-brick[i][j].size.y/2, WHITE);
       
            }
            if (brick[i][j].health == 2){
                DrawTexture(brick_2hp_texture, brick[i][j].position.x-brick[i][j].size.x/2, brick[i][j].position.y-brick[i][j].size.y/2, WHITE);
       
            }
            if (brick[i][j].health == 3){
                DrawTexture(brick_3hp_texture, brick[i][j].position.x-brick[i][j].size.x/2, brick[i][j].position.y-brick[i][j].size.y/2, WHITE);
       
            }
            if (brick[i][j].health == 4){
                DrawTexture(brick_4hp_texture, brick[i][j].position.x-brick[i][j].size.x/2, brick[i][j].position.y-brick[i][j].size.y/2, WHITE);
       
            }
            if (brick[i][j].health == 5){
                DrawTexture(brick_5hp_texture, brick[i][j].position.x-brick[i][j].size.x/2, brick[i][j].position.y-brick[i][j].size.y/2, WHITE);
       
            }
            if (brick[i][j].health == 6){
                DrawTexture(brick_6hp_texture, brick[i][j].position.x-brick[i][j].size.x/2, brick[i][j].position.y-brick[i][j].size.y/2, WHITE);
       
            }
        }
        
    }
};

void movements(float &ft){
    movePaddle(ft);
    moveBall();
}

void collisions(){
    ball_collision();
    paddle_wall_collision(paddle.position);
}

void draw(){
    DrawTexture(game_background, 0, 0, WHITE);
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
    initializeBricks();
    initializeTextures();

    while (!WindowShouldClose()){ // while the game is running
        float ft = GetFrameTime();
        movements(ft);
        collisions();
        draw();
    }

    CloseWindow();
    return 0;
}