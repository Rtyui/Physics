#include "Ball.h"
#include <iostream>
using namespace std;

Ball::Ball(float xp, float yp, float xs, float ys, float rad, float e){
	position.changeCoords(xp, yp);
	speed.changeCoords(xs, ys);
	speed0 = speed;
	r = rad;
	elasticity = e;
	time = 0;
}


Ball::~Ball(){
}

void Ball::checkCollision(Bar b){
	float d0 = (position - b.p1) * b.normal;
	float d1 = (position + speed - b.p1) * b.normal;
	if (d0 < r){
		speed.showVector();
		time = 0;
		float ui = (d0 - r) / (d0 - d1);
		position = position * (1 - ui) + (position + speed)  * ui;
		if (b.normal.x != 0){
			speed.x *= -elasticity;
			speed.y -= speed.y * b.friction;
		}
		if (b.normal.y != 0){
			speed.y *= -elasticity;
			if (fabs(speed.y) <= 1){
				speed.y = 0;
			}
			cout << speed.y << endl;
			speed.x -= speed.x * b.friction;
		}
		speed0 = speed;
	}
	if (speed.y == 0){
		speed.x *= 1 - b.friction;
		if (fabs(speed.x) < 0.01){
			speed.x = 0;
		}
		cout << speed.x << endl;
	}

}

void Ball::increment(){
	position = position + speed;
}

void Ball::draw(){
	al_draw_filled_circle(position.x, position.y, r, al_map_rgb(255, 100, 100));
}

float Ball::calculateAlpha(Bar b){
	return atan(speed.y / speed.x);
}

void Ball::gravityIncrement(){
	time = time + 0.1666;
	if (speed.y != 0)
	speed.y = speed0.y - g * time;

}
