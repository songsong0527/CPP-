#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

int main() {
	float minavg;
	cin >> minavg;
	vector<float> arr;
	string s;
	cin.ignore();
	getline(cin, s);
	string token;
	istringstream ss(s);
	while (getline(ss, token, ' '))
	{
		arr.push_back(stof(token));
	}
	struct MyStruct
	{
		int begin;
		int end;
	};
	vector<MyStruct> models;
	for (int i = 0; i < arr.size() - 1; i++)
	{
		float sum = arr[i];
		float count = 1;
		MyStruct model;
		model.begin = i;
		for (int j = i + 1; j < arr.size(); j++)
		{
			sum += arr[j];
			count++;
			float avg = sum / count;
			if (avg <= minavg)
			{
				model.end = j;
				models.push_back(model);
			}
			else
			{
				break;
			}
		}
	}
	vector<int> idx;
	int maxlength = 0;
	for (int i = 0; i < models.size(); i++)
	{
		if (models[i].end != NULL)
		{
			int length = models[i].end - models[i].begin;
			if (length > maxlength)
			{
				maxlength = length;
			}
		}
	}
	for (int i = 0; i < models.size(); i++)
	{
		if (models[i].end != NULL)
		{
			int length = models[i].end - models[i].begin;
			if (length == maxlength)
			{
				idx.push_back(i);
			}
		}
	}
	for (int i = 0; i < idx.size(); i++)
	{
		if (i != idx.size() + 1)
		{
			cout << models[idx[i]].begin << "-" << models[idx[i]].end << " ";
		}
		else
		{
			cout << models[idx[i]].begin << "-" << models[idx[i]].end;
		}
	}
}