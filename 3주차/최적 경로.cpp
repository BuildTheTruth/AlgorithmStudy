#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

struct pos {
	int x, y;
};

int W[12][12];
int nCase, nClient;
pos company, home, client[11];
vector<int> ans_set;

int main()
{
	cin >> nCase;
	for (int c = 0; c < nCase; c++)
	{
		cin >> nClient;
		cin >> company.x >> company.y;
		cin >> home.x >> home.y;
		for (int i = 1; i <= nClient; i++)
			cin >> client[i].x >> client[i].y;

		for (int i = 1; i <= nClient; i++)
			W[0][i] = abs(company.x - client[i].x) + abs(company.y - client[i].y);

		for (int i = 1; i <= nClient; i++)
			for (int j = 1; j <= nClient; j++)
				W[i][j] = abs(client[i].x - client[j].x) + abs(client[i].y - client[j].y);

		for (int i = 1; i <= nClient; i++)
			W[i][nClient + 1] = abs(home.x - client[i].x) + abs(home.y - client[i].y);

		vector<int> v;
		for (int i = 1; i <= nClient; i++)
			v.push_back(i);
		int sum, ans = 10000;
		do{
			sum = W[0][v[0]];
			for (int i = 0; i < nClient - 1; i++){
				sum += W[v[i]][v[i + 1]];
			}
			sum += W[v[nClient - 1]][nClient + 1];
			ans = min(ans, sum);
		} while (next_permutation(v.begin(), v.end()));
		ans_set.push_back(ans);
	}

	for (int c = 0; c < nCase; c++)
	{
		cout << "#" << c + 1 << " ";
		cout << ans_set[c] << endl;
	}

	return 0;
}