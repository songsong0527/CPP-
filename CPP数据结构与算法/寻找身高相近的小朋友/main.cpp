#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int h, n;
bool cmp(int A, int B)//���������
{
	//�����߲����ֵ��ͬ��������߲����ֵ��С��������
	if (abs(A - h) != abs(B - h)) {
		return abs(A - h) < abs(B - h);
	}
	//��߲����ֵ��ͬ��������ߴ�С��������
	return A < B;
}

int main()
{
	vector<int> a;
	//��������
	cin >> h >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), cmp);
	//������
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	return 0;
}