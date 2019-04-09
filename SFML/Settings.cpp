#include "stdafx.h"
#include "Settings.h"

Settings::Settings()
{
	font = new Font;
	text = new Text();

	number = 10;
}

void Settings::Create(RenderWindow* window)
{
	if (!font->loadFromFile("Comfortaa Bold.ttf")) {

	}
	text->setFont(*font);
	text->setString("Do ilu:");
	text->setFillColor(Color::White);
	text->setPosition(Vector2f(1127 / 2 - 350, 632 / 2 - 50));
	text->setCharacterSize(50);

}


void Settings::Update(RenderWindow* window)
{
	text->setString("Do ilu punktow?	" + to_string(number));
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		Sleep(200);
		number--;
		
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		Sleep(200);
		number++;
	}
	
	else if (Keyboard::isKeyPressed(Keyboard::Key::S))
	{
		
		main_state.SetState(new Game(number));
	}

}

void Settings::Render(RenderWindow* window)
{
	window->draw(*text);
}

void Settings::Destroy(RenderWindow* window)
{
	delete text;
	delete font;
}