#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> ans;
	vector<int> ans_temp;
	int cryptos[100];
	int cryptos_len, command_cnt;
	char insert_command;
	int insert_index, insert_cnt, insert_temp;

	for (int i = 0; i < 10; i++)
	{
		cin >> cryptos_len;
		for (int nCryptos = 0; nCryptos < cryptos_len; nCryptos++)
			cin >> cryptos[nCryptos];
		cin >> command_cnt;
		for (int nCommand = 0; nCommand < command_cnt; nCommand++)
		{
			cin >> insert_command >> insert_index >> insert_cnt;
			for (int nInsert = 0; nInsert < insert_cnt; nInsert++){
				cin >> insert_temp;
				for (int idx = cryptos_len; idx > nInsert + insert_index; idx--)
					cryptos[idx] = cryptos[idx - 1];
				cryptos[nInsert + insert_index] = insert_temp;
			}
		}
		for (int j = 0; j < 10; j++)
			ans_temp.push_back(cryptos[j]);

		ans.push_back(ans_temp);
		ans_temp.clear();
	}

	for (int i = 0; i < 10; i++)
	{
		printf("#%d ", i + 1);
		for (int j = 0; j < 10; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}

	return 0;
}