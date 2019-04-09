#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class State
{
public:
	virtual void Create(RenderWindow* window) {}
	virtual void Update(RenderWindow* window) {}
	virtual void Render(RenderWindow* window) {}
	virtual void Destroy(RenderWindow* window) {}
};

class game_state
{
private:
	RenderWindow* window;
	State* state;
public:
	game_state();
	void SetWindow(RenderWindow* window);
	void SetState(State * state);
	void Update();
	void Render();
	~game_state();
};

extern game_state main_state;
