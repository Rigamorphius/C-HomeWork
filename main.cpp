#include <iostream>
#include <ctime>
//#include "stdafx.h"
using namespace std;

const int rows = 20;
const int columns = 20;
int maxships;
int matrix[rows][columns];

void Clearboard() {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] = 0;
		}
	}
}

void Buildboard() {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << endl;
	}
}

int ShipNum() {
	int c = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j] == 1) {
				c++;
			}
		}
	}
	return c;
}

void Setships() {
	int s = 0;
	while (s < maxships) {
		int x = rand() % rows;
		int y = rand() % columns;
		if (matrix[x][y] != 1) {
			s++;
			matrix[x][y] = 1;
		}
	}
}

bool Attack(int x, int y) {
	if (matrix[x][y] == 1) {
		matrix[x][y] = 2;
		return true;
	}
	return false;
}

bool NearMiss(int x, int y) {
	if (matrix[x - 1][y] == 1 || matrix[x + 1][y] == 1 || matrix[x][y - 1] == 1 || matrix[x][y + 1] == 1 || matrix[x - 1][y - 1] == 1 || matrix[x + 1][y + 1] == 1 || matrix[x- 1][y + 1] == 1 || matrix[x + 1][y - 1] == 1) {
		return true;
	}
	return false;
}

int main()
{
	char prompt;
	int pos1, pos2;
	srand(time(NULL));
	Clearboard();
	cout << "Welcome to Battleship, the board is a 20X20 size!\nWhen placing positions please add a space between numbers!\n";
	cout << "How many ships will you play with?\n"; cin >> maxships;
	Setships();
	while (1) {
		cout << "Please input location (0-19)\n"; cin >> pos1 >> pos2;
		if (Attack(pos1, pos2)) {
			cout << "Hit!" << endl;
			cout << "Number of ships left: " << ShipNum() << endl;
		} else if(NearMiss(pos1, pos2)){
			cout << "Near Miss!" << endl;
			cout << "Number of ships left: " << ShipNum() << endl;
		}
		else {
		cout << "Miss!" << endl;
			cout << "Number of ships left: " << ShipNum() << endl;
		}
		
		if (ShipNum() < 5) {
			cout << "Surrender? (y/n)"; cin >> prompt;
			if (prompt == 'y') {
				cout << "Game Over! You Lose!" << endl;
				Buildboard();
				break;
			}
			else if (ShipNum() == 0) {
				cout << "Game Over! You Win!" << endl;
				Buildboard();
				break;
			}
		}
	}
	return 0;
}
