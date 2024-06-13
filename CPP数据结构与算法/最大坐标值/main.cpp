#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	int luckynum;
	cin >> luckynum;
	vector<int> nums;
	nums.resize(n);
	for (int i = 0; i < nums.size(); i++)
	{
		cin >> nums[i];
	}
	int step = 0;
	int maxstep = 0;
	for (int& numsi : nums) {
		if (numsi == luckynum && luckynum > 0)
		{
			step = step + numsi + 1;
		}
		else if (numsi == luckynum && luckynum < 0)
		{
			step = step + numsi - 1;
		}
		else
		{
			step += numsi;
		}
		if (step > maxstep)
		{
			maxstep = step;
		}
	}
	cout << maxstep;
}