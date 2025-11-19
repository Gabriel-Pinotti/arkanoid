#ifndef BALL
#define BALL
#include "raylib.h"
#include "global.h"

struct Ball {
    bool active = false;
    int radius = 10;
    Vector2 speed = {0, 0};
    Vector2 position = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
};

extern Ball ball;
extern int localStoredTime;

void moveBall();

void ball_collision();

void drawBall();

#endif