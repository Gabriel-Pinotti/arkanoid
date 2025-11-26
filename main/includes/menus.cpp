#include "menus.h"
#include "raylib.h"
#include "global.h"
#include "textures.h"
#include "saving.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Vector2 mousePnt = {0.0f, 0.0f};

bool checkDrawButton(const char *btn_text, Rectangle button){
    // -- Draw button
    mousePnt = GetMousePosition();
    if (!CheckCollisionPointRec(mousePnt, button)){
        DrawTexture(button_texture, button.x, button.y, WHITE);
    } else {
        DrawTexture(alt_button_texture, button.x, button.y, WHITE);
    }
    DrawText(btn_text, (SCREEN_WIDTH-MeasureText(btn_text, 26))/2, button.y+12, 26, BLACK);
    // -- Check click
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePnt, button)){
        return true;
    } else {
        return false;
    }
}


// -- MAIN MENU
Rectangle playButton = {(SCREEN_WIDTH-230)/2, 260, 230, 54};
Rectangle difficultySelectionButton = {(SCREEN_WIDTH-230)/2, 360, 230, 54};
Rectangle rankingButton = {(SCREEN_WIDTH-230)/2, 460, 230, 54};
Rectangle quitButton = {(SCREEN_WIDTH-230)/2, 560, 230, 54};

// -- difficulty selection
void difficultyButtonVerification(){
    // get mouse position
    mousePnt = GetMousePosition();
    
    // draw button (color variation)
    if (!CheckCollisionPointRec(mousePnt, difficultySelectionButton)){
        DrawTexture(button_texture, difficultySelectionButton.x, difficultySelectionButton.y, WHITE);
    } else {
        DrawTexture(alt_button_texture, difficultySelectionButton.x, difficultySelectionButton.y, WHITE);
    }

    // draw difficulty name
    if (difficulty == 1){
        DrawText("Dificuldade: Fácil", (SCREEN_WIDTH-MeasureText("Dificuldade: Fácil", 22))/2, difficultySelectionButton.y+14, 22, BLACK);
    }
    if (difficulty == 2){
        DrawText("Dificuldade: Médio", (SCREEN_WIDTH-MeasureText("Dificuldade: Médio", 22))/2, difficultySelectionButton.y+14, 22, BLACK);
    }
    if (difficulty == 3){
        DrawText("Dificuldade: Difiícil", (SCREEN_WIDTH-MeasureText("Dificuldade: Difiícil", 22))/2, difficultySelectionButton.y+14, 22, BLACK);
        DrawText("Sem resturação de HP!", (SCREEN_WIDTH-MeasureText("Sem resturação de HP!", 14))/2, 420, 14, RED);
    }

    // check clicking
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePnt, difficultySelectionButton)){
        if (difficulty == 1){
            difficulty = 2;
        } else if (difficulty == 2){
            difficulty = 3;
        } else if (difficulty == 3) {
            difficulty = 1;
        }
    }
}

void mainmenu_render(){
    DrawTexture(mainmenu_background, 0, 0, WHITE);
    DrawTexture(mainmenu_logo, (SCREEN_WIDTH-295)/2, 75, WHITE);
    // -- "JOGAR"
    if(checkDrawButton("Jogar", playButton)){
        initializeGame();
    }
    // -- "Dificuldade: "
    difficultyButtonVerification();
    // -- "RANKING"
    if(checkDrawButton("Ranking", rankingButton)){
        gameState = RANKING;
    }
    // -- "SAIR"
    if(checkDrawButton("Sair", quitButton)){
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
    if (IsKeyPressed(KEY_BACKSPACE) && playerName != ""){
        playerName.pop_back();
    }
    // -- save
    if (IsKeyPressed(KEY_ENTER) || checkDrawButton("SALVAR", endgame_returnbtn)){
        saveScore(playerName, points, difficulty);
        playerName.clear();
        gameState = MENUPAGE;
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

// -- RANKING
int printedScoresNum = 5;
void ranking_render(){
    DrawTexture(mainmenu_background, 0, 0, WHITE);
    DrawText("RANKING", (SCREEN_WIDTH-MeasureText("RANKING", 32))/2, 40, 32, WHITE);
    DrawText(TextFormat("*Os %d melhores!", printedScoresNum), (SCREEN_WIDTH-MeasureText(TextFormat("*Os %d melhores!", printedScoresNum), 18))/2, 70, 18, WHITE);
    vector<string> scoreList = readScoresFile();

    sortScores(scoreList); // prioritze points, difficulty in order

    for(int i = 0; i < scoreList.size() && i < printedScoresNum; i++){
        vector<string> currentScore = formatScore(scoreList[i]);

        string firstLineText = 
            currentScore[0] + " - " +
            currentScore[1] + " pts";
        
        string secondLineText =
            currentScore[2] + " - " +
            currentScore[3];

        DrawText(firstLineText.c_str(), 15, 130+(80*i), 22, WHITE);
        DrawText(secondLineText.c_str(), 15, 150+(80*i), 22, WHITE);
    }

    if(IsKeyPressed(KEY_ESCAPE) || checkDrawButton("RETORNAR", quitButton)){
        gameState = MENUPAGE;
    }
    BeginDrawing();
    EndDrawing();
}