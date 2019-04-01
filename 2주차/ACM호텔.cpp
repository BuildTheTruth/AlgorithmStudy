#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t, h, w, n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x = 1;
		string room;
		cin >> h >> w >> n;
		while (n > h) {
			n -= h; 
			x++;
		}
		room += to_string(n);
		if (x < 10) room += '0';
		room += to_string(x);
		cout << room << endl;
	}

	return 0;
}