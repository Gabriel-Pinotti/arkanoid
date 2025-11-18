#include "textures.h"

Texture2D game_background;
Texture2D paddle_texture;
Texture2D ball_texture;
Texture2D brick_1hp_texture;
Texture2D brick_2hp_texture;
Texture2D brick_3hp_texture;
Texture2D brick_4hp_texture;
Texture2D brick_5hp_texture;
Texture2D brick_6hp_texture;

void initializeTextures(){
    game_background = LoadTexture("../assets/backgrounds/game_background.png");
    paddle_texture = LoadTexture("../assets/paddles/paddle_normal_texture.png");
    ball_texture = LoadTexture("../assets/misc/ball_texture.png");
    brick_1hp_texture = LoadTexture("../assets/bricks/1hpbrick.png");
    brick_2hp_texture = LoadTexture("../assets/bricks/2hpbrick.png");
    brick_3hp_texture = LoadTexture("../assets/bricks/3hpbrick.png");
    brick_4hp_texture = LoadTexture("../assets/bricks/4hpbrick.png");
    brick_5hp_texture = LoadTexture("../assets/bricks/5hpbrick.png");
    brick_6hp_texture = LoadTexture("../assets/bricks/6hpbrick.png");
}