#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#define LEFT 0
#define RIGHT 1
#define LENGTH 100

using namespace std;

vector<vector<int>> tree;
vector<char> word;
vector<string> ans;
string str;

void inorder(int v)
{
	if (tree[v][LEFT] != -1) inorder(tree[v][LEFT]);
	str += word[v];
	if (tree[v][RIGHT] != -1) inorder(tree[v][RIGHT]);
}

int main()
{
	int n, root, leftChild, rightChild;
	char line[LENGTH], w;
	char delim[2] = " ", *temp;

	for (int i = 1; i <= 10; i++) {
		str = "";
		cin >> n; cin.ignore();
		tree.resize(n + 1);
		word.resize(n + 1);
		for (int j = 0; j < n; j++){
			cin.getline(line, LENGTH);
			temp = strtok(line, delim);
			root = atoi(temp);
			temp = strtok(NULL, delim);
			word[root] = temp[0];
			temp = strtok(NULL, delim);
			if (temp) leftChild = atoi(temp);
			else leftChild = -1;
			temp = strtok(NULL, delim);
			if (temp) rightChild = atoi(temp);
			else rightChild = -1;
			tree[root].push_back(leftChild);
			tree[root].push_back(rightChild);
		}
		inorder(1);
		ans.push_back(str);
		tree.clear();
		word.clear();
	}

	for (int i = 1; i <= 10; i++)
		cout << "#" << i << " " << ans[i - 1] << endl;

	return 0;
}