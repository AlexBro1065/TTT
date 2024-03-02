#include <iostream>
#include <io.h>
#include <fcntl.h>
using namespace std;
void drawBoard(char board[3][3])

{
	cout << "-------------\n";
	for (int i = 0; i < 3; i++) {
		cout << "| ";
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << " | ";
		}
		cout << "\n-------------\n";
	}
}

bool checkWin(char board[3][3], char player)
{
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == player && board[i][1] == player
			&& board[i][2] == player)
			return true;
		if (board[0][i] == player && board[1][i] == player
			&& board[2][i] == player)
			return true;
	}
	if (board[0][0] == player && board[1][1] == player
		&& board[2][2] == player)
		return true;
	if (board[0][2] == player && board[1][1] == player
		&& board[2][0] == player)
		return true;
	return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");
	char board[3][3] = { { ' ', ' ', ' ' },
						{ ' ', ' ', ' ' },
						{ ' ', ' ', ' ' } };
	char player = 'X';
	int row, col;
	int turn;
	wcout << "Крестики нолики на двоих.\n";

	for (turn = 0; turn < 9; turn++) {
		drawBoard(board);

		while (true) {

			wcout << "Игрок " << player
				<< ", выберите сначала вашу клетку по горизонту, затем по вертикали!(Подсказка - выбор от 0 до 2): ";
			cin >> row >> col;

			if (board[row][col] != ' ' || row < 0 || row > 2
				|| col < 0 || col > 2) {
				wcout << "Клетка занята\n";
			}
			else {
				break;
			}
		}


		board[row][col] = player;


		if (checkWin(board, player)) {
			drawBoard(board);
			wcout << "Игрок " << player << " ПОБЕЖДАЕТ!!!\n";
			break;

		}


		player = (player == 'X') ? 'O' : 'X';
	}


	drawBoard(board);
	if (turn == 9 && !checkWin(board, 'X')
		&& !checkWin(board, 'O')) {
		wcout << "Оу... А похоже у нас ничья! Переигрывайте.\n";
	}

	return 0;
}
