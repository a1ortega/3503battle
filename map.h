//
//  map.h
//  battle_ship_1
//
//  Created by Evan Waxman on 3/22/17.
//  Copyright © 2017 Evan Waxman. All rights reserved.
//

#ifndef map_h
#define map_h

#include <stdio.h>
#include <iostream>
#include "ship.h"

using namespace std;

class map {
public:
    map();
    const static int size = 10;     // Size won't ever change
    char mapArray[size][size];
    void printMap(map *player1ships, map *player1guesses);
    bool hitCheck(map *guessMap, int coordinate[]);
    bool guessCheck(int coordinate[]);
    void placeShip(Ship *ship, map *shipMap, char counter);
};

// Constructor for map object
map::map() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mapArray[i][j] = '~';       // Default map element value is ~
        }
    }
}

// Checks if coordinate was already guessed
bool map::guessCheck(int coordinate[]) {
    if(mapArray[coordinate[0]][coordinate[1]] == 'X' || mapArray[coordinate[0]][coordinate[1]] == 'O') {    // Only other values for guess map
        return 1;
    }else {
        return 0;
    }
}

// Checks if ship was hit
bool map::hitCheck(map *guessMap, int coordinate[2]) {
    if(mapArray[coordinate[0]][coordinate[1]] == '~'){
        guessMap->mapArray[coordinate[0]][coordinate[1]] = 'O';     // Update guess map
        return 0;
    }else {
        guessMap->mapArray[coordinate[0]][coordinate[1]] = 'X';     // Update guess map
        return 1;
    }
}

// Print mapArray of map
void printMap(map *player1ships, map *player1guesses) {
    for (int i = 0; i < player1guesses->size; i++) {
        for (int j = 0; j < player1guesses->size; j++) {
            cout << player1ships->mapArray[i][j] << " " ;
        }
        cout << " ";
        for(int j=0; j< player1guesses->size; j++){
            cout << player1guesses->mapArray[i][j]<< " ";
        }
        cout << endl;
    }
}

void placeShip(Ship *ship, map *shipMap, char counter) {
    int coordinate[2];
    for(int i=0; i<ship->length; i++) {
        coordinate[1] = toupper(ship->chunk[i].at(0)) - 0x41;   // First argument must be a char A-J. Subtract
                                                                // 0x41 to get int value for array indexing.
                                                                // Refer to ASCII table.
        coordinate[0] = ship->chunk[i].at(1) - 0x31;    // Second argument must be a char 1-10. Subtract
                                                        // 0x31 to get int value for array indexing.
                                                        // Refer to ASCII table.
        shipMap->mapArray[coordinate[0]][coordinate[1]] = counter;
    }
}


#endif /* map_h */

