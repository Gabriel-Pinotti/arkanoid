#include "bricks.h"
#include "raylib.h"
#include "global.h"
#include "textures.h"
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>



Brick brick[brickRows][bricksPerRow];

void initializeBricks(){
    float x_margins = 30; // blocks are 68x40px
    float y_margin = 65;
    float brick_y = 35;
    float brick_x = (SCREEN_WIDTH-(2*x_margins))/bricksPerRow;
    
    for (int i = 0; i < brickRows; i++) {
        for (int j = 0; j < bricksPerRow; j++) {
            brick[i][j].size = {brick_x, brick_y};
            brick[i][j].position = { (j*brick[i][j].size.x + brick[i][j].size.x/2)+x_margins, i*brick[i][j].size.y + y_margin };
        }
    }
    srand(time(NULL)); // for random layouts of blocks health
    hitsRemaining = 0;
    setBricksHealth(0, 0); 
}

void setBricksHealth(int row, int col) {
    if (row >= brickRows) {
        return;
    }

    if (col >= bricksPerRow) {
        // next row, restarts column
        setBricksHealth(row + 1, 0);
        return;
    }

    float increaseFactor = (level * 0.05f) + (difficulty * 0.1f);
    
    float baseChanceForOne = 0.7f; // 70% base-chance for 1hp bricks
    float actualChanceForOne = baseChanceForOne - increaseFactor;

    if (actualChanceForOne < 0.1f) {
        actualChanceForOne = 0.1f;
    }

    float randomValue = ((float)rand() / (float)RAND_MAX);

    if (randomValue < actualChanceForOne) {
        brick[row][col].health = 1;
        hitsRemaining+=1;
    } else {
        float normalizedRandom = (randomValue - actualChanceForOne) / (1.0f - actualChanceForOne);
        float biasedRandom = powf(normalizedRandom, 1.0f - increaseFactor); 

        int range = 5;
        
        int calculatedHealth = (int)floorf(biasedRandom * (float)range) + 2;

        if (calculatedHealth > 6) {
            calculatedHealth = 6;
        }

        brick[row][col].health = calculatedHealth;
        hitsRemaining+=calculatedHealth;
    }

    setBricksHealth(row, col + 1);
}

void drawBricks(){
    for (int i = 0; i < brickRows; i++){
        for (int j = 0; j < bricksPerRow; j++)
        {
            if (brick[i][j].health == 1){
                DrawTexture(brick_1hp_texture, brick[i][j].position.x-brick[i][j].size.x/2, brick[i][j].position.y-brick[i][j].size.y/2, WHITE);
       
            }
            if (brick[i][j].health == 2){
                DrawTexture(brick_2hp_texture, brick[i][j].position.x-brick[i][j].size.x/2, brick[i][j].position.y-brick[i][j].size.y/2, WHITE);
       
            }
            if (brick[i][j].health == 3){
                DrawTexture(brick_3hp_texture, brick[i][j].position.x-brick[i][j].size.x/2, brick[i][j].position.y-brick[i][j].size.y/2, WHITE);
       
            }
            if (brick[i][j].health == 4){
                DrawTexture(brick_4hp_texture, brick[i][j].position.x-brick[i][j].size.x/2, brick[i][j].position.y-brick[i][j].size.y/2, WHITE);
       
            }
            if (brick[i][j].health == 5){
                DrawTexture(brick_5hp_texture, brick[i][j].position.x-brick[i][j].size.x/2, brick[i][j].position.y-brick[i][j].size.y/2, WHITE);
       
            }
            if (brick[i][j].health == 6){
                DrawTexture(brick_6hp_texture, brick[i][j].position.x-brick[i][j].size.x/2, brick[i][j].position.y-brick[i][j].size.y/2, WHITE);
       
            }
        }
        
    }
};