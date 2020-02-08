#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <fstream>
#include "gotoxy.h"
#define MAX_ROWS 5
#define BOARD_START_Y 13

class Board
{
private:
	int stickarr[MAX_ROWS];

public:

	Board();
	void Remve(int row, int stick_num); //removes stick_num of stick from the selcted row
	bool CheckWin(); 
	void UpdateBoard(); //prints the current state of the board out
	inline int GetStickNum(int row)//returns current number of srtick in this row
	{
		return stickarr[row];
	}
};

#endif

