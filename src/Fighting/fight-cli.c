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
    
    printf("You: %s HP: %d\n", you->name, you->HP);
    printf("Oponent: %s HP: %d\n", oponent->name, oponent->HP);
    printf("Actions:\n");
    printf("1: Attack\n");
    printf("Choice: ");
    scanf("%d", &choice);
    
    if (choice==1){
        // Print out attacks
        for (int i = 0; i < 4; i++){
            if (you->attacks[i]){
                printf("%i: %s\n", i+1 , you->attacks[i]->name);
                
            }
        }

        printf("Choice: ");
        scanf("%d", &choice);
        oponent->HP = attackNow(you->attacks[choice-1], oponent);
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
    
    you.family = &tingleMon;
    you.name = you.family->name;
    you.HP = you.family->baseHP + 5;
    you.attacks[0] = &skratch;
    
    oponent.family = &tingleMon;
    oponent.name = oponent.family->name;
    oponent.HP = oponent.family->baseHP + 5;
    you.attacks[0] = &skratch;
    
    while (running) {
        game(&you, &oponent);
    }
    return 0;
}

