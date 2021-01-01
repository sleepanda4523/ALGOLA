#define _CRT_SECURE_NO_WARNINGS
#define FALSE 0
#define TRUE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int map[105][105] = { 0, };
int vist[105][105] = { FALSE, }; // 4방향 탐색시 같은 곳을 또 탐색하지 않도록 해주는 2차원 배열
int cnt = 0; 
void dfs(int y, int x,int max_y,int max_x);


int main()
{
	int n, m, k;		//n = 세로길이 m = 가로길이 k = 음식물 쓰래기 개수
	int max = 0;
	scanf("%d %d %d", &n, &m, &k);
	int x, y;		//입력받을 좌표
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] && vist[i][j] == FALSE) {					// 만약 map좌표에 쓰래기가 있을때 + 이미 방문한 좌표일때
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
	vist[y][x] = TRUE;					//방문한 곳 체크
	for (int i = 0; i < 4; i++) {
		int ay = y + dy[i];
		int bx = x + dx[i];
		if (ay > 0 && bx > 0 && ay <= max_y && bx <= max_x && vist[ay][bx]==FALSE && map[ay][bx]) {	//a와b가 map을 벗어나지 않도록 + 방문여부 + 쓰래기 여부
			dfs(ay, bx, max_y, max_x);
		}
	}
}