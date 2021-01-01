#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1100

char arr[MAX] = { 0, };
char ans[MAX] = { 0, };

long Findrule(int size);
char* Rev(long X,int size);

int main()
{
	long X;
	int size;
	scanf("%ld", &X);
	scanf("%s", arr);
	size = strlen(arr);
	long pattern = Findrule(size);
	X %= pattern;
	long turn = pattern - X;
	printf("%s", Rev(turn, size));
	return 0;
}
long Findrule(int s)
{
	int sz = s + 2;
	char *str = calloc(sz, sizeof(char));
	char* temp = calloc(sz, sizeof(char));
	strcpy(str, arr);
	int half = s/2+1;
	long cnt = 0;
	int idx = 0;
	do {
		idx = 0;
		for (int i = 0; i < half ; i++) {
			temp[idx] = str[i];
			idx++;
			if (str[s - i - 1] != NULL) {
				temp[idx] = str[s - i - 1];
				idx++;
			}
		}
		temp[s] = NULL;
		strcpy(str, temp);
		//printf("%s\n", str);
		cnt++;
	} while (strcmp(str,arr));
	
	return cnt;
}
//원래 값에서 n번 깜빡여서 입력받은 단어가 되었다면, 입력받은 단어에서(주기 - n)번 더 깜빡이면 원래 값으로 되돌아간다는 점
char* Rev(long X,int size)
{
	int sz = size + 2;
	char *str = calloc(sz, sizeof(char));
	char *temp = calloc(sz, sizeof(char));
	strcpy(str, arr);
	int half = size / 2;
	int idx = 0;
	for (long j = 0; j < X; j++) {
		idx = 0;
		for (int i = 0; i <= half && idx < size; i++) {
			temp[idx] = str[i];
			idx++;
			if (str[size - i - 1] != NULL) {
				temp[idx] = str[size - i - 1];
				idx++;
			}
		}
		temp[size] = 0;
		strcpy(str, temp);
	}

	return str;
}