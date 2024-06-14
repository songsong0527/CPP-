#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 将十进制数转换为任意进制
string decimalToAnyBase(int k, int n) {
	string result = "";
	while (k > 0) {
		int remainder = k % n;

		// 将余数转换为对应的字符
		if (remainder < 10) {
			result += to_string(remainder);
		}
		else {
			result += (char)('a' + remainder - 10);
		}
		k /= n;
	}
	// 结果字符串需要逆序
	reverse(result.begin(), result.end());

	return result;
}

int main() {
	int k, n;
	char m;
	cin >> k >> m >> n;
	string result = decimalToAnyBase(k, n);
	int count = 0;
	for (auto mychar : result) {
		if (mychar == m)
		{
			count++;
		}
	}
	cout << count;

	return 0;
}
