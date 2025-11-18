#ifndef BALL
#define BALL
#include "raylib.h"
#include "global.h"

struct Ball {
    int radius = 10;
    Vector2 speed = {0, -5};
    Vector2 position = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
};

extern Ball ball;

void moveBall();

void ball_collision();

#endif