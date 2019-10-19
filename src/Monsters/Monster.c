//
//  Monster.c
//  Clonémon
//
//  Created by Bastian Inuk Christensen on 17/10/2019.
//  Copyright © 2019 Inuk Entertainment. All rights reserved.
//

#include "Monster.h"

MonsterType green;

MonsterFamily tingleMon = {.type = &green,
                           .baseDefence = 5,
                           .baseHP = 5,
                           .name = "Tinglemon"};

Attack skratch = {.type = &green, .attack = 2, .name = "Skratch"};
