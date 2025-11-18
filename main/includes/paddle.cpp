#include "raylib.h"
#include "global.h"
#include "paddle.h"
#include "textures.h"

Paddle paddle;

void paddle_wall_collision(){
    if ((paddle.position.x - paddle.size.x/2) <= 0) {
        paddle.position.x = paddle.size.x/2;
    }
    if ((paddle.position.x + paddle.size.x/2) >= SCREEN_WIDTH) {
        paddle.position.x = SCREEN_WIDTH - paddle.size.x/2;
    }
}

void movePaddle(float &ft){
    char direction;
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
        direction = 'r';
    }
    else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
        direction = 'l';
    }
    else {
        direction = 's';
    }

    switch (direction){ 
        case 'l':
            paddle.position.x-=paddle.speed * ft;
            break;
        case 'r':
            paddle.position.x+=paddle.speed * ft;
            break;
        case 's':
            break;
    }
}

void drawPaddle(){
    DrawTexture(paddle_texture, paddle.position.x-paddle.size.x/2, paddle.position.y-paddle.size.y/2, WHITE);
}
