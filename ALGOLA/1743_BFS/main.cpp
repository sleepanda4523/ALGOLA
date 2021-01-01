#include <iostream>
#include <queue>
#define MAX 105
using namespace std;
typedef struct _coord {
	int y;
	int x;
}Coord;

queue<Coord> q;
int map[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M, K;

int main()
{
	cin >> N >> M >> K;
	int r,c;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		map[r][c] = 1;
	}
	
	return 0;
}