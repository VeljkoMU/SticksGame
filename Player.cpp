#include "Player.h"
#include"Board.h"

Player::Player()
	:current_player(1)
{
}
void Player::Menu()
{
	while (true)
	{
		gotoxy(10, 10);
		std::cout << "1. Start Game";
		gotoxy(10, 11);
		std::cout << "2.Rules";
		gotoxy(10, 13);
		std::cout << "Enter a menu numberto pick:  ";
	 char choice;
		std::cin >> choice;
		switch (choice)
		{
		case '1':
			system("cls");
			return;
			break;
		case '2': 
			this->PrintRules();
			return;
			break;
		}
	}
}

void Player::Play(Board* game_board)
{
	//Indicates the currently playing player
	gotoxy(3, 2);
	std::cout << "Player ";
	if (current_player == -1)
		std::cout << 2;
	else
		std::cout << 1;
	/////////////////////////////////
	//player's turn
	gotoxy(5, 5);
	std::cout << "Select a row: ";
	int row, sticknum;
	std::cin >> row;
	if ((row > 5) || (row < 1))//seelcting an non-existant row leads to the player playing his turn again
	{
		game_board->UpdateBoard();
		return;
	}
	std::cout << "Enter the number of stick: ";
	std::cin >> sticknum;
	if (sticknum > game_board->GetStickNum(row-1))//if more than existing sticks are selected
	{
		game_board->UpdateBoard();
		return;
	}
	//stick removal and changing of players
	game_board->Remve(row-1, sticknum);
	game_board->UpdateBoard();
	this->ChangePlayer();
	return;
}

void Player::PrintRules()
{
	std::ifstream rulesfl("rules.txt");
	system("cls");
	if (rulesfl.good())
		std::cout << rulesfl.rdbuf();
		std::cout << std::endl;
	system("pause");
	rulesfl.close();
	return;
}