#pragma once
#include <string>
#include <iostream>
#include <cstdlib>

class AI : public player {
	string difficulty;

}
int[][]generatesmap() {

}
int[]generateguess(str difficulty, string[][]guessMap) {
	if (difficulty == Easy) {
		int coordinateX = rand() % 10;
		int coordinateY = rand() % 10;
		int guess[2];
			while (guessMap[coordinateX][coordinateY]!=~) {
				int coordinateX = rand() % 10;
				int coordinateY = rand() % 10;
			}
			int guess[0] = coordinateX;
			int guess[1] = coordinateY;
			return guess;

	}
	if (difficulty == Medium) {
		int guess[2];
		int[][] potentialList = new int [15][2];
		int c = 0;
		for (int i = 0; i < guessMap.size; i++) {
			for (int j = 0; j < guessMap[i].size; j++) {
				if (guessMap[i][j] = "*") {
					if (guessMap[i][j + 1] == "~") {
						potentialList[c][0] = i;
						potentialList[c][1] = j + 1;
						c++;
					}
					if (guessMap[i][j -1] == "~") {
						potentialList[c][0] = i;
						potentialList[c][1] = j -1;
						c++;
					}
					if (guessMap[i+1][j] == "~") {
						potentialList[c][0] = i+1;
						potentialList[c][1] = j ;
						c++;
					}
					if (guessMap[i-1][j] == "~") {
						potentialList[c][0] = i-1;
						potentialList[c][1] = j ;
						c++;
					}

				}
			}
		}


		if (potentialList[0][0]==NULL){
		int coordinateX = rand() % 10;
		int coordinateY = rand() % 10;
		while (guessMap[coordinateX][coordinateY] != "~") {
			int coordinateX = rand() % 10;
			int coordinateY = rand() % 10;
		}
		int guess[0] = coordinateX;
		int guess[1] = coordinateY;
		return guess;
	}
		else {
			int counter;
			for (int k = 0; k <= 14; k++) {
				if (potentialList[k][0]!=NULL) {
					counter++;

				}
			}
		}
				 
	}
	if (difficulty == Hard) {
		int coordinateX = rand() % 10;
		int coordinateY = rand() % 10
			if (hit == true && ship != sunk) {
				if (map[][] == ~) {

				}

			}
	}
}