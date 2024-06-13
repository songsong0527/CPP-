#include<iostream>
#include<vector>

using namespace std;

int sum(vector<int> nums) {
	int a = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		a += nums[i];
	}
	return a;
}



int main() {
	vector<int> A, B;
	int numbera, numberb;
	cin >> numbera >> numberb;
	A.resize(numbera);
	B.resize(numberb);
	for (int i = 0; i < numbera; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < numberb; i++)
	{
		cin >> B[i];
	}
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
		{
			int temp = A[i];
			A[i] = B[j];
			B[j] = temp;
			if (sum(A) == sum(B))
			{
				cout << temp << " " << A[i];
				return 0;
			}
			else
			{
				B[j] = A[i];
				A[i] = temp;
			}
		}
	}
}