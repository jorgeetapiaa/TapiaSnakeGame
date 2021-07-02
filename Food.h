#ifndef FOOD_H
#define FOOD_H

#include <windows.h> //to include position of food
#include <cstdlib> //for random position generator

#define WIDTH 50
#define HEIGHT 25

class Food
{
public:
	Food();
	void gen_food();
	COORD get_pos();
private:
	COORD pos;

};

#endif
