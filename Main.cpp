#include "Board.h"
#include "Player.h"
int main()
{
	Player* player=new Player();
	player->Menu();
	Board* game_board = new Board();
	game_board->UpdateBoard();//the board is printed for the first time
	while (!game_board->CheckWin())//playing until game over
	{
		player->Play(game_board);
	}
	//game over screen
	system("cls");
	if (player->GetCurrentPlayer() == 1)
	{
		std::ifstream filep1("player2win.txt");
		std::cout << filep1.rdbuf();
		filep1.close();

	}
	else
	{
		std::fstream filep2("player1win.txt");
		if (filep2.good())
		{
			std::cout << filep2.rdbuf();
		}
		filep2.close();
	}
	std::cout << std::endl;
	system("pause");
	delete player;
	delete game_board;
	return 0;
}