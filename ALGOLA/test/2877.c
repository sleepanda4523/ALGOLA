#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void print(int cnt, int or )
{
	long answer = 0;
	if (or==1) {
		answer = 4;
		for (int i = 1; i <= cnt; i++) {
			int ten = pow(10, i);
			answer += ten * 4;
		}
	}
	else if (or==0) {
		answer = 7;
		for (int i = 1; i <= cnt; i++) {
			int ten = pow(10, i);
			answer += ten * 7;
		}
	}
	printf("%ld", answer);
}
int find(int* ndata, int or,int cnt)
{
		int zero = 0,one = 0;
		for (int i = 0; i < cnt; i++) {
			ndata[i] == 0 ? zero++ : one++;
		}
		if (or==0) {
			return zero;
		}
		else if (or==1) {
			return one;
		}
}

void two(long n,int or) {
	long ndata = n;
	int a[1000] = { 0, };
	int p = 0;
	while (1)
	{
		a[p] = ndata % 2;    // 2로 나누었을 때 나머지를 배열에 저장
		ndata /= 2;             // 2로 나눈 몫을 저장

		p++;    // 자릿수 변경

		if (ndata == 0)    // 몫이 0이 되면 반복을 끝냄
			break;
	}
	int cnt= find(a, or,p);
	print(cnt, or);
	free(a);
}
int main()
{
	long n;
	scanf("%ld", &n);
	two(n,n%2);
	return 0;
}