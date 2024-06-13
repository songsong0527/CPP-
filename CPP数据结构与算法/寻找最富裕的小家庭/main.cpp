#include <iostream>
#include <vector>
#include <map>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> cash;
	cash.resize(n);
	for (int i = 0; i < cash.size(); i++)
	{

		cin >> cash[i];
	}
	vector<pair<int, int>> homes;
	for (int i = 0; i < n - 1; i++)
	{
		pair<int, int> home;
		cin >> home.first >> home.second;
		homes.push_back(home);
	}
	map<int, vector<int>> maps;//依次为子节点和父节点

	for (auto& homei : homes) {
		maps[homei.first].push_back(homei.second);
	}
	int maxsum = 0;
	for (auto& pairi : maps) {
		int sum = 0;
		sum += cash[pairi.first - 1];//父节点
		//子节点
		for (int& idxi : pairi.second) {
			sum += cash[idxi - 1];
		}
		if (sum > maxsum)
		{
			maxsum = sum;
		}
	}
	cout << maxsum;
}
