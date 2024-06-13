#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
int main() {
	string str;
	getline(cin, str);
	istringstream ss(str);
	vector<char> arr;
	for (int i = 0; i < str.length(); i++)
	{
		arr.push_back(str[i]);
	}
	struct MyStruct
	{
		int begin;
		int end;
	};
	vector<MyStruct> models;
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int xcount = 0;
		int ycount = 0;
		MyStruct model;
		model.begin = i;
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i] == 'X')
			{
				xcount++;
			}
			else
			{
				ycount++;
			}
			if (arr[j] == 'X')
			{
				xcount++;
			}
			else
			{
				ycount++;
			}
			if (xcount == ycount)
			{
				model.end = j;
				i = j;
				models.push_back(model);
				break;
			}
		}
	}
	cout << models.size() << endl;
}