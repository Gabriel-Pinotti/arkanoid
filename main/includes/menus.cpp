#include "menus.h"
#include "raylib.h"
#include "global.h"
#include "textures.h"

Vector2 mousePnt = {0.0f, 0.0f};
Rectangle playButton = {(SCREEN_WIDTH-230)/2, 260, 230, 54};
Rectangle rankingButton = {(SCREEN_WIDTH-230)/2, 360, 230, 54};
Rectangle quitButton = {(SCREEN_WIDTH-230)/2, 460, 230, 54};

void menubtn_draw(const char *btn_text, Rectangle btn){
    mousePnt = GetMousePosition();
    if (!CheckCollisionPointRec(mousePnt, btn)){ // PLAY button
        DrawTexture(button_texture, btn.x, btn.y, WHITE);
        DrawText(btn_text, (SCREEN_WIDTH-MeasureText(btn_text, 30))/2, btn.y+12, 30, BLACK);
    } else {
        DrawTexture(alt_button_texture, btn.x, btn.y, WHITE);
        DrawText(btn_text, (SCREEN_WIDTH-MeasureText(btn_text, 30))/2, btn.y+12, 30, (Color){0x93, 0x84, 0x73, 0xff});
    }
}

void mainmenu_draw(){
    DrawTexture(mainmenu_background, 0, 0, WHITE);
    DrawTexture(mainmenu_logo, (SCREEN_WIDTH-295)/2, 75, WHITE);
    menubtn_draw("JOGAR", playButton);
    menubtn_draw("RANKING", rankingButton);
    menubtn_draw("SAIR", quitButton);



    BeginDrawing();
    EndDrawing();
};

void mainmenu_clickcheck(){
    mousePnt = GetMousePosition();
    // -- "JOGAR"
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePnt, playButton)){
        initializeGame();
        // TODO define difficulty based on user selection here
    }
    // -- "RANKING"
    // TODO add ranking screen
    // -- "SAIR"
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePnt, quitButton)){
        CloseWindow();
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