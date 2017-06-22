#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "omokfunction.h"

#define UP 72
#define LEFT 75
#define DOWN 80
#define RIGHT 77
#define SPACE 32
#define ENTER 13
#define X 0
#define Y 1

#define W_SIZE 15 
#define H_SIZE 15 

extern char turn, bwin, wwin;
extern int chk;
extern int table[W_SIZE + 2][H_SIZE + 2];
extern int cursor[2];


void draw_table(void)
{
	int bx, by, i;

	system("cls");
	for (by = 1; by <= H_SIZE; by++)
	{
		printf(" ");
		for (bx = 1; bx <= W_SIZE; bx++)
		{
			if (cursor[X] == bx && cursor[Y] == by)
			{
				if (by != 1 && by != H_SIZE)
				{
					switch (table[by][bx])
					{
					case 0:
						printf("Ⅱ");
						break;
					case 1:
						printf("□");
						break;
					case 2:
						printf("■");
						break;
					}
				}
				
				else if (by == H_SIZE) {
					switch (table[by][bx])
					{
					case 0:
						printf("Ⅱ");
						break;
					case 1:
						printf("□");
						break;
					case 2:
						printf("■");
						break;
					}
				}
				else {
					switch (table[by][bx])
					{
					case 0:
						printf("Ⅱ");
						break;
					case 1:
						printf("□");
						break;
					case 2:
						printf("■");
						break;
					}
				}
			}
			else {
				if (by != 1 && by != H_SIZE)
				{
					switch (table[by][bx])
					{
					case 0:
						if (bx == 1) printf("┠");
						else if (bx == W_SIZE)  printf("┨");
						else printf("┼");
						break;
					case 1:
						printf("○");
						break;
					case 2:
						printf("●");
						break;
					}
				}
				else if (by == H_SIZE) {
					switch (table[by][bx])
					{
					case 0:
						if (bx == 1) printf("┗");
						else if (bx == W_SIZE)  printf("┛");
						else printf("┷");
						break;
					case 1:
						printf("○");
						break;
					case 2:
						printf("●");
						break;
					}
				}
				else {
					switch (table[by][bx])
					{
					case 0:
						if (bx == 1) printf("┏");
						else if (bx == W_SIZE)  printf("┓");
						else printf("┯");
						break;
					case 1:
						printf("○");
						break;
					case 2:
						printf("●");
						break;
					}
				}
			}
		}
		printf("\n");
	}
}
//*/

void winchk(void)
{
	int fullcount = 0;
	int i, j;

	bwin = 0;
	wwin = 0;

	for (j = 1; j < H_SIZE + 1; j++) 
	{
		for (i = 1; i < W_SIZE + 1; i++)
		{
			if (table[j][i] != 0) fullcount++;
		}
	}

	if (fullcount == W_SIZE * H_SIZE)
	{
		bwin = 99;
		wwin = 99;
	}

	for (j = 1; j < H_SIZE + 1; j++)
	{
		for (i = 1; i < W_SIZE - 3; i++)
		{
			if (table[j][i] == 1
				&& table[j][i + 1] == 1
				&& table[j][i + 2] == 1
				&& table[j][i + 3] == 1
				&& table[j][i + 4] == 1
				&& table[j][i - 1] != 1
				&& table[j][i + 5] != 1) bwin = 1;
			else if (table[j][i] == 2
				&& table[j][i + 1] == 2
				&& table[j][i + 2] == 2
				&& table[j][i + 3] == 2
				&& table[j][i + 4] == 2
				&& table[j][i - 1] != 2
				&& table[j][i + 5] != 2) wwin = 1;
		}
	}

	for (i = 1; i < W_SIZE + 1; i++)
	{
		for (j = 1; j < H_SIZE - 3; j++)
		{
			if (table[j][i] == 1
				&& table[j + 1][i] == 1
				&& table[j + 2][i] == 1
				&& table[j + 3][i] == 1
				&& table[j + 4][i] == 1
				&& table[j - 1][i] != 1
				&& table[j + 5][i] != 1) bwin = 1;
			else if (table[j][i] == 2
				&& table[j + 1][i] == 2
				&& table[j + 2][i] == 2
				&& table[j + 3][i] == 2
				&& table[j + 4][i] == 2
				&& table[j - 1][i] != 2
				&& table[j + 5][i] != 2) wwin = 1;
		}
	}

	for (j = 1; j < H_SIZE - 3; j++)
	{
		for (i = 1; i < W_SIZE - 3; i++)
		{
			if (table[j][i] == 1
				&& table[j + 1][i + 1] == 1
				&& table[j + 2][i + 2] == 1
				&& table[j + 3][i + 3] == 1
				&& table[j + 4][i + 4] == 1
				&& table[j - 1][i - 1] != 1
				&& table[j + 5][i + 5] != 1) bwin = 1;
			else if (table[j][i] == 2
				&& table[j + 1][i + 1] == 2
				&& table[j + 2][i + 2] == 2
				&& table[j + 3][i + 3] == 2
				&& table[j + 4][i + 4] == 2
				&& table[j - 1][i - 1] != 2
				&& table[j + 5][i + 5] != 2) wwin = 1;
		}
	}

	for (i = 1; i < W_SIZE - 3; i++) 
	{
		for (j = 5; j < H_SIZE + 1; j++)
		{
			if (table[j][i] == 1
				&& table[j - 1][i + 1] == 1
				&& table[j - 2][i + 2] == 1
				&& table[j - 3][i + 3] == 1
				&& table[j - 4][i + 4] == 1

				&& table[j - 5][i + 5] != 1
				&& table[j + 1][i - 1] != 1) bwin = 1;

			else if (table[j][i] == 2
				&& table[j - 1][i + 1] == 2
				&& table[j - 2][i + 2] == 2
				&& table[j - 3][i + 3] == 2
				&& table[j - 4][i + 4] == 2

				&& table[j - 5][i + 5] != 2
				&& table[j + 1][i - 1] != 2) wwin = 1;
		}
	}
}


void move_cursor(void)
{
	char ch;

	ch = getch();
	switch (ch)
	{
	case UP:
		if (cursor[Y] != 1) cursor[Y]--;
		else cursor[Y] = H_SIZE;
		break;
	case LEFT:
		if (cursor[X] != 1) cursor[X]--;
		else cursor[X] = W_SIZE;
		break;
	case RIGHT: 
		if (cursor[X] != W_SIZE) cursor[X]++;
		else cursor[X] = 1;
		break;
	case DOWN: 	
		if (cursor[Y] != H_SIZE) cursor[Y]++;
		else cursor[Y] = 1;
		break;
	case ENTER:
		if (turn == 0 && table[cursor[Y]][cursor[X]] == 0)
		{
			table[cursor[Y]][cursor[X]] = 1;
			turn = 1;
		}
		else if (turn == 1 && table[cursor[Y]][cursor[X]] == 0)
		{
			table[cursor[Y]][cursor[X]] = 2;
			turn = 0;
		}
		break;
	case SPACE:
		if (turn == 0 && table[cursor[Y]][cursor[X]] == 0)
		{
			table[cursor[Y]][cursor[X]] = 1;
			turn = 1;
		}
		else if (turn == 1 && table[cursor[Y]][cursor[X]] == 0)
		{
			table[cursor[Y]][cursor[X]] = 2;
			turn = 0;
		}
		break;
	case 'r':
		chk = 1;
		break;
	case 'R':
		chk = 1;
		break;
	case 'q':
		chk = 2;
		break;
	case '27':
		chk = 2;
		break;
	default:
		chk = 0;
		break;
	}
}
