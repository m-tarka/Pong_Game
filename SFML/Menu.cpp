#include "stdafx.h"
#include "Menu.h"

Menu::Menu()
{
	font = new Font();
	title = new Text;
	for (auto &e : menu) {
		e = new Text;
	}

	if (!font->loadFromFile("Comfortaa Bold.ttf")) {

	}

	menu[0]->setFont(*font);
	menu[0]->setFillColor(Color::Green);
	menu[0]->setString("Graj");
	menu[0]->setPosition(Vector2f(1127 / 10, 632 / (NUMBER_OF_ELEMENTS + 1) *1.5));

	menu[1]->setFont(*font);
	menu[1]->setFillColor(Color::Black);
	menu[1]->setString("Ustawienia");
	menu[1]->setPosition(Vector2f(1127 / 10, 632 / (NUMBER_OF_ELEMENTS + 1) * 2));

	menu[2]->setFont(*font);
	menu[2]->setFillColor(Color::Black);
	menu[2]->setString("Wyjscie");
	menu[2]->setPosition(Vector2f(1127 / 10, 632 / (NUMBER_OF_ELEMENTS + 1) * 2.5));

	title->setFont(*font);
	title->setCharacterSize(70);
	title->setFillColor(Color::White);
	title->setString("Pong");
	title->setPosition(Vector2f(1127 / 8, 632 / 8));

	selected = 0;

}


void Menu::Create(RenderWindow * window)
{
	texture = new Texture;
	if (!texture->loadFromFile("pong2.jpg")) {}
	
		Sprite background(*texture);
		window->draw(background);

		window->draw(*title);

		for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
			window->draw(*menu[i]);
		}
}

void Menu::Destroy(RenderWindow* window) {
	delete this->texture;
	delete this->title;
	delete this->font;
	for (auto &e : menu) {
		delete e;
	}	
}

void Menu::Update(sf::RenderWindow* window)
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Up) && !upKey)
	{
		selected -= 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down) && !downKey)
	{
		selected += 1;
	}
	if (selected > 2)
	{
		selected = 0;
	}
	if (selected < 0)
	{
		selected = 2;
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Return))
	{
		switch (selected)
		{
		case 0:
			main_state.SetState(new Game());
			break;
		case 1:
		{
			main_state.SetState(new Settings());
			break;
		}
		case 2:
			window->close();
			break;
		}
	}
	upKey = Keyboard::isKeyPressed(Keyboard::Key::Up);
	downKey = Keyboard::isKeyPressed(Keyboard::Key::Down);
}
void Menu::Render(sf::RenderWindow* window)
{
	Create(window);
	switch (selected)
	{
	case 0:
		menu[0]->setFillColor(Color::Green);
		menu[1]->setFillColor(Color::Black);
		menu[2]->setFillColor(Color::Black);
		break;
	case 1:
		menu[0]->setFillColor(Color::Black);
		menu[1]->setFillColor(Color::Green);
		menu[2]->setFillColor(Color::Black);
		break;
	case 2:
		menu[0]->setFillColor(Color::Black);
		menu[1]->setFillColor(Color::Black);
		menu[2]->setFillColor(Color::Green);
		break;
	}
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		window->draw(*menu[i]);
	}
}