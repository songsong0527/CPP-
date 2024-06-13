#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int h, n;
bool cmp(int A, int B)//重载运算符
{
	//如果身高差绝对值不同，按照身高差绝对值由小到大排序
	if (abs(A - h) != abs(B - h)) {
		return abs(A - h) < abs(B - h);
	}
	//身高差绝对值相同，按照身高从小到大排序
	return A < B;
}

int main()
{
	vector<int> a;
	//处理输入
	cin >> h >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), cmp);
	//输出结果
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	return 0;
}