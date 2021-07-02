// Snake Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//main file

#include <iostream>
#include <conio.h> //to control the dnake (console input/output)

#include "Snake.h"
#include "Food.h"

#define WIDTH 50
#define HEIGHT 25

using namespace std;

Snake snake({ WIDTH / 2, HEIGHT / 2 }, 1); //initialize snake in the middle of the board w/a vel of 1
Food food;
void board()
{
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();

    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t#";
        for (int j = 0; j < WIDTH - 2; j++)
        {
            if (i == 0 || i == HEIGHT - 1) cout << "#";
            else if (i == snake_pos.Y && j == snake_pos.X) cout << "O";
            else if (i == food_pos.Y && j == food_pos.X) cout << "*";
            else cout << " ";
        }
        cout << "#\n";
    }
}

int main()
{
    while (true)
    {
        board();

        if (_kbhit()) //keyboard hit
        {
            switch (_getch()) //gives you the key pressed by user
            {
            case 'w':snake.change_dir('u'); break; //move snake up
            case 'a':snake.change_dir('l'); break;
            case 's':snake.change_dir('d'); break;
            case 'd':snake.change_dir('r'); break;
            }
        }
        
        snake.move_snake(); //move the snake

        if (snake.eaten(food.get_pos()))
        {
            food.gen_food(); //generate new food if snake ate the previous one
            snake.grow();
        }

        //This function will pick up the cursor from the end of this code and place it back at the beginning
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
    }
}
