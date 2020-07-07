#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
int cnt = 0;
int myx = 0, myy = 0;
void zfind(int x, int y, int size)
{
	if (size == 2) {
		if (x == myx && y == myy) {
			printf("%d\n", cnt);
		}
		cnt++;
		if (x + 1 == myx && y == myy) {
			printf("%d\n", cnt);
		}
		cnt++;
		if (x == myx && y + 1 == myy) {
			printf("%d\n", cnt);
		}
		cnt++;
		if (x + 1 == myx && y + 1 == myy) {
			printf("%d\n", cnt);
		}
		cnt++;
		return;
	}
	int s = size / 2;
	zfind(x, y, s);
	zfind(x + s, y, s);
	zfind(x, y + s, s);
	zfind(x + s, y + s, s);
}

int main()
{
	int n, r, c;
	scanf("%d %d %d", &n, &r, &c);
	myy = r;
	myx = c;

	zfind(0, 0, pow(2, n));

	return 0;
}