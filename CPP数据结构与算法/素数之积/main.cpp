#include<iostream>
#include<vector>

using namespace std;

bool charg(int factor) {
	for (int i = factor - 1; i > 0; i--)
	{
		if (factor % i == 0 && i != 1)
		{
			return false;
		}
	}
	return true;
}

int main() {
	int a;
	cin >> a;
	bool flag = true;
	if (a > 1)
	{
		for (int i = a - 1; i > 0; i--)
		{
			if (charg(i))
			{
				for (int j = i - 1; j > 0; j--)
				{
					if (charg(j))
					{
						if (i * j == a)
						{
							printf("%d %d", j, i);
							flag = false;
							break;
						}
					}
				}
			}
		}
	}
	if (flag)
	{
		printf("%d %d", -1, -1);
	}
}