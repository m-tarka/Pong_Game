#include "stdafx.h"
#include "game_state.h"

game_state::game_state()
{
	state = nullptr;
}

void game_state::SetWindow(RenderWindow* window)
{
	this->window = window;

}

void game_state::SetState(State * state)
{
	if (this->state != nullptr)
	{
		this->state->Destroy(window);
	}
	this->state = state;
	if (this->state != nullptr)
	{
		this->state->Create(window);
	}
}

void game_state::Update()
{

	if (state != nullptr)
	{
		state->Update(window);
	}
}
void game_state::Render()
{
	if (state != nullptr)
	{
		state->Render(window);
	}
}

game_state::~game_state()
{
	if (state != nullptr)
	{
		state->Destroy(window);
	}
}
