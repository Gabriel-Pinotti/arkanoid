#include "menus.h"
#include "raylib.h"
#include "global.h"


void mainmenu_draw(){
    BeginDrawing();
    ClearBackground(DARKBLUE);
    DrawText("main menu, press TAB", 10, 10, 2, WHITE);
    EndDrawing();
};

void mainmenu_clickcheck(){
    if(IsKeyPressed(KEY_TAB)){
        initializeGame();
        lives = 3;
        // TODO define difficulty based on user selection here
        gameState = GAME;
    }
};

void endgame_draw(){
    BeginDrawing();
    ClearBackground(DARKBLUE);
    DrawText("endgame screen, press TAB", 10, 10, 2, WHITE);
    EndDrawing();
}

void endgame_return(){
    if(IsKeyPressed(KEY_TAB)){
        gameState = MENUPAGE;
    }
};