#ifndef player_h
#define player_h

#include "ship.h"
#include "map.h"

using namespace std;

class Player {
public:
    Ship* ship1;
    Ship* ship2;
    Ship* ship3;
    Ship* ship4;
    Ship* ship5;
    string name;
    int getGuessX();
    int getGuessY();
    string getName();
    Ship* createShip(int shipNumber, int length, map* map);
    
};

bool intersectionCheck(string position, string orientation, int length, map *map);
bool boundaryCheck(string position, string orientation, int length);

Ship* Player::createShip(int shipNumber, int length, map* map) {
    cout << "What position do you want to put your " << length <<" length ship at? (enter a capital letter and a digit ex: D7): "<< endl;
    string position;
    cin >> position;
    
    while(position.length() > 2 || position.length() < 2) {
        cout << "Incorrect Coordinate Input" << endl;
        
        cout << "What position do you want to put your " << length <<" length ship at? (enter a capital letter and a digit ex: D7): "<< endl;
        cin >> position;
    }
    
    //Coordinate check
    
    cout << "What orientation do you want to put your ship at? (up, down, left, right)" << endl;
    string orientation;
    cin >> orientation;
    
    while(orientation != "right" && orientation != "left" && orientation != "up" && orientation != "down") {
        cout << "Incorrect Orientation Input" << endl;
        
        cout << "What orientation do you want to put your ship at? (up, down, left, right)" << endl;
        cin >> orientation;
    }
    
    while(intersectionCheck(position, orientation, length, map) || boundaryCheck(position, orientation, length)){
        cout << "Incorrect Placement" << endl;
        
        cout << "What position do you want to put your " << length <<" length ship at? (enter a capital letter and a digit ex: D7): "<< endl;
        cin >> position;
        
        while(position.length() > 2 || position.length() < 2) {
            cout << "Incorrect Coordinate Input" << endl;
            
            cout << "What position do you want to put your " << length <<" length ship at? (enter a capital letter and a digit ex: D7): "<< endl;
            cin >> position;
        }
        
        //Coordinate check
        
        cout << "What orientation do you want to put your ship at? (up, down, left, right)" << endl;
        cin >> orientation;
        
        while(orientation != "right" && orientation != "left" && orientation != "up" && orientation != "down") {
            cout << "Incorrect Orientation Input" << endl;
            
            cout << "What orientation do you want to put your ship at? (up, down, left, right)" << endl;
            cin >> orientation;
        }

    }
    
    Ship* ship = new Ship(shipNumber, position, length, orientation);
    placeShip(ship, map, shipNumber);
    
    return ship;
}

bool boundaryCheck(string position, string orientation, int length) {
    int coordinate[2];
    char column, row;
    
    column = position.at(0);
    row = position.at(1);
    
    coordinate[1] = toupper(column) - 0x41;   // First argument must be a char A-J. Subtract
    // 0x41 to get int value for array indexing.
    // Refer to ASCII table.
    coordinate[0] = row - 0x30;    // Second argument must be a char 1-10. Subtract
    // 0x31 to get int value for array indexing.
    // Refer to ASCII table.
    
    
    if(orientation == "left")
    {
        if ((coordinate[1] - length) < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(orientation == "right")
    {
        if ((coordinate[1] + length) > 10)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(orientation == "up")
    {
        if ((coordinate[0] - length) < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(orientation == "down")
    {
        if ((coordinate[0] + length) > 10)
        {
            return true;
        }
        else
        {
            return false;
        }
    }else {
        return true;
    }
}

bool intersectionCheck(string position, string orientation, int length, map *map) {
    int coordinate[2];
    char column, row;
    
    column = position.at(0);
    row = position.at(1);
    
    coordinate[1] = toupper(column) - 0x41;   // First argument must be a char A-J. Subtract
    // 0x41 to get int value for array indexing.
    // Refer to ASCII table.
    coordinate[0] = row - 0x30;    // Second argument must be a char 1-10. Subtract
    // 0x31 to get int value for array indexing.
    // Refer to ASCII table.
    
    for(int i=0; i<length; i++) {
        if(map->mapArray[coordinate[0]][coordinate[1]] != '~') {
            return true;
        }
        coordinate[1]++;
    }
    return false;
}

int Player::getGuessX() {
    cout << "Enter your guess for the x coordinate: " << endl;
    int x;
    cin >> x;
    
    return x;
}

int Player::getGuessY() {
    
    cout << "Enter your guess for the y coordinate: " << endl;
    int y;
    cin >> y;
    
    return y;
}

string Player::getName() {
    
    cout << "Enter your name: " << endl;
    string name;
    cin >> name;
    
    return name;
}
#endif /* player_h */
