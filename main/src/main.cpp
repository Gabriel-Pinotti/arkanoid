#include "raylib.h"
#include "../includes/paddle.h"
#include "../includes/global.h"
#include "../includes/textures.h"
#include "../includes/ball.h"
#include "../includes/bricks.h"
#include "../includes/menu.h"
using namespace std;
// compile using makefile if using linux
// for windows, use alternative makefile

int main(){
    SetTargetFPS(60);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Arkanoid");
    initializeGame();
    while (!WindowShouldClose()){ // while the game is running
        float ft = GetFrameTime();
        if (gameState == MENUPAGE){
            // draw menu and render mouse hover / clicking
            menu_draw();
            menu_clickcheck();
        }
        if (gameState == GAME){
            game_movements(ft);
            game_collisions();
            game_draw();
        }
    }

    CloseWindow();
    return 0;
}