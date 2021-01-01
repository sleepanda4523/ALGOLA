#define _CRT_SECURE_NO_WARNINGS
#define FALSE 0
#define TRUE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int map[105][105] = { 0, };
int vist[105][105] = { FALSE, }; // 4���� Ž���� ���� ���� �� Ž������ �ʵ��� ���ִ� 2���� �迭
int cnt = 0; 
void dfs(int y, int x,int max_y,int max_x);


int main()
{
	int n, m, k;		//n = ���α��� m = ���α��� k = ���Ĺ� ������ ����
	int max = 0;
	scanf("%d %d %d", &n, &m, &k);
	int x, y;		//�Է¹��� ��ǥ
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] && vist[i][j] == FALSE) {					// ���� map��ǥ�� �����Ⱑ ������ + �̹� �湮�� ��ǥ�϶�
				cnt = 0;
				dfs(i, j,n,m);
				if (max < cnt)	max = cnt;
			}
		}
	}
	printf("%d", max);
	return 0;
}

void dfs(int y, int x, int max_y, int max_x)
{
	cnt++;
	vist[y][x] = TRUE;					//�湮�� �� üũ
	for (int i = 0; i < 4; i++) {
		int ay = y + dy[i];
		int bx = x + dx[i];
		if (ay > 0 && bx > 0 && ay <= max_y && bx <= max_x && vist[ay][bx]==FALSE && map[ay][bx]) {	//a��b�� map�� ����� �ʵ��� + �湮���� + ������ ����
			dfs(ay, bx, max_y, max_x);
		}
	}
}