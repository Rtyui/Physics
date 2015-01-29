#include "Vector.h"
#include <iostream>

Vector::Vector(){
}

Vector::Vector(float _x, float _y){
	x = _x;
	y = _y;
}

Vector::~Vector(){
}

void Vector::changeCoords(float _x, float _y){
	x = _x;
	y = _y;
}

void Vector::rotate(float tetha){
	float aux = x;
	x = x * cos(tetha) - y * sin(tetha);
	y = aux * sin(tetha) + y * cos(tetha);
}

void Vector::operator=(Vector v){
	x = v.x;
	y = v.y;
}

void Vector::showVector(){
	std::cout << x << " " << y << std::endl;
}

Vector Vector::operator+(Vector v){
	return Vector(x + v.x, y + v.y);
}

Vector Vector::operator-(Vector v){
	return Vector(x - v.x, y - v.y);
}

Vector Vector::operator*(float a){
	return Vector(x*a, y*a);
}

float Vector::operator*(Vector v){
	//return sqrt(x * x + x * x) * sqrt(v.x * v.x + v.y * v.y) * (x * v.x + y * v.y) / (sqrt(x * x + y * y) * sqrt(v.x * v.x + v.y * v.y));
	return (x * v.x + y * v.y);
}
