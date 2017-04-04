
#include <string>
#include "player.h"
using namespace std;

Ship** Player::createShipArray() {
	Ship** shipArray = new Ship*[5];
	shipArray[0] = createShip(1, 5);
	shipArray[1] = createShip(2, 4);
	shipArray[2] = createShip(3, 3);
	shipArray[3] = createShip(4, 3);
	shipArray[4] = createShip(5, 2);

	return shipArray;
}

Ship* Player::createShip(int shipNumber, int length) {
	cout << "What position do you want to put your " << length <<" length ship at? (enter a capital letter and a digit ex: D7): ";
	string position;
	cin >> position;

	//Coordinate check

	cout << "What orientation do you want to put your ship at? (up, down, left, right)";
	string orientation;
	cin >> orientation;

	Ship* ship = new Ship(shipNumber, position, length, orientation);
	return ship;
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

Player::Player(){
	name = getName();
	shipArray = createShipArray();
}
