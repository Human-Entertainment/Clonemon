//
//  Player.h
//  SDLTest
//
//  Created by Bastian Inuk Christensen on 15/10/2019.
//  Copyright © 2019 Inuk Entertainment. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <stdio.h>

#include <SDL2/SDL.h>


enum PlayerNumber {one,two};
enum PlayerDirection {up, down, still};

typedef struct player {
    SDL_Rect bat;
    enum PlayerNumber player;
    enum PlayerDirection direction;
} Player;


#endif /* Player_h */
