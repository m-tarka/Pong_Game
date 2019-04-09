#pragma once

#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

class Score : public Text
{
private:
	int value1, value2;
	Font* font;
	Text* score;
public:
	Score(Font &font, unsigned int size);
	void Score1Update();
	void Score2Update();
	void Update();
	int getScore1();
	int getScore2();
	int max;
};