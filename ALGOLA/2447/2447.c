#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char table[2188][2188];
void star(int x, int y, int size) {
    if (size == 1) {
        table[x][y] = '*';
        return;
    }
    int m = size / 3;
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cnt++;
            if (cnt != 5) {
                star(x + i * m, y + j * m, m);
            }
        }
    }
}

int main()
{

    int input = 0;

    memset(table, ' ', sizeof(table));
    scanf("%d", &input);
    star(0, 0, input);
    for (int i = 0; i < input; i++) {
        for (int j = 0; j < input; j++) {
            printf("%c", table[i][j]);
        }
        printf("\n");
    }
    return 0;
}
