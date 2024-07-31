#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printGrid(char grid[3][3]) {
	cout << "-------------" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "| ";
		for (int j = 0; j < 3; ++j) {
			cout << grid[i][j] << " | ";
		}
		cout << endl << "-------------" << endl;
	}
}

bool winGridCheck(char grid[3][3], char player) {
	for (int i = 0; i < 3; ++i) {
		if ((grid[i][0] == player && grid[i][1] == player
				&& grid[i][2] == player)
				|| (grid[0][i] == player && grid[1][i] == player
						&& grid[2][i] == player)) {
			return true;
		}
	}
	if ((grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
			|| (grid[0][2] == player && grid[1][1] == player
					&& grid[2][0] == player)) {
		return true;
	}
	return false;
}

bool fullGridCheck(char grid[3][3]) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (grid[i][j] == ' ')
				return false;
		}
	}
	return true;
}

void moveAI(char grid[3][3]) {
	srand(time(0));
	int row, col;
	do {
		row = rand() % 3;
		col = rand() % 3;
	} while (grid[row][col] != ' ');
	grid[row][col] = 'O';
}

int main() {
	char grid[3][3] =
			{ { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };

	cout << "Welcome to AI Tic Tac Toe!\n" << endl;
	cout << "You are X and the AI is O\n" << endl;

	int row, col;
	char currentPlayer = 'X';

	while (true) {
		printGrid(grid);

		cout << "\nEnter row (1-3) and column (1-3): ";
		cin >> row >> col;
		row--;
		col--;

		if (row >= 0 && row < 3 && col >= 0 && col < 3
				&& grid[row][col] == ' ') {
			grid[row][col] = currentPlayer;

			if (winGridCheck(grid, currentPlayer)) {
				printGrid(grid);
				cout << "You win!" << endl;
				break;
			}

			if (fullGridCheck(grid)) {
				printGrid(grid);
				cout << "Draw Game!" << endl;
				break;
			}

			currentPlayer = 'O';

			moveAI(grid);

			if (winGridCheck(grid, 'O')) {
				printGrid(grid);
				cout << "AI wins!" << endl;
				break;
			}

			if (fullGridCheck(grid)) {
				printGrid(grid);
				cout << "Draw Game!" << endl;
				break;
			}

			currentPlayer = 'X';
		} else {
			cout << "Invalid Move!" << endl;
		}
	}

	cout << "Thanks for playing AI Tic Tac Toe!" << endl;

	return 0;
}
