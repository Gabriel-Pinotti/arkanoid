#include "raylib.h"
#include "global.h"
#include "ball.h"
#include "paddle.h"
#include "bricks.h"
#include "textures.h"
#include <cmath>

// -- time
int baseTime;
double currentLevelTime;
// -- level specific
int points;
int lives;
int level;
int hitsRemaining;
int initialheath = 3;
// -- menu and selections
int difficulty = 1;
game_state_selection gameState = MENUPAGE;


void menuExitVerification(){
    if (IsKeyPressed(KEY_ESCAPE)){
        gameState = MENUPAGE;
    }
}

void drawGameUI(){
    // -- low opacity black rectangles
    DrawRectangle(0, 0, SCREEN_WIDTH, 40, (Color){0, 0, 0, 150});
    DrawRectangle(0, SCREEN_HEIGHT-30, SCREEN_WIDTH, 30, (Color){0, 0, 0, 150});

    // ----- Points -----
    DrawText(TextFormat("Pontos: %d", points), 10, 10, 20, WHITE);

    // ----- Lifes -----
    DrawTextureEx(heart_texture, (Vector2){SCREEN_WIDTH-100, 0}, 0, 1.4, WHITE);
    DrawText(TextFormat("x %d", lives), SCREEN_WIDTH-55, 10, 20, WHITE);

    // ----- Time -----
    int displayMin = (int)(currentLevelTime / 60.0);
    float displaySec = (float)fmod(currentLevelTime, 60.0);
    DrawText(TextFormat("%02i:%02.0f", displayMin, displaySec), SCREEN_WIDTH/2-23, 10, 20, WHITE);

    // ----- Level -----
    DrawText(TextFormat("Level %d", level), (SCREEN_WIDTH-MeasureText(TextFormat("Level %d", level), 17))/2, SCREEN_HEIGHT-25, 17, WHITE);
}

void game_movements(float &ft){
    movePaddle(ft);
    moveBall();
    menuExitVerification();
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
    // -- game objects
    initializeBricks();
    ball.speed = {0, 0};
    ball.active = false;
    paddle.position = {((SCREEN_WIDTH/2)), 650};
    // -- level specific variables
    lives = initialheath;
    level = 1;
    points = 0;
    // -- time
    localStoredTime = 0;
    currentLevelTime = 0;

    // -- render game
    gameState = GAME;
}

void initializeGame(int points){
    // -- game objects
    initializeBricks();
    ball.speed = {0, 0};
    ball.active = false;
    paddle.position = {((SCREEN_WIDTH/2)), 650};
    // -- level specific variables
    if (difficulty != 3){
        lives = initialheath;
    }
    level+=1;;
    // -- time
    localStoredTime = 0;
    currentLevelTime = 0;

    // -- render game
    gameState = GAME;
}
