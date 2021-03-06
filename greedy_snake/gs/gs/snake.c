#include<stdio.h>
#include<stdlib.h>
#include<windef.h>
#include<conio.h>
#include<time.h>

#include "head.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")




// play background music
void MyPlaySound(void);
// display the firstpage
void FirstPage(void);
// stop the sound
void MyStopSound(void);
// start
void TestSpace(void);
// print background
void showBackGround(void);

void SetSnakeRandPos(void);
// drawsnake
void DrawSnake(void);

// snake go
void SnakeMove(void);

//destroy snake
void DestroySnake(void);

// changd dir
void ChangeDir(void);

//snake die
char IsSnakeDie(void);

//get food
void GenFood(void);
int main(void)
{

	// play background music
	MyPlaySound();
	// display the firstpage
	FirstPage();
	// start
	TestSpace();
	// stop the sound
	MyStopSound();
	
	// clear the screen
	system("cls");


	printf("\t\tstart~!\n");

	SetSnakeRandPos();
	
	GenFood();

	while (1)
	{
		system("cls");

		ChangeDir();
		
		if (1 == IsSnakeDie())
		{
			printf("\t\tSNAKE DIED!\n");
			break;
		}
		

		SnakeMove();

		showBackGround();
		
		Sleep(1000);
	}

	system("pause");
	return 0;
}

//firstpage
void FirstPage(void)
{
	printf("\t\t\twelcome to the world of greedy snake!>>\n");
	printf("\t\t\tw a s d >> control direction\n");
	printf("\t\t\tspace >> start\n");
}
  
//playsound
void MyPlaySound(void)
{
	PlaySound("2.wav",NULL,SND_FILENAME|SND_ASYNC);
}

void TestSpace(void)
{
	char chInput;
	while (1)
	{
		chInput = _getch();
		if (' ' == chInput)
		{
			break;
		}
	}
}

void MyStopSound(void) 
{
	PlaySound(NULL, NULL, NULL);
}

void showBackGround(void)
{
	for (int i = 0; i < 20; i++)
	{
		printf(g_strGameBack[i]);
	}
}

void SetSnakeRandPos(void) 
{
	int nX = -1;
	int nY = -1;

	// gen rand see
	srand((unsigned int)time(NULL));
	nX = rand() % 19 + 1;
	nY = rand() % 18 + 1;

	// init of snake
	g_arrSnake[0][0] = nY;
	g_arrSnake[0][1] = nX * 2; // every square took two place
	g_arrSnake[0][2] = to_west;

	g_arrSnake[1][0] = nY;
	g_arrSnake[1][1] = nX * 2 + 2;
	g_arrSnake[1][2] = to_west;
	
	g_arrSnake[2][0] = nY;
	g_arrSnake[2][1] = nX * 2 + 4;
	g_arrSnake[2][2] = to_west;
}


void DrawSnake(void) 
{
	int i = 0;
	for (i = 0; g_arrSnake[i][0] != 0; i++)
	{
		// use strncpy to avoid "\0"
		strncpy(&g_strGameBack[g_arrSnake[i][0]][g_arrSnake[i][1]], "��", 2);
	}
}

void SnakeMove(void) 
{
	DestroySnake();
	int i = DEF_SNAKE_LONG;
	for (i; i >= 1; i--)
	{
		if (g_arrSnake[i][0] == 0)
			continue;

		g_arrSnake[i][0] = g_arrSnake[i - 1][0];
		g_arrSnake[i][1] = g_arrSnake[i - 1][1];
		g_arrSnake[i][2] = g_arrSnake[i - 1][2];
	}

	

	if (to_west == g_arrSnake[0][2] || to_east == g_arrSnake[0][2])
	{ 
		g_arrSnake[0][1] += g_arrSnake[0][2];
	}
	else
	{
		g_arrSnake[0][0] += g_arrSnake[0][2];
	}
	DrawSnake();
}

void DestroySnake(void) 
{
	int i = 0;
	for (i = 0; g_arrSnake[i][0] != 0; i++)
	{
		// use strncpy to avoid "\0"
		strncpy(&g_strGameBack[g_arrSnake[i][0]][g_arrSnake[i][1]], "  ", 2);
	}
}

void ChangeDir(void) 
{
	if(GetAsyncKeyState('W'))
	{
		g_nSnakeDir = to_north;
	}
	else if (GetAsyncKeyState('S'))
	{
		g_nSnakeDir = to_south;
	}
	else if (GetAsyncKeyState('A'))
	{
		g_nSnakeDir = to_west;
	}
	else if (GetAsyncKeyState('D'))
	{
		g_nSnakeDir = to_east;
	}
	
	g_arrSnake[0][2] = g_nSnakeDir;
}

char IsSnakeDie(void) 
{
	if (to_west == g_arrSnake[0][2] || to_east == g_arrSnake[0][2])
	{
		if(0 == strncmp(&g_strGameBack[g_arrSnake[0][0]][g_arrSnake[0][1] + g_arrSnake[0][2]],"��",2))
		{
			return 1;
		}
	}
	else
	{
		if (0 == strncmp(&g_strGameBack[g_arrSnake[0][0]+ g_arrSnake[0][2]][g_arrSnake[0][1]], "��", 2))
		{
			return 1;
		}
	}
	return 0;
}


void GenFood(void)
{
	srand((unsigned int)time(NULL));
	int nRow, nCol;
	while (1)
	{
		nRow = rand() % 18 + 1;
		nCol = rand() % 21 + 1;

		char flag = 1;
		// detect whether the food and the snake are overlapped
		for (int i = 0; g_arrSnake[i][0] != 0; i++)
		{
			if (nRow == g_arrSnake[i][0] && nCol*2 == g_arrSnake[i][1])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{ 
			break;
		}
	}
	//plot food
	strncpy(&g_strGameBack[nRow][nCol * 2], "��", 2);
}