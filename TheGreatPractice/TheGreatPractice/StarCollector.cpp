/*Hello!  And welcome to Star Collector!  
This is a simple game made using C++.
I made this game as a practice to better
my coding skills.  This game is very easy
to play.  You play as 'O' and you must collect as 
many stars as you can.  The score counter will keep
track of your progress, however, if you run into the barriers
you crash and die :( nobody said star collecting wasn't a dangerous
business.  So go forth and collect those stars! And most importantly
have fun!

-Ashley Faul
8/15/2016*/




#include <iostream>
#include  <conio.h>
#include <Windows.h>
using namespace std;
bool gameOver; //boolian for the game over.  The game over will be true or false depending on the placement of the O
const int width = 20; //witdth of the game
const int height = 20; //Height of the game
int x, y, starX, starY, score;  //constant variables for the star placements and score
enum eDirection{ STOP = 0, LEFT, RIGHT, UP, DOWN}; 
eDirection dir;
void Setup(){
	
	gameOver = false; //in the main setup of the game, the game starts and the game over is false
	dir = STOP; //the 'O' or our main character is currently not moving in any direction until WASD is pressed.
	x = width / 2; 
	y = height / 2;
	starX = rand() % width;  //These two statements are random placement of the star every game.
	starY = rand() % height;
	score = 0; //The score is set at 0 and goes up one for every star collected
	
}
void Draw()
{
  
	system("cls"); 
	for (int i = 0; i < width+2; i++)
		cout << "/"; //this is the setup for the wall
	cout << endl;
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "/"; //another wall
			if (i == y && j == x)
				cout << "O";
			else if (i == starY && j == starX)
				cout << "*"; //This is the star and star placement
			else 
				cout << " "; 

			if (j == width - 1)
				cout << "/"; // yet another wall
		}
		cout << endl;
		
	}

	for (int i = 0; i < width + 2; i++)
		cout << "/"; //bottom wall
		cout << endl;
		cout << "Stars Collected:" << score << endl; //This is where the score will be displayed, followed by the text. 
		cout << "WELCOME TO STAR COLLECTOR" << endl;
		cout << "COLLECT AS MANY STARS ( * ) AS YOU CAN!!" << endl;
		cout << "USE WASD TO MOVE" << endl;
		cout << "DON'T HIT THE WALL OR YOU CRASH AND DIE :( " << endl;
		

}
void Input() //This is the input for the game controls, like most pc games the controls will be WASD.
{
	if (_kbhit()) //If these character keys are hit, the 'O' will move left, right, up, or down.  if X is hit then the game is terminated. 
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;

		}
	}
}
void Logic()
{
	switch (dir) //The switch directions are hee
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;


	}
	if (x > width || x < 0 || y > height || y < 0) //if the wall is hit the game is terminated
		gameOver = true;
	if (x == starX && y == starY)//if a star is collected, the score goes up
	{
		score += 1;
		starX = rand() % width;
		starY = rand() % height;
		//the star is placed in a new location with every star collected.
	}
}


int main()
{
	


	Setup();
	while (!gameOver) //as long as the wall isnt hit and there is no game over, all of these functions are called to make the game run, until the game over.  
	{
		
		Draw();
		Input();
		Logic();
		Sleep(20); Sleep(20); //this is the speed of the 'O', origionally there was no speed setting and it was far too fast, I looked this up online and found this "sleep" setting to slow the speed.  
		//I slowed it by 20 because 10 was still to fast, 20 is not too slow but still represents a challenge.
		
		
	}




	return 0; //thats it, have fun.  My high score is 43 stars *
}
