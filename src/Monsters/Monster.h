//
//  Monster.h
//  Clonémon
//
//  Created by Bastian Inuk Christensen on 17/10/2019.
//  Copyright © 2019 Inuk Entertainment. All rights reserved.
//

#ifndef Monster_h
#define Monster_h

#include <stdio.h>

typedef enum type{rock, paper, scissor} Type;

/// The attack type
typedef struct attack{
    Type type;
    int attack;
} Attack;

/// The type of the monster
typedef struct monster{
    Type type;
    Attack* attacks [4];
    int defence;
    int hp;
    char* name;
} Monster;

#endif /* Monster_h */
