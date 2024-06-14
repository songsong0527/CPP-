#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ��ʮ������ת��Ϊ�������
string decimalToAnyBase(int k, int n) {
	string result = "";
	while (k > 0) {
		int remainder = k % n;

		// ������ת��Ϊ��Ӧ���ַ�
		if (remainder < 10) {
			result += to_string(remainder);
		}
		else {
			result += (char)('a' + remainder - 10);
		}
		k /= n;
	}
	// ����ַ�����Ҫ����
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
