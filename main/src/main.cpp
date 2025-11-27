#include "raylib.h"
#include "../includes/textures.h"
#include "../includes/menus.h"
using namespace std;
// compile using makefile if using linux
// for windows, use alternative makefile

int main(){
    SetTargetFPS(60);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Arkanoid");
    initializeTextures();
    SetExitKey(KEY_NULL);
    while (!WindowShouldClose()){ // while the game is running
        float ft = GetFrameTime();
        if (gameState == MENUPAGE){
            // draw menu and render mouse hover / clicking
            mainmenu_render();
        }
        if (gameState == ENDGAME){
            endgame_render();
        }
        if (gameState == GAME){
            game_movements(ft);
            game_collisions();
            game_draw();
        }
        if (gameState == RANKING){
            ranking_render();
        }
    }

    CloseWindow();
    return 0;
}