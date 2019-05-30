#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int t, n, k, w;
int time[1001];

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		vector<int> craft[1001];
		vector<int> dp(n + 1);
		vector<int> pre(n + 1);
		for (int i = 1; i <= n; i++)
			scanf("%d", &time[i]);
		int x, y;
		for (int i = 0; i < k; i++){
			scanf("%d %d", &x, &y);
			craft[x].push_back(y);
			pre[y]++;
		}
		scanf("%d", &w);
		queue<int> q;

		for (int i = 1; i <= n; i++)
			if (!pre[i]) q.push(i);

		while (pre[w] > 0) {
			int f = q.front();
			q.pop();
			for (int &next : craft[f]) {
				dp[next] = max(dp[next], dp[f] + time[f]);
				if (--pre[next] == 0) q.push(next);
			}
		}
		printf("%d\n", dp[w] + time[w]);
	}
	return 0;
}