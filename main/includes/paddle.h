#ifndef PADDLE
#define PADDLE
#include "raylib.h"
#include "global.h"

struct Paddle {
    int speed = 250;
    Vector2 size = {150, 20};
    Vector2 position = {((SCREEN_WIDTH/2)), 650};
};

extern Paddle paddle;

void paddle_wall_collision(Vector2 &paddle_position);

void movePaddle(float &ft);

#endif