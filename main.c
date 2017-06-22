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

#define W_SIZE 15 // 오목판 가로 사이즈
#define H_SIZE 15 // 오목판 세로 사이즈

char turn = 0, bwin = 0, wwin = 0;
int chk = 0;
int table[W_SIZE + 2][H_SIZE + 2] = { 0 };
int cursor[2] = { W_SIZE / 2, H_SIZE / 2 };


void reset_quit(void); // 키 입력 - 커서 이동, 재시작, 종료
void clear_table(void); // 초기화

int main(void)
{
	while (1)
	{
		if (chk == 1) clear_table();
		draw_table();
		winchk();
		if (bwin > 0 || wwin > 0) // 판정
		{
			while (chk == 0)
			{
				cursor[X] = 99;
				draw_table();
				if (wwin == 99 && bwin == 99) printf("　	DRAW\n\n");

				else if (turn == 1) printf("		BLACK WIN\n\n");
				else printf("		WHITE WIN\n\n");
				printf("　(RESET : r, R)\n　(EXIT 　　 : q, Q)\n");

				reset_quit();
				if (chk > 0) break;
			}
			clear_table();
			draw_table();
		}
		if (chk == 2) break; // 종료 시 반복문 밖으로 탈출
		chk = 0;

		if (turn == 0) printf("	BLACK'S TURN\n\n");
		else printf("	WHITE's TURN\n\n");
		printf("　(RESET : r, R)\n　(EXIT 　　 : q, Q)\n");
		move_cursor();
	}
	return 0;
}

void reset_quit(void)
{
	
	char ch;

	ch = getch();
	switch (ch) // 재시작, 종료 여부
	{
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

void clear_table(void)
{
	int i, j;

	turn = 0;
	wwin = 0;
	bwin = 0;
	cursor[X] = W_SIZE / 2;
	cursor[Y] = H_SIZE / 2;
	for (i = 1; i < W_SIZE; i++)
	{
		for (j = 1; j < H_SIZE; j++) table[j][i] = 0;
	}
}
