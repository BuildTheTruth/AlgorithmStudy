#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct stick {
	int bgn, end;
};

int solution(string arrangement) {
	int ans = 0;
	int len = arrangement.length();
	vector<int> laser_set;
	vector<stick> stick_set;
	stack<stick> stick_stack;
	stack<char> s;

	for (int i = 0; i < len; i++)
		if (arrangement[i] == ')'){
			if (arrangement[i - 1] == '(') 
				laser_set.push_back(i - 1);
			else {
				stick_stack.top().end = i;
				stick_set.push_back(stick_stack.top());
			}
			stick_stack.pop();
			s.pop();
		}
		else {
			s.push(arrangement[i]);
			stick_stack.push({ i, -1 });
		}

	for (stick s : stick_set) {
		int cnt = 0;
		for (int laser : laser_set) {
			if (s.bgn < laser && laser + 1 < s.end){
				if (!cnt) cnt = 1;
				cnt++;
			}
		}
		ans += cnt;
	}

	return ans;
}

int main()
{
	string arrangement = "()(((()())(())()))(())";
	cout << solution(arrangement) << endl;
	return 0;
}