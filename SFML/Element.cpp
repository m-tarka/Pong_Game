#include "stdafx.h"
#include "Element.h"

Element::Element() 
{
	texture = new Texture();
}

Element::~Element()
{
	delete texture;
}

void Element::Load(string filename) {
	texture->loadFromFile(filename);
	this->setTexture(*texture);
}

void Element::Update()
{
	move(velocity);
}

bool Element::CheckCrash(Element *element)
{
	return getGlobalBounds().intersects(element->getGlobalBounds()); //getglobalbounds (zwraca prostokat ograniczajacy obiekt)
}