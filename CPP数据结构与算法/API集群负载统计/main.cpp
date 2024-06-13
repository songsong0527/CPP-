#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

struct MyStruct
{
	int level;
	string name;
};

int main() {
	int n;
	cin >> n;
	vector<MyStruct> urls;
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		string url;
		string token;
		cin >> url;
		MyStruct single;
		istringstream tokenstream(url);
		while (getline(tokenstream, token, '/'))
		{

			if (!token.empty())
			{
				j++;
				single.name = token;
				single.level = j;
				urls.push_back(single);
			}
		}
	}
	MyStruct target;
	cin >> target.level >> target.name;
	int count = 0;
	for (auto& url : urls) {
		if (url.level == target.level && url.name == target.name)
		{
			count++;
		}
	}
	cout << count;
	return 0;
}