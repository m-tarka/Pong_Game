#pragma once

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

class Element : public Sprite {
private:
	Texture * texture;
protected:
	float ballVelocity;
	Vector2f velocity{ ballVelocity, ballVelocity }; //predkosc
public:
	Element();
	virtual ~Element();
	void Load(string filename);
	virtual void Update();
	bool CheckCrash(Element *element);
};