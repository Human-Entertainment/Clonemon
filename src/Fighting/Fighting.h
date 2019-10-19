//
//  Fighting.h
//  Clonémon
//
//  Created by Bastian Inuk Christensen on 16/10/2019.
//  Copyright © 2019 Inuk Entertainment. All rights reserved.
//

#ifndef Fighting_h
#define Fighting_h

//#include "Player.h"
#include "Monster.h"

/// Reduces the HP of monsther getting attacked appropriate to type and attack stats.
int attackNow(const Attack* attack, Monster* attackee);

#endif /* Fighting_h */
