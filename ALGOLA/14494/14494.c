#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define MAX 1010
#define MOD 1000000007

long long dynamic(int x, int y);
long long dp[MAX][MAX] = { 0, };
//f(x,y) = f(x-1,y) + f(x,y-1) + f(x-1,y-1)
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%lld", dynamic(n, m));
	return 0;
}

long long dynamic(int n, int m) {
	dp[1][1] = 1;
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= m; j++) {
			if (i*j!=1)	dp[i][j] = (dp[i - 1][j] % MOD) + (dp[i][j - 1] % MOD) + (dp[i - 1][j - 1] % MOD);
		}
	return dp[n][m]%MOD;
}