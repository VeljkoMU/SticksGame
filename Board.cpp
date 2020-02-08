#include "Board.h"

Board::Board()
{
	for (int i = 0; i < MAX_ROWS; i++)
		stickarr[i] = i + 1; //inicialize the board of stick, each row with one more stick
}

void Board::Remve(int row, int stick_num)
{
	stickarr[row] -= stick_num;
}

bool Board::CheckWin()
{
	int sum = 0;
	for (int i = 0; i < MAX_ROWS; i++)
		sum += stickarr[i];
	if (sum == 1)
		return true;
	else return false;
}

void Board::UpdateBoard()
{
	system("cls");
	//the rdges of the board
	gotoxy(1, BOARD_START_Y);
	std::cout << "***************************************";
	gotoxy(1, BOARD_START_Y + 11);
	std::cout<< "***************************************";
	/////////////////////////
	int xcod = 5;
	int ycod;
	for (int i = 0; i < MAX_ROWS; i++)//prints out each row of the bard wit hte current number of sticks
	{
		ycod = BOARD_START_Y + 2;
		for (int j = 0; j < stickarr[i]; j++)
		{
			gotoxy(xcod + (i * 5), ycod);
			std::cout << "-";
			ycod = ycod + 2;
		}
	}


	return;
}