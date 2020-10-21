#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000000
#define MAX 101
#define LAST 11

// 자릿수가 n이고 끝 자릿수가 x일때 dp[n][x] = dp[n-1][x-1] + dp[n-1][x+1]

int main()
{
	int dp[MAX][LAST] = { 0, };
	int n = 0;
	scanf("%d", &n);

	//N=1 일때 기본 세팅
	for (int i = 1; i < 10; i++)	dp[1][i] = 1;

	//원하는 자릿수 N까지
	for (int i = 2; i <= n; i++) {
		// 뒷자리 자릿수가 0일때 
		dp[i][0] = dp[i - 1][1];
		//그 외의 경우
		for (int j = 1; j < 10; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
	}
	long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
	}
	printf("%d", sum % MOD);
	

	return 0;
}