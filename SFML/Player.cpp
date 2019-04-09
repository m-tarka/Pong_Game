#include "stdafx.h"
#include "Player.h"

Player::Player(int p) 
{
	player = p;
	switch (player)
	{
	case 0:
		Load("e2.png");
		break;
	case 1:
		break;
	}
}

void Player::Update()
{
	switch (player)
	{
	case 0:
		velocity.y = Keyboard::isKeyPressed(Keyboard::Key::S) - Keyboard::isKeyPressed(Keyboard::Key::W);
		break;
	case 1:
		velocity.y = Keyboard::isKeyPressed(Keyboard::Key::Down) - Keyboard::isKeyPressed(Keyboard::Key::Up);
		break;
	}
	Element::Update();

	if (getPosition().y < 0)
	{
		this->move(0, 1.0f);
	}

	if (getPosition().y + getGlobalBounds().height > 632)
	{
		this->move(0, -1.0f);
	}

}

