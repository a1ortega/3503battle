#include "ship.h"
class Player {
public:
	string name;
	int getGuessX();
	int getGuessY();
	string getName();
	Ship** createShipArray();
	Ship* createShip(int shipNumber, int length);
};
