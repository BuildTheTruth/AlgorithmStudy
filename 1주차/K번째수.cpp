#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> tmp, ans;
	for (vector<int> comm : commands) {
		tmp = array;
		sort(tmp.begin() + comm[0] - 1, tmp.begin() + comm[1]);
		ans.push_back(tmp[comm[0] + comm[2] - 2]);
	}
	return ans;
}
