#include <stdio.h>
#include <cmath>

using namespace std;

int reserved(int k)
{
	int ret = 0;
	for (int i = 1; i <= k; i++)
		ret += i;
	return ret;
}

int main()
{
	int T, x, y;
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int k = 1, cnt = 0, maxK, rsv;
		scanf("%d %d", &x, &y);
		maxK = sqrt(y - x);
		rsv = reserved(maxK);
		while (y - x > rsv)
		{
			x += k; cnt++;
			if (k < maxK) k++;
		}
		cnt += k;
		printf("%d\n", cnt);
	}

	return 0;
}