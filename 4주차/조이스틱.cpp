#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
	int ans = 0, idx = 0, sw = 1, move_cnt = 0;
	int len = name.length();
	string base;

	for (int i = 0; i < len; i++)
		base += 'A';

	while (base != name) {
		if (name[idx] - 'A' <= 13)
			ans += name[idx] - 'A';
		else
			ans += 26 - (name[idx] - 'A');

		name[idx] = 'A';
		if (base == name) break;

		int left = 0, right = 0;
		int i = idx;
		while (name[i] == 'A') {
			if (++i >= len) i = 0;
			right++;
		}

		i = idx;
		while (name[i] == 'A') {
			if (--i < 0) i = len - 1;
			left++;
		}

		if (left < right) sw = -1;
		else if (left > right) sw = 1;

		idx += sw;
		if (idx < 0) idx = len - 1;
		else if (idx > len - 1) idx = 0;
		ans += 1;
	}
	
	return ans;
}

int main()
{
	string name = "AZAAAZ";
	cout << solution(name);
	return 0;
}