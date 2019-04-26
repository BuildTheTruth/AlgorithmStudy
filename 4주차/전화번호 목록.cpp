#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2)
{
	return s1.length() < s2.length();
}

bool solution(vector<string> phone_book) {
	int n = phone_book.size(), len;
	string tmp;
	sort(phone_book.begin(), phone_book.end(), cmp);
	for (int i = 0; i < n - 1; i++)
	{
		len = phone_book[i].size();
		for (int j = i + 1; j < n; j++){
			tmp = phone_book[j].substr(0, len);
			if (phone_book[i] == tmp) 
				return false;
		}
	}

	return true;
}