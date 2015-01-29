#include <iostream>
using namespace std;
#include <math.h>

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "Vector.h"
#include "Ball.h"
#include "Bar.h"

#define M_PI       3.14159265358979323846
#define meter 10

const int DISPLAY_WIDTH = 1366;
const int DISPLAY_HEIGHT = 768;


int main(){
	ALLEGRO_DISPLAY *display;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *queue;
	ALLEGRO_EVENT event;

	al_init();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();

	timer = al_create_timer(1.0 / 60.0);

	display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
	al_set_window_position(display, 100, 100);

	queue = al_create_event_queue();
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));

	bool running = true, redraw = false;
	//bool KEYS[250];

	Ball ball1(500, 300, 3, 1, 0.35 * meter, 0.7);
	Bar bar1(Vector(100, 100), Vector(DISPLAY_WIDTH - 100, 100), Vector(0, 1), 0);
	Bar bar2(Vector(DISPLAY_WIDTH - 100, 100), Vector(DISPLAY_WIDTH - 100, DISPLAY_HEIGHT - 100), Vector(-1, 0), 0);
	Bar bar3(Vector(DISPLAY_WIDTH - 100, DISPLAY_HEIGHT - 100), Vector(100, DISPLAY_HEIGHT - 100), Vector(0, -1), 0.01);
	Bar bar4(Vector(100, DISPLAY_HEIGHT - 100), Vector(100, 100), Vector(1, 0), 0);

	al_start_timer(timer);

	while (running){
		al_wait_for_event(queue, &event);

		if (event.type == ALLEGRO_EVENT_TIMER){
			redraw = true;
			ball1.checkCollision(bar1);
			ball1.checkCollision(bar2);
			ball1.checkCollision(bar3);
			ball1.checkCollision(bar4);
			ball1.gravityIncrement();
			ball1.increment();
			

		}

		else if (event.type == ALLEGRO_EVENT_MOUSE_AXES){
		}

		else if (event.type == ALLEGRO_EVENT_KEY_DOWN){
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				running = false;
			}
		}

		else if (event.type == ALLEGRO_EVENT_KEY_UP) {
			
		}

		if (redraw){
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			ball1.draw();
			bar1.draw();
			bar2.draw();
			bar3.draw();
			bar4.draw();

			al_flip_display();
		}
	}
	return 0;
}