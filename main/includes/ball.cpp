#include "ball.h"
#include "raylib.h"
#include "math.h"
#include "paddle.h"
#include "bricks.h"

// ----- Main declaration -----
Ball ball;

void moveBall(){
    if (!ball.active) {
        if (IsKeyPressed(KEY_SPACE)){
            ball.active = true;
            ball.speed = (Vector2){0, -5}; // TODO make {0, -5}, {0, -6.25} or {0, -7.5} when launching (based on difficulty)
        }
        ball.position = (Vector2){ paddle.position.x, paddle.position.y - paddle.size.y/2 - ball.radius };
    } 
    if (ball.active) {
        ball.position.x += ball.speed.x;
        ball.position.y += ball.speed.y;
    }
}

void ball_collision(){

    // ball x walls collision

    if (((ball.position.x + ball.radius) >= SCREEN_WIDTH) || ((ball.position.x - ball.radius) <= 0)) { // left and right
        ball.speed.x *= -1;
    }
    if ((ball.position.y - ball.radius) <= 0) { // up
        ball.speed.y *= -1;
    }
    if ((ball.position.y + ball.radius) >= SCREEN_HEIGHT) { // down
        // TODO add logic to floor collision
    }


    // ball x paddle collision

    if (CheckCollisionCircleRec(ball.position, ball.radius,
        (Rectangle){ paddle.position.x - paddle.size.x/2, paddle.position.y - paddle.size.y/2, paddle.size.x, paddle.size.y}))
    {
        if (ball.speed.y > 0) {
            ball.speed.y *= -1;
            ball.speed.x = (ball.position.x - paddle.position.x)/(paddle.size.x/2)*5;
        }
    }


    // ball x bricks collision

    for (int i = 0; i < brickRows; i++) {
        for (int j = 0; j < bricksPerRow; j++) {
            if (brick[i][j].health >= 1) {
                // Hit below
                if (((ball.position.y - ball.radius) <= (brick[i][j].position.y + brick[i][j].size.y/2)) &&
                    ((ball.position.y - ball.radius) > (brick[i][j].position.y + brick[i][j].size.y/2 + ball.speed.y)) &&
                    ((fabs(ball.position.x - brick[i][j].position.x)) < (brick[i][j].size.x/2 + ball.radius*2/3)) && (ball.speed.y < 0))
                {
                    brick[i][j].health -= 1;
                    if (brick[i][j].health == 0){
                        points +=2;
                        // TODO add here the possibility of dropping items
                    }
                    points +=1;
                    ball.speed.y *= -1;
                }
                // Hit above
                else if (((ball.position.y + ball.radius) >= (brick[i][j].position.y - brick[i][j].size.y/2)) &&
                        ((ball.position.y + ball.radius) < (brick[i][j].position.y - brick[i][j].size.y/2 + ball.speed.y)) &&
                        ((fabs(ball.position.x - brick[i][j].position.x)) < (brick[i][j].size.x/2 + ball.radius*2/3)) && (ball.speed.y > 0))
                {
                    brick[i][j].health -= 1;
                    if (brick[i][j].health == 0){
                        points +=2;
                    }
                    points +=1;
                    ball.speed.y *= -1;
                }
                // Hit left
                else if (((ball.position.x + ball.radius) >= (brick[i][j].position.x - brick[i][j].size.x/2)) &&
                        ((ball.position.x + ball.radius) < (brick[i][j].position.x - brick[i][j].size.x/2 + ball.speed.x)) &&
                        ((fabs(ball.position.y - brick[i][j].position.y)) < (brick[i][j].size.y/2 + ball.radius*2/3)) && (ball.speed.x > 0))
                {
                    brick[i][j].health -= 1;
                    if (brick[i][j].health == 0){
                        points +=2;
                    }
                    points +=1;
                    ball.speed.x *= -1;
                }
                // Hit right
                else if (((ball.position.x - ball.radius) <= (brick[i][j].position.x + brick[i][j].size.x/2)) &&
                        ((ball.position.x - ball.radius) > (brick[i][j].position.x + brick[i][j].size.x/2 + ball.speed.x)) &&
                        ((fabs(ball.position.y - brick[i][j].position.y)) < (brick[i][j].size.y/2 + ball.radius*2/3)) && (ball.speed.x < 0))
                {
                    brick[i][j].health -= 1;
                    if (brick[i][j].health == 0){
                        points +=2;
                    }
                    points +=1;
                    ball.speed.x *= -1;
                }
            }
        }
    }
}