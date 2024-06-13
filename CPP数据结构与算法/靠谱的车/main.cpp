#include<iostream>

using namespace std;

int main() {
	int fake;
	cin >> fake;
	int count = 0;
	for (int i = 1; i <= fake; i++)
	{
		bool flag = true;
		int temp = i;
		while (temp > 10)
		{
			if (temp % 10 == 4)
			{
				count++;
				flag = false;
			}
			temp /= 10;
		}
		if (temp % 10 == 4 && flag)
		{
			count++;
		}
	}
	cout << fake - count;
}