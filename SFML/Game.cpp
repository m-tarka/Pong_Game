#include "stdafx.h"
#include "Game.h"


Game::Game()
{

}


Game::Game(int m)
{
	font = new Font();
	if (!font->loadFromFile("Comfortaa Bold.ttf")) {

	}

	score = new Score(*font, 48U);
	score->max = m;
}

void Game::Update(RenderWindow* window) 
{
	player1->Update();
	player2->Update();
	ball->Update();
	score->Update();
}

void Game::Create(RenderWindow* window) {
	texture = new Texture;
	if (!texture->loadFromFile("background2.jpg")) {}

	background = Sprite(*texture);

	player1 = new Player(0);
	player2 = new Player(1);
	player1->Load("e2.png");
	player2->Load("e2.png");
	player1->setPosition(0, window->getSize().y / 2 - player1->getGlobalBounds().height / 2);
	player2->setPosition((window->getSize().x - player2->getGlobalBounds().width), window->getSize().y / 2 - player2->getGlobalBounds().height / 2);

	font = new Font();
	if (!font->loadFromFile("Comfortaa Bold.ttf")) {

	}
	if (score == nullptr)
	{
	score = new Score(*font, 48U);
	}
	ball = new Ball(player1,player2,score);
	ball->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	score->setPosition(window->getSize().x / 2 - 200, 0);
	score->setFillColor(Color::Black);
}

void Game::Render(RenderWindow* window) 
{
	window->draw(background);
	window->draw(*player1);
	window->draw(*player2);
	window->draw(*ball);
	window->draw(*score);
}

void Game::Destroy(RenderWindow* window)
{
	delete player1;
	delete player2;
	delete ball;
}
