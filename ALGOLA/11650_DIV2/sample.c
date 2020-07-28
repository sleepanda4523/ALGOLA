#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Coord {
	int x;
	int y;
}coord;
int compare(const void* a, const void* b)    // �������� �� �Լ� ����
{
	int num1 = *(int*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	int num2 = *(int*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (num1 < num2)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (num1 > num2)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}
int main()
{
	int size;
	scanf("%d", &size);
	coord* ndata = (coord*)malloc(sizeof(coord) * size);
	for (int i = 0; i < size; i++) {
		scanf("%d %d", &ndata[i].x, &ndata[i].y);
	}
	qsort(ndata, size, sizeof(coord),compare);
	for (int i = 0; i < size; i++) {
		printf("%d %d\n", ndata[i].x, ndata[i].y);
	}
	return 0;
}
