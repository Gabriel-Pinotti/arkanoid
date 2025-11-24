#include "menus.h"
#include "raylib.h"
#include "global.h"
#include "textures.h"

Vector2 mousePnt = {0.0f, 0.0f};
Rectangle playButton = {(SCREEN_WIDTH-230)/2, 260, 230, 54};


void mainmenu_draw(){
    mousePnt = GetMousePosition();
    DrawTexture(mainmenu_background, 0, 0, WHITE);
    DrawTexture(mainmenu_logo, (SCREEN_WIDTH-295)/2, 75, WHITE);
    if (!CheckCollisionPointRec(mousePnt, playButton)){ // PLAY button
        DrawTexture(button_texture, playButton.x, playButton.y, WHITE);
        DrawText("JOGAR", (SCREEN_WIDTH-MeasureText("JOGAR", 30))/2, playButton.y+12, 30, BLACK);
    } else {
        DrawTexture(alt_button_texture, playButton.x, playButton.y, WHITE);
        DrawText("JOGAR", (SCREEN_WIDTH-MeasureText("JOGAR", 30))/2, playButton.y+12, 30, BLACK);
    }

    BeginDrawing();
    EndDrawing();
};

void mainmenu_clickcheck(){
    mousePnt = GetMousePosition();
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePnt, playButton)){
        initializeGame();
        // TODO define difficulty based on user selection here
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