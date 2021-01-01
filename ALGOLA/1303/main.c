#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX 104
#define TRUE 1
#define FALSE 0 

typedef struct MyStruct
{
	int y, x;
}Dir;
Dir Move[4] = { {0,1},{1,0},{-1,0},{0,-1} };	//위, 오른쪽, 왼쪽, 아래.

char map[MAX][MAX] = { 0, };

int B_count = 0;
int W_count = 0;
int x_size, y_size;

int DFS(int y, int x, char color);


int main()
{
	scanf("%d %d", &x_size, &y_size);
	for (int i = 1; i <= y_size; i++) {
		scanf("%s", map[i] + 1);
	}
	int temp = 0;		//임시 저장 변수
	for (int i = 1; i <= y_size; i++) {
		for (int j = 1; j <= x_size; j++) {
			if (map[i][j] == 'W') {
				temp = DFS(i, j, 'W');
				W_count += temp * temp;
			}
			else if (map[i][j] == 'B') {
				temp = DFS(i, j, 'B');
				B_count += temp * temp;
			}
		}
	}
	printf("%d %d", W_count, B_count);
	return 0;
}

int DFS(int y, int x, char color)
{
	int r = 1;
	map[y][x] = FALSE;
	for (int i = 0; i < 4; i++) {
		int ny = y + Move[i].y, nx = x + Move[i].x;
		if (map[ny][nx] != color) continue;
		r += DFS(ny, nx, color);
	}
	return r;
}