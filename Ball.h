#pragma once
#include "Vector.h"
#include "Bar.h"
#include <allegro5\allegro_primitives.h>
#include<cmath>
#define g -1
class Ball
{
public:
	Vector position;
	Vector speed;
	Vector speed0;
	float time;
	float r;
	float elasticity;
	Ball(float xp, float yp, float xs, float ys, float rad, float e);
	~Ball();
	void checkCollision(Bar b);
	void increment();
	void draw();
	float calculateAlpha(Bar b);
	void gravityIncrement();
};

