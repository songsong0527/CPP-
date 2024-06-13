#include<iostream>
#include<string>
#include<vector>
#include<map>;
#include<algorithm>
using namespace std;

struct MyWeight
{
	int watch;
	int star;
	int fork;
	int issue;
	int mr;
};

bool compare(pair<string, int> pair1, pair<string, int> pair2) {
	if (pair1.second == pair2.second)
	{
		return pair1.first < pair2.first;//从小到大
	}
	return pair1.second > pair2.second;//从大到小

}


int main() {
	MyWeight weight;
	int n;
	cin >> n;
	cin >> weight.watch >> weight.star >> weight.fork >> weight.issue >> weight.mr;
	vector<pair<string, int>> pairs;
	for (int i = 0; i < n; i++)
	{
		string name;
		MyWeight value;
		cin >> name >> value.watch >> value.star >> value.fork >> value.issue >> value.mr;
		int hot = 0;
		hot += value.watch * weight.watch;
		hot += value.star * weight.star;
		hot += value.fork * weight.fork;
		hot += value.issue * weight.issue;
		hot += value.mr * weight.mr;
		pairs.push_back(make_pair(name, hot));
	}
	sort(pairs.begin(), pairs.end(), compare);
	for (auto& pair : pairs) {

		cout << pair.first << endl;
	}

}