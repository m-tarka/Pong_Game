#pragma once
#include <SFML/Graphics.hpp>
#include "game_state.h"
#include "Game.h"
#include <Windows.h>
using namespace sf;
using namespace std;

class Settings : public State
{
public:
	void Update(RenderWindow* window);
	void Render(RenderWindow* window);
	void Destroy(RenderWindow* window);
	void Create(RenderWindow* window);
	Settings();
private:
	Font * font;
	Text* text;
	unsigned int number;
};
