#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int cost[1001][3];
int dp[1001][3];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &cost[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			dp[i][j] = 1000 * 1000;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++) {
				if (j == k) continue;
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + cost[i][j]);
			}

	int ans = 1000 * 1000;
	for (int i = 0; i < 3; i++)
		ans = min(ans, dp[n][i]);
	printf("%d\n", ans);

	return 0;
}