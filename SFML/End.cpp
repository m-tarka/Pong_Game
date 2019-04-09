#include "stdafx.h"
#include"End.h"

End::End()
{
	
}

End::End(Score * s)
{
	text = new Text();
	font = new Font();
	score1 = s->getScore1();
	score2 = s->getScore2();
	
}

void End::Create(RenderWindow* window)
{
	if (!font->loadFromFile("Comfortaa Bold.ttf")) {

	}
	text->setFont(*font);
	text->setFillColor(Color::Magenta);
	text->setPosition(window->getSize().x/2 - 150, window->getSize().y / 2 - 150);
	text->setCharacterSize(60);
	if (score1 == 10)
	{
		Winner1(window);
	}
	else Winner2(window);
}

void End::Render(RenderWindow* window)
{

}
void End::Destroy(RenderWindow* window)
{
	delete text;
	delete font;
}

void End::Winner1(RenderWindow* window)
{
	text->setString("Wygral gracz 1\nWynik	" + to_string(score1) + ":" + to_string(score2));
	window->draw(*text);
}

void End::Winner2(RenderWindow* window)
{
	text->setString("Wygral gracz 2\nWynik	" + to_string(score1) + ":" + to_string(score2));
	window->draw(*text);
}

void End::Update(RenderWindow* window)
{
	window->draw(*text);
}
