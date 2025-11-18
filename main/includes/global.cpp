#include "raylib.h"
#include "global.h"
#include "ball.h"
#include "paddle.h"
#include "bricks.h"
#include "textures.h"

int points = 0;

void drawPoints(){ // TODO make points relative to difficulty and time
    DrawRectangle(0, 0, SCREEN_WIDTH, 40, (Color){0, 0, 0, 120});
    DrawText(TextFormat("Pontos: %d", points), 10, 10, 20, WHITE);
}

void movements(float &ft){
    movePaddle(ft);
    moveBall();
}

void collisions(){
    ball_collision();
    paddle_wall_collision();
}

void draw(){
    DrawTexture(game_background, 0, 0, WHITE);
    DrawTexture(ball_texture, ball.position.x-ball.radius, ball.position.y-ball.radius, WHITE);
    DrawTexture(paddle_texture, paddle.position.x-paddle.size.x/2, paddle.position.y-paddle.size.y/2, WHITE);
    drawBricks();
    drawPoints();
    
    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();
}

void initializeGame(){
    initializeBricks();
    initializeTextures();
}