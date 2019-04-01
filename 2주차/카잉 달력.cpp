#include <stdio.h>

using namespace std;

int main()
{
	int T, M, N, x, y;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		scanf("%d %d %d %d", &M, &N, &x, &y);
		int i = 0, j = 0, k;
		while (1) {
			if (M*i + x > N*j + y) j++;
			else if (M*i + x < N*j + y) i++;
			else {
				k = N*j + y;
				break;
			}
			if (M*i + x > 40000 * 40000) {
				k = -1;
				break;
			}
		}
		printf("%d\n", k);
	}

	return 0;
}