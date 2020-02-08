#ifndef PLAYER_H
#define PLAYER_H
#include"Board.h"

class Player
{
private:
	char current_player;

public:
	Player();
	inline char GetCurrentPlayer() { return current_player; }
	inline void ChangePlayer() { current_player = -current_player; }//changes tghe player's turns codded with 1 and -1
	void Menu();
	void Play(Board* game_board);
	void PrintRules();
};

#endif
