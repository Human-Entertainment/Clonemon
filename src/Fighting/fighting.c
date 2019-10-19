#include "Fighting.h"

/// Reduces the HP of monsther getting attacked appropriate to type and attack stats.
int attackNow(const Attack* attack, Monster* attackee){
    if (attackee->family->type->weakAgainst == attack->type){
        return attackee->HP - attack->attack * 1.5;
    } else if (attackee->family->type->strongAgainst == attack->type){
        return attackee->HP - attack->attack * 0.5;
    } else {
        return attackee->HP - attack->attack;
    }
}
