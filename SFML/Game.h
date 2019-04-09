#pragma once
#include <SFML/Graphics.hpp>
#include "game_state.h"
#include "Menu.h"
#include "Element.h"
#include "Player.h"
#include "Ball.h"
#include "Score.h"
using namespace sf;

class Game : public State 
{
public:
	void Create(RenderWindow* window);
	void Update(RenderWindow* window);
	void Render(RenderWindow* window);
	void Destroy(RenderWindow* window);
	Game();
	Game(int m);
	~Game();
	int max;
private:
	Player *player1;
	Player *player2;
	Ball *ball;
	Texture * texture;
	Sprite background;
	Score *score;
	Font * font;

};

