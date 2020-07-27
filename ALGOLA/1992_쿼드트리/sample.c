#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 64

void DC(int, int, int);

int ndata[MAX][MAX];

int main()
{
	int size;
	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf("%1d", &ndata[i][j]);
		}
	}
	DC(0, 0, size);
	return 0;
}

void DC(int x, int y, int size)
{
	if (size == 1) {
		printf("%d", ndata[y][x]);
		return;
	}
	int zero = 1, one = 1;
	for (int i = y; i < y+size; i++) {
		for (int j = x; j < x+size; j++) {
			if (ndata[i][j] == 0) {
				one = 0;
			}
			else {
				zero = 0;
			}
		}
	}
	if (zero==1) {
		printf("0");
	}
	else if (one == 1) {
		printf("1");
	}
	else {
		int m = size / 2;
		printf("(");
		DC(x, y, m);
		DC(x + m, y, m);
		DC(x, y + m, m);
		DC(x + m, y + m, m);
		printf(")");
	}
}
