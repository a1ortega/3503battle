//
//  main.cpp
//  battle_ship_1
//
//  Created by Evan Waxman on 4/8/17.
//  Copyright © 2017 Evan Waxman. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "ship.h"
#include "map.h"
#include "player.h"

int main() {
    map player1ships;
    map player2ships;
    map player1guesses;
    map player2guesses;
    
    Player player1;
    Player player2;
    
    int sizeArray[5] = {2, 3, 3, 4, 5};
    
    for(int i=1; i<6; i++) {
        player1.createShip(i, sizeArray[i-1], &player1ships);
        printMap(&player1ships, &player1guesses); 
    }
    
    for(int i=1; i<6; i++) {
        player2.createShip(i, sizeArray[i-1], &player2ships);
        printMap(&player2ships, &player2guesses);
    }
    
/*
    Ship ship1(1,"D5", 5, "right");
    placeShip(&ship1, &player1ships, '1');
    printMap(&player1ships, &player1guesses);
 */
    return 0;
}
