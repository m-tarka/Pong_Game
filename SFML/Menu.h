#pragma once
#include "SFML/Graphics.hpp"
#include "game_state.h"
#include "Game.h"
#include "Settings.h"
#define NUMBER_OF_ELEMENTS 3

using namespace sf;

class Menu : public State
{
public:
	Menu();
	~Menu() {}

	int press() { return selected; }
	void Create(RenderWindow* window) override;
	void Destroy(RenderWindow* window) override;
	void Update(RenderWindow* window) override;
	void Render(RenderWindow* window) override;


private:
	int selected;
	Font *font; // czcionka
	Text *menu[NUMBER_OF_ELEMENTS];
	Text *title;
	Texture *texture;
	bool upKey, downKey;
};



