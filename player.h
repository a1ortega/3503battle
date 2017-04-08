#include "ship.h"
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
	void createShipArray();
	Ship* createShip(int shipNumber, int length);

};
