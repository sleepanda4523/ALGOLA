#include <stdio.h>
#include <stdlib.h>


void two(long n) {
	int size = 1;
	int* a = (int*)malloc(sizeof(int) * size);
	// 배열에 원소 넣기 ex) 11 => 1 1 0 1 (2로 나누고 나머지 값) 
	for (int i = 0; n != 0; i++) {
		a[i] = n % 2;
		n /= 2;
		if (n != 0) {
			size++;
			realloc(a, sizeof(int) * size);
		}
	}
	realloc(a, sizeof(int) * (size - 1));		//맨 앞자리 없애기

	for (int i = 0; i < size - 1; i++) {
		if (a[i] == 0) {
			a[i] = 4;
		}
		else if (a[i] == 1) {
			a[i] = 7;
		}
	}
	for (int i = size - 2; i >= 0; i--) {
		printf("%d", a[i]);
	}

	free(a);
}
int main()
{
	long n;
	scanf("%ld", &n);
	two(n+1);
	return 0;
}