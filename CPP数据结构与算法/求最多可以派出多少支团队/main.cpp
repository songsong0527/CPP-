#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	vector<int> peoples;
	int req;//要求
	int result = 0;
	cin >> n;

	peoples.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> peoples[i];
	}
	cin >> req;
	//判断单人参加
	for (auto& people : peoples) {
		if (people >= req)
		{
			people = 0;
			result++;
		}
	}
	//判断多人参加
	struct Temp
	{
		int i;
		int j;
		int mreq;
	};
	vector<Temp> temps;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int comp = peoples[i] + peoples[j];
			if (comp >= req)
			{
				Temp temp;
				temp.i = i;
				temp.j = j;
				temp.mreq = comp;
				temps.push_back(temp);
			}
			if (j == n - 1 && temps.size() != 0)
			{
				sort(temps.begin(), temps.end(), [](const Temp& t1, const Temp& t2) {
					return t1.mreq < t2.mreq;
					});
				peoples[temps[0].i] = 0;
				peoples[temps[0].j] = 0;
				temps.clear();
				result++;
			}
		}
	}
	cout << result;
}