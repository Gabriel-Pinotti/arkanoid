#include "bricks.h"
#include "raylib.h"
#include "global.h"
#include "textures.h"

Brick brick[brickRows][bricksPerRow];

void initializeBricks(){
    float x_margins = 30; // blocks are 68x40px
    float y_margin = 55;
    float brick_y = 35;
    float brick_x = (SCREEN_WIDTH-(2*x_margins))/bricksPerRow;

    for (int i = 0; i < brickRows; i++) {
        for (int j = 0; j < bricksPerRow; j++) {
            brick[i][j].size = {brick_x, brick_y};
            brick[i][j].position = { (j*brick[i][j].size.x + brick[i][j].size.x/2)+x_margins, i*brick[i][j].size.y + y_margin };
            brick[i][j].health = 6; // TODO randomize with a recursive function, based on difficulty and level
        }
    }
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