#include <iostream>
#include <string>
#include "player.h"
using namespace std;

void Player::createShipArray() {

	this->ship1 = createShip(1, 5);
	this->ship2 = createShip(2, 4);
	this->ship3 = createShip(3, 3);
	this->ship4 = createShip(4, 3);
	this->ship5 = createShip(5, 2);
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

Player::Player() {

}