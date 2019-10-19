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

typedef struct monsterType {
    /** The Monster Type this  gets a lot a of damage by */
    struct monsterType* weakAgainst;
    /** The monster type this doesn't get dealt a lot of damage by */
    struct monsterType* strongAgainst;
    char* name;
}MonsterType;

/// The attack type
typedef struct attack{
    MonsterType type;
    int attack;
} Attack;

/// The type of the monster
typedef struct monsterFamily{
    MonsterType* type;
    Attack* attacks [4];
    int baseDefence;
    int baseHP;
    char* name;
} MonsterFamily;

typedef struct monster {
    MonsterFamily family;
    char* name;
} Monster;

MonsterFamily tingleMon;




#endif /* Monster_h */
