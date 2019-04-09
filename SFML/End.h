#pragma once

#include <SFML/Graphics.hpp>
#include "Score.h"
#include "game_state.h"
using namespace sf;

class End : public State
{
public:
	void Update(RenderWindow* window);
	void Render(RenderWindow* window);
	void Destroy(RenderWindow* window);
	void Create(RenderWindow* window);
	void Winner1(RenderWindow* window);
	void Winner2(RenderWindow* window);
	End();
	End(Score* s);
private:
	Font * font;
	Text * text;
	int score1, score2;
};