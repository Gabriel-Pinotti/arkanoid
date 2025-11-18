#include "raylib.h"
#include "global.h"
#include "ball.h"
#include "paddle.h"
#include "bricks.h"
#include "textures.h"

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

void initializeGame(){
    initializeBricks();
    initializeTextures();
}