#include "stdafx.h"
#include "Ball.h"

Ball::Ball(Player* p1, Player* p2, Score* s)
{
	player1 = p1;
	player2 = p2;
	ballVelocity = 1.0f;
	velocity.x = ballVelocity;
	velocity.y = ballVelocity;
	Load("ball2.png");

	score = s;
}

void Ball::Update()
{
	Element::Update();

	if (CheckCrash(player1) || CheckCrash(player2))
	{
		velocity.x = - velocity.x;
	}


	if (getPosition().y < 0 || getPosition().y + getGlobalBounds().height > 632)
	{
		velocity.y = -velocity.y;
	}

	if (score->getScore1() == score->max)
	{
		main_state.SetState(new End(score));
	}
	else if (score->getScore2() == score->max)
	{
		main_state.SetState(new End(score));
	}
	else if (getPosition().x < 0 )
	{
		score->Score2Update();
		setPosition(1127 / 2, 632 / 2);
		player1->setPosition(0, 632 / 2 - player1->getGlobalBounds().height / 2);
		player2->setPosition((1127- player2->getGlobalBounds().width), 632 / 2 - player2->getGlobalBounds().height / 2);
	}
	else if (getPosition().x > 1127)
	{
		score->Score1Update();
		setPosition(1127 / 2, 632 / 2);
		player1->setPosition(0, 632 / 2 - player1->getGlobalBounds().height / 2);
		player2->setPosition((1127 - player2->getGlobalBounds().width), 632/ 2 - player2->getGlobalBounds().height / 2);
	}

}