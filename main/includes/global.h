#ifndef GLOBAL_DEFINITIONS
#define GLOBAL_DEFINITIONS
#include "raylib.h"

// ----- GLOBAL VARIABLES -----
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 700
// -- time
extern int baseTime;
extern double currentLevelTime;
// -- level specific
extern int points;
extern int lives;
extern int level;
// -- menu and selections
extern int difficulty;
enum game_state_selection {
    MENUPAGE,
    GAME,
    ENDGAME,
    RANKING
};
extern game_state_selection gameState;

// ----- GLOBAL FUNCTIONS -----
void game_movements(float &ft);

void game_collisions();

void game_draw();

void initializeGame();

#endif