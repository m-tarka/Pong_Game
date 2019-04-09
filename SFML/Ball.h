#pragma once
#include "Player.h"
#include "Score.h"
#include "game_state.h"
#include "End.h"

class Ball : public Element
{
private:
	Player * player1, *player2;
	Score* score;
public:
	Ball(Player* p1, Player* p2, Score* s1);
	void Update();
};
