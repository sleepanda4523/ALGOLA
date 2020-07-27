#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Coord {
	int x;
	int y;
}coord;
coord* bubble(coord*,int,int);
int main()
{
	int size;
	scanf("%d", &size);
	coord* ndata = (coord*)malloc(sizeof(coord) * size);
	for (int i = 0; i < size; i++) {
		scanf("%d %d", ndata[i].x, ndata[i].y);
	}
	bubble(ndata,1,size);
	return 0;
}
coord* bubble(coord* ndata, int check,int s)
{
	if (check == 1) {
		for (int i = 0; i < s; i++) {
			for (int j = 1; j < s - i; j++) {
				if (ndata[j - 1].x > ndata[j].x) {
					coord temp;
					temp = ndata[j - 1];
					ndata[j - 1] = ndata[j];
					ndata[j] = temp;
				}
				else if (ndata[j].x == ndata[j - 1].x) {
					bubble(ndata, check + 1, s);
				}
			}
		}
	}
	else if (check == 2) {

	}
}