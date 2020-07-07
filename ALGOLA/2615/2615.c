#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define X 19
typedef struct MyStruct
{
	int y, x;
}Dir;
int win = 0;
int wx, wy;

Dir move[4] = { {0,1},{1,0},{1,1},{-1,1} }; //오른쪽 가로, 밑으로 세로, 오른쪽 대각선 아래, 오른쪽 대각선 위
Dir movet = { 0,1 };

void find(int(*pdata)[X], int y, int x, int cnt, int color, int d)
{
	if (x == -1 || y == -1 || y == X || x == X)		return;

	if (cnt == 1) {
		for (int i = 0; i < 4; i++) {
			if (pdata[y + move[i].y][x + move[i].x] == color) {
				find(pdata, y + move[i].y, x + move[i].x, cnt + 1, color, i);
			}
		}
	}
	if (cnt == 5 && pdata[y + move[d].y][x + move[d].x] != color && pdata[y - move[d].y * 5][x - move[d].x * 5] != color) {
		win = color;
		wy = y - move[d].y * 4 + 1;
		wx = x - move[d].x * 4 + 1;
		return;
	}
	if (cnt >= 2 && pdata[y + move[d].y][x + move[d].x] == color) {
		find(pdata, y + move[d].y, x + move[d].x, cnt + 1, color, d);
	}
	else {
		return;
	}
}
int input(int(*pdata)[X])
{
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < X; j++) {
			scanf("%d", &pdata[i][j]);
		}
	}
	for (int i = 0; i < X; i++) {
		if (win > 0)	break;
		for (int j = 0; j < X; j++) {
			if (pdata[i][j] != 0) {
				find(pdata, i, j, 1, pdata[i][j], 0);
			}
		}
	}
	if (win > 0) {
		printf("%d\n%d %d", win, wy, wx);
	}
	else {
		printf("0");
	}
	return 0;

}


int main()
{
	int table[X][X] = { 0, };

	input(table);

	return 0;
}
