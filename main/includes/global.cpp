#include "raylib.h"
#include "global.h"
#include "ball.h"
#include "paddle.h"
#include "bricks.h"
#include "textures.h"

int points = 0;
int lives = 3;

void drawUI(){ // TODO make points relative to difficulty and time
    DrawRectangle(0, 0, SCREEN_WIDTH, 40, (Color){0, 0, 0, 120}); // low opacity black rectangle

    // ----- Points -----
    DrawText(TextFormat("Pontos: %d", points), 10, 10, 20, WHITE);

    // ----- Lifes -----
    DrawTextureEx(heart_texture, (Vector2){SCREEN_WIDTH-120, 0}, 0, 1.4, WHITE);
    DrawText(TextFormat("x %d", lives), SCREEN_WIDTH-75, 10, 20, WHITE);
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
    DrawTexture(game_background, 0, 0, WHITE); // in-game background
    drawBall();
    drawPaddle();
    drawBricks();
    drawUI();
    
    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();
}

void initializeGame(){
    initializeBricks();
    initializeTextures();
}