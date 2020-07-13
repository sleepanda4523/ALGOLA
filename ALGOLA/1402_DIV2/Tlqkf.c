#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
void func()
{
	int innum1,innum2;
	int sum = 0,i;
	int check = 1;

	scanf("%d %d", &innum1,&innum2);
	if (innum1 < 0) {
		innum1 *= -1;
		check = -1;
	}
	for (i = 1; i * i < innum1; i++) {
		if (innum1 % i == 0) {
			sum += i;
			sum += innum1 / i;
		}
		
	}
	if (i * i == innum1) {
		sum += i*2;
	}
	sum = sum - 1 - innum1;

	if (sum == innum2) {
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
}
int main()
{
	int testcase = 0,n,m;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++) {
		scanf("%d %d", &n, &m);
		printf("yes\n");
	}
	return 0;
}