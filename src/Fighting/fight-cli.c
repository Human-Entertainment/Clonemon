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
    int choice;
    
    printf("You: %s\n", you->name);
    printf("Oponent: %s\n", oponent->name);
    printf("Actions:\n");
    printf("1: Attack\n");
    printf("Choice: ");
    scanf("‰d", choice);
    printf("%i\n", choice);
    
    if (choice==1){
            for (int i = 0; i < 4; i++){
                if (you->attacks[i]){
                    printf("%i: %s\n", i+1 , you->attacks[i]->name);
                } else {
                    printf("%i: No attack here \n", i+1);
                }
            }
    } else {
        printf("I asked you to make a choice\n");
        
    }
    
    if (you->HP <= 0 || oponent->HP <= 0)
    {
        running = 0;
    }
    
}

int main(){
    Monster you;
    Monster oponent;
    
    you.family = tingleMon;
    you.name = you.family.name;
    you.HP = you.family.baseHP + 5;
    
    oponent.family = tingleMon;
    oponent.name = oponent.family.name;
    oponent.HP = oponent.family.baseHP + 5;
    
    while (running) {
        game(&you, &oponent);
    }
    return 0;
}

