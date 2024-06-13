#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int n;
	int fail = 0;
	cin >> n;
	vector<string> words;
	string mystring;
	words.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> words[i];
	}
	cin >> mystring;
	for (int i = 0; i < n; i++)
	{
		vector<char> mychars(mystring.begin(), mystring.end());
		for (int j = 0; j < words[i].size(); j++)
		{
			for (int q = 0; q < mychars.size(); q++)
			{
				if (mychars[q] == words[i][j])
				{
					mychars[q] = 0;
					break;
				}
				if (q == mychars.size() - 1)
				{
					for (int z = 0; z < mychars.size(); z++)
					{
						if (mychars[z] == '?')
						{
							mychars[z] = 0;
							break;
						}
					}
				}
			}
		}
	}
	cout << n - fail;
	return 0;
}