//
//  main.c
//  FightTest
//
//  Created by Bastian Inuk Christensen on 16/10/2019.
//  Copyright © 2019 Inuk Entertainment. All rights reserved.
//

#include <stdio.h>

#include "Fighting.h"

int running = 1;

void game(Monster* you, Monster* oponent){
    
    
    printf("%s\n%s\n", you->name, oponent->name);
    
}

int main(){
    Monster you;
    Monster oponent;
    
    you.family = tingleMon;
    you.name = you.family.name;
    
    oponent.family = tingleMon;
    oponent.name = oponent.family.name;
    
    while (running) {
        game(&you, &oponent);
    }
    return 0;
}

