#pragma once
#include "Vector.h"
#include <allegro5\allegro_primitives.h>
class Bar
{
public:
	Vector p1;
	Vector p2;
	Vector normal;
	float friction;
	Bar(Vector a, Vector b, Vector n, float f);
	~Bar();

	void draw();
	
};

