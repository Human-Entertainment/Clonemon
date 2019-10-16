#include <stdio.h>
#include <stdlib.h>

#include "Player/Player.h"

typedef enum PlayerDirection BallYDirection;
typedef enum ballXDirection {left, right} BallXDirection;



typedef enum state{playerRightWon, playerLeftWon, running} State;

State gameState = running;

typedef struct ball{
    SDL_Rect ball;
    BallYDirection yDir;
    BallXDirection xDir;
} Ball;

int done;

int speed = 5;

/* Call this instead of exit(), so we can clean up SDL: atexit() is evil. */
static void quit(int rc)
{
    SDL_Quit();
    exit(rc);
}

void movePlayer(Player *player){
    switch (player->direction) {
        case up:
            if (player->bat.y > 0){
                player->bat.y-=speed;
            }
            break;
            
        case down:
            if (player->bat.y < 400 - player->bat.h){
                player->bat.y+=speed;
            }
            break;
        case still:
            break;
    }
}

void moveBall(Ball *ball, const Player playerRight, const Player playerLeft){
    int ballSpeed = speed/2;
    if(ball->yDir == down && ball->ball.y < 400 - ball->ball.h){
        ball->ball.y+=ballSpeed;
        
        if (ball->ball.y == 400 - ball->ball.h - 1){
            ball->yDir = up;
        }
    }else if (ball->yDir == up && ball->ball.y > 0){
        ball->ball.y-=ballSpeed;
        
        if (ball->ball.y == 1){
            ball->yDir = down;
        }
    }
    
    if(ball->xDir == right && ball->ball.x < 640 - ball->ball.w){
        ball->ball.x+=ballSpeed;
    } else if (ball->xDir == left && ball->ball.x > 0){
        ball->ball.x-=ballSpeed;
    }
    
    if(ball->xDir == left &&
       ball->ball.x == playerLeft.bat.x + playerLeft.bat.w &&
       ball->ball.y > playerLeft.bat.y - ball->ball.h &&
       ball->ball.y < playerLeft.bat.y + playerLeft.bat.h + ball->ball.h)
    {
        ball->xDir = right;
    } else if (ball->ball.x <= playerLeft.bat.x + playerLeft.bat.w){
        gameState = playerRightWon;
    } else if(ball->xDir == right &&
       ball->ball.x == playerRight.bat.x - ball->ball.w &&
       ball->ball.y > playerRight.bat.y - ball->ball.h &&
       ball->ball.y < playerRight.bat.y + playerRight.bat.h + ball->ball.h)
    {
        ball->xDir = left;
    } else if(ball->ball.x >= playerRight.bat.x - ball->ball.w){
        gameState = playerLeftWon;
    }
}

int main(int argc, char *argv[])
{
    SDL_Window *window;

    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s\n", SDL_GetError());
        return (1);
    }

    /* Set 640x480 video mode */
    window = SDL_CreateWindow("Pong-ish",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 400, 0);
    if (!window)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create 640x480 window: %s\n",
                SDL_GetError());
        quit(2);
    }

    /* Watch keystrokes */
    done = 0;
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    
    SDL_Rect leftBat = { .x = 10, .y = 175, .h = 50, .w = 8 };
    SDL_Rect rightBat = { .x = 640 - 10 - 8, .y = 175, .h = 50, .w = 8 };
    SDL_Rect ballRect ={ .x = 640/2, .y = 400/2 - 5, .h = 10, .w = 10};
    
    Player playerRight;
    playerRight.bat = rightBat;
    playerRight.player = two;
    playerRight.direction = still;
    
    Player playerLeft;
    playerLeft.bat = leftBat;
    playerLeft.player = one;
    playerLeft.direction = still;
    
    Ball ball;
    ball.ball = ballRect;
    ball.yDir = down;
    ball.xDir = right;
    
    while (!done)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear( renderer );
        
        SDL_Event event;
        
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_UP)
                {
                    playerRight.direction = up;
                }
                else if (event.key.keysym.sym == SDLK_DOWN)
                {
                    playerRight.direction = down;
                }
                if (event.key.keysym.sym == 'w') {
                    playerLeft.direction=up;
                } else if (event.key.keysym.sym == 's') {
                    playerLeft.direction=down;
                }
                break;
            case SDL_KEYUP:
                if(event.key.keysym.sym == 'w' | event.key.keysym.sym == 's'){
                    playerLeft.direction=still;
                }
                if ((event.key.keysym.sym == SDLK_UP && playerRight.direction == up) || (event.key.keysym.sym == SDLK_DOWN && playerRight.direction == down)) {
                    playerRight.direction=still;
                }
                break;
            case SDL_QUIT:
                    printf("QUIT!");
                done = 1;
                break;
            default:
                break;
            }
        }
        
        SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
        
        movePlayer(&playerRight);
        movePlayer(&playerLeft);
        moveBall(&ball, playerRight, playerLeft);
        
        SDL_RenderFillRect(renderer, &playerRight.bat);
        SDL_RenderFillRect(renderer, &playerLeft.bat);
        SDL_RenderFillRect(renderer, &ball.ball);
        
        SDL_RenderPresent( renderer);
        if(gameState != running){
            done = 1;
        }
    }
    char *winner = NULL;
    switch (gameState) {
        case playerLeftWon:
            winner = "left";
            break;
            
        case playerRightWon:
            winner = "right";
            break;
        case running:
            printf("How did you get here?\nw");
            break;
    }
    printf("The player to the %s won!\n", winner);
    done = 1;
    SDL_Quit();
    return (0);
}

/* vi: set ts=4 sw=4 expandtab: */
