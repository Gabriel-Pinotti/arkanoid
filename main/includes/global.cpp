#include "raylib.h"
#include "global.h"
#include "ball.h"
#include "paddle.h"
#include "bricks.h"
#include "textures.h"
#include <cmath>

// -- time
int baseTime = GetTime();
double currentLevelTime = 0;
// -- level specific
int points = 0;
int lives = 3;
int level = 1;
// -- menu and selections
int difficulty = 1; // TODO select after clicking "play" on menu
game_state_selection gameState = MENUPAGE;


void drawGameUI(){ // TODO make points relative to difficulty and time
    DrawRectangle(0, 0, SCREEN_WIDTH, 40, (Color){0, 0, 0, 120}); // low opacity black rectangle

    // ----- Points -----
    DrawText(TextFormat("Pontos: %d", points), 10, 10, 20, WHITE);

    // ----- Lifes -----
    DrawTextureEx(heart_texture, (Vector2){SCREEN_WIDTH-100, 0}, 0, 1.4, WHITE);
    DrawText(TextFormat("x %d", lives), SCREEN_WIDTH-55, 10, 20, WHITE);

    // ----- Time -----
    int displayMin = (int)(currentLevelTime / 60.0);
    float displaySec = (float)fmod(currentLevelTime, 60.0);
    DrawText(TextFormat("%02i:%02.0f", displayMin, displaySec), SCREEN_WIDTH/2-23, 10, 20, WHITE);
}

void game_movements(float &ft){
    movePaddle(ft);
    moveBall();
}

void game_collisions(){
    ball_collision();
    paddle_wall_collision();
}

void game_draw(){
    DrawTexture(game_background, 0, 0, WHITE); // in-game background
    drawBall();
    drawPaddle();
    drawBricks();
    drawGameUI();
    
    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();
}

void initializeGame(){
    initializeBricks();
    initializeTextures();
}