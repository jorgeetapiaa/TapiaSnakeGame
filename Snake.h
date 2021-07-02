#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h> //in order to use COORD
class Snake
{
private:
	COORD pos;
	int len; //length of snake
	int vel; //velocity of snake
	char direction;

public:
	Snake(COORD pos, int vel);
	void change_dir(char dir);
	void move_snake();
	COORD get_pos();
	bool eaten(COORD food_pos);
	void grow();
};

#endif
