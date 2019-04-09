#pragma once
#include "Element.h"

class Player : public Element
{
private:
	int player;
public:
	Player() {}
	Player(int p);
	void Update() override;

};