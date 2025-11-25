#include "menus.h"
#include "raylib.h"
#include "global.h"
#include "textures.h"
#include <iostream>
using namespace std;
#include <string>

Vector2 mousePnt = {0.0f, 0.0f};

bool checkDrawButton(const char *btn_text, Rectangle button){
    // -- Draw button
    mousePnt = GetMousePosition();
    if (!CheckCollisionPointRec(mousePnt, button)){ // PLAY button
        DrawTexture(button_texture, button.x, button.y, WHITE);
        DrawText(btn_text, (SCREEN_WIDTH-MeasureText(btn_text, 26))/2, button.y+12, 26, BLACK);
    } else {
        DrawTexture(alt_button_texture, button.x, button.y, WHITE);
        DrawText(btn_text, (SCREEN_WIDTH-MeasureText(btn_text, 26))/2, button.y+12, 26, (Color){0x93, 0x84, 0x73, 0xff});
    }
    // -- Check click
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePnt, button)){
        return true;
    } else {
        return false;
    }
}

// -- MAIN MENU
Rectangle playButton = {(SCREEN_WIDTH-230)/2, 260, 230, 54};
Rectangle rankingButton = {(SCREEN_WIDTH-230)/2, 360, 230, 54};
Rectangle quitButton = {(SCREEN_WIDTH-230)/2, 460, 230, 54};

void mainmenu_render(){
    DrawTexture(mainmenu_background, 0, 0, WHITE);
    DrawTexture(mainmenu_logo, (SCREEN_WIDTH-295)/2, 75, WHITE);

    // -- "JOGAR"
    if(checkDrawButton("JOGAR", playButton)){
        initializeGame();
        // TODO define difficulty based on user selection here
    }
    // -- "RANKING"
    if(checkDrawButton("RANKING", rankingButton)){
        // gameState = RANKING;
        // TODO add ranking screen
    }
    // -- "SAIR"
    if(checkDrawButton("SAIR", quitButton)){
        CloseWindow();
    }

    BeginDrawing();
    EndDrawing();
};

// -- ENDGAME
string playerName;
Rectangle endgame_returnbtn = {(SCREEN_WIDTH-230)/2, 500, 230, 54};

void endgame_entername(){
    int keyPressed = GetKeyPressed();
    // -- write when pressing
    while (keyPressed > 0) {
        int currentLetter = keyPressed;
        if ((currentLetter >= 32) && (currentLetter <= 125) && playerName.size() < 15) {
            playerName.push_back((char)currentLetter);
        }
        keyPressed = GetKeyPressed();
    }
    // -- erase with backspace
    if (IsKeyPressed(KEY_BACKSPACE)){
        playerName.pop_back();
    }
    // -- enter also saves
    if (IsKeyPressed(KEY_ENTER) or checkDrawButton("SALVAR", endgame_returnbtn)){
        gameState = MENUPAGE;
        // TODO save into file, in another cpp
    }
}

void endgame_render(){
    DrawTexture(mainmenu_background, 0, 0, WHITE);
    DrawText("VOCÊ PERDEU", (SCREEN_WIDTH-MeasureText("VOCÊ PERDEU", 35))/2, 40, 35, WHITE);
    DrawText(TextFormat("Sua pontuação: %d", points), (SCREEN_WIDTH-MeasureText(TextFormat("Sua pontuação: %d", points), 20))/2, 180, 20, WHITE);
    DrawText("Digite seu nome", (SCREEN_WIDTH-MeasureText("Digite seu nome", 20))/2, 280, 20, WHITE);
    endgame_entername();
    DrawText(playerName.c_str(), ((SCREEN_WIDTH-MeasureText(playerName.c_str(), 20))/2), 360, 20, WHITE);
    DrawLine(70, 380, SCREEN_WIDTH-70, 380, WHITE);
    

    BeginDrawing();
    EndDrawing();
}