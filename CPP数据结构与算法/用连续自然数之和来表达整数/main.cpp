#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int> result) {
	int sum = 0;

	for (int& resulti : result) {
		sum += resulti;
	}
	return sum;
}

void show(vector<int> result, int a) {
	printf("%d=", a);
	for (int i = result.size() - 1; i >= 0; i--)
	{
		if (i != 0)
		{
			printf("%d+", result[i]);
		}
		else
		{
			printf("%d\n", result[i]);
		}
	}
}

int main() {
	int a;
	cin >> a;
	vector<int> result;
	int count = 0;
	for (int i = a; i > 1; i--)
	{
		result.clear();
		result.push_back(i);
		for (int j = i - 1; j >= 1; j--)
		{
			result.push_back(j);
			if (i == a)
			{
				printf("%d=%d\n", a, i);
				count++;
			}
			if (sum(result) > a)
			{
				result.clear();
				break;
			}
			else if (sum(result) == a)
			{
				show(result, a);
				result.clear();
				count++;
			}
		}
	}
	printf("Result=%d", count);
}