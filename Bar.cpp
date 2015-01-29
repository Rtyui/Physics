#include "Bar.h"

Bar::Bar(Vector a, Vector b, Vector n, float f) {
	p1 = a;
	p2 = b;
	normal = n;
	friction = f;
}

Bar::~Bar(){
}

void Bar::draw(){
	al_draw_line(p1.x, p1.y, p2.x, p2.y, al_map_rgb(200, 200, 200), 2);
}
