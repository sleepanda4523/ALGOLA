#define _CRT_SECURE_NO_WARNINGS

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int table[16][16] = { 0, };


int dfs(int size, int x);
int check_q(int size, int y, int x);

int main()
{
	int size,cnt;
	scanf("%d", &size);
	cnt = dfs(size, 0);
	printf("%d", cnt);
	return 0;
}
int dfs(int size, int x)
{
	if (x == size) {
		return TRUE;
	}
	int cnt = 0;
	for (int i = 0; i < size; i++) {
		if (check_q(size, i, x)) {
			table[i][x] = TRUE;
			cnt += dfs(size, x + 1);		
			table[i][x] = FALSE;			//n-1로 되돌아옴. 백트래킹.
		}
	}
	return cnt;
}
int check_q(int size, int y, int x)
{
	int d1 = y + x;
	int d2 = y - x;
	for (int i = 0; i < size; i++) {
		if (table[i][x] == TRUE || table[y][i] == TRUE) {
			return FALSE;
		}
		//대각선
		for (int j = 0; j < size; j++) {
			if ((i + j == d1 && table[i][j] == TRUE) || (i-j == d2 && table[i][j] == TRUE)) {
				return FALSE;
			}
		}
	}
	return TRUE;
}