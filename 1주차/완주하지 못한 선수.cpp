#include <string>
#include <vector>
#include <map>
using namespace std;
string solution(vector<string> participant, vector<string> completion) {
	string ans;
	map<string, int> part;
	for (auto s : participant) part[s]++;
	for (auto s : completion) part[s]--;
	for (auto s : participant) if (part[s]) ans = s;
	return ans;
}


