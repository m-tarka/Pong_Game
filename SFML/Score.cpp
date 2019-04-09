#include "stdafx.h"
#include "Score.h"

Score::Score(Font &font,  unsigned int size) : Text("", font, size)
{

	value1 = 0;
	value2 = 0;
	max = 10;
}

void Score::Score1Update()
{
	value1++;
}

void Score::Score2Update()
{
	value2++;
}

void Score::Update()
{
	setString("Wynik: " + to_string(value1) + "	 " + to_string(value2));
}

int Score::getScore1()
{
	return value1;
}

int Score::getScore2()
{
	return value2;
}