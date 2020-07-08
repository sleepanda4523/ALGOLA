#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

int cnt = 0;
int myx = 0, myy = 0;
void zfind(int x, int y, int size)
{
	if (size == 2) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (x + j == myx && y + i == myy) {
					printf("%d\n", cnt);
				}
				cnt++;
			}
		}
		return;
	}
	int s = size / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			zfind(x + s * j, y + s * i, s);
		}
	}
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