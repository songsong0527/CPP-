#include<iostream>
#include<vector>
using namespace std;

int main() {
	int gpu, n;
	cin >> gpu >> n;
	vector<int> arr;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int time = 0;
	//未处理的任务
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (gpu >= arr[i] + temp)
		{
			time++;
			temp = 0;
		}
		if (gpu < arr[i] + temp)
		{
			temp = arr[i] + temp - gpu;
			time++;
		}
	}
	while (temp > 0)
	{
		temp -= gpu;
		time++;
	}
	cout << time;
	return 0;
}
