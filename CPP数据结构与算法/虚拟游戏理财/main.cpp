#include<vector>
#include<iostream>
#include <chrono>
using namespace std;

struct Sample
{
	//�ر���
	int inrat;
	//����
	int outrat;
	//�޶�
	int limitcash;
};
struct Result
{
	int idx;
	int number;
	int max;
};

void get(vector<Sample>& samples, int& n) {
	for (int i = 0; i < n; i++)
	{
		cin >> samples[i].inrat;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> samples[i].outrat;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> samples[i].limitcash;
	}
}


int main() {
	//��Ŀ������Ͷ�ʶ���ܵķ��ն�
	int n, cash, x;
	cin >> n >> cash >> x;
	vector<Sample> samples;
	samples.resize(n);
	get(samples, n);
	// ��ȡ����ʼ����ʱ��ʱ���
	auto start = std::chrono::high_resolution_clock::now();

	// �����������ĳ����߼�
	int max = 0;
	Result result;
	//���Ͷ�ʶ���
	vector<Result> results;
	results.resize(2);
	//Ͷ�ʵ���
	for (int i = 0; i < n; i++)
	{
		int number = 0;
		int tempmax = 0;
		if (samples[i].outrat < x)
		{
			if (cash > samples[i].limitcash)
			{
				number = samples[i].limitcash;
			}
			else if (cash <= samples[i].limitcash)
			{
				number = cash;
			}
			tempmax = samples[i].inrat * number;
			if (tempmax > max)
			{
				max = tempmax;
				result.idx = i;
				result.number = number;
				result.max = max;
			}
		}
	}
	//Ͷ�ʶ���
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (samples[i].outrat + samples[j].outrat <= x)
			{
				if (samples[i].inrat > samples[j].inrat && samples[i].limitcash < cash)
				{
					int number1 = samples[i].limitcash;
					int number2 = cash - number1;
					if (number2 > samples[j].limitcash)
					{
						number2 = samples[j].limitcash;
					}
					int tempmax = samples[i].inrat * number1 + samples[j].inrat * number2;
					if (tempmax > max)
					{
						max = tempmax;
						Result result1, result2;
						result1.idx = i;
						result1.number = number1;
						result1.max = max;
						result2.idx = j;
						result2.number = number2;
						result2.max = max;
						results[0] = result1;
						results[1] = result2;
					}
				}
				else if (samples[j].inrat > samples[i].inrat && samples[j].limitcash < cash)
				{
					int number1 = samples[j].limitcash;
					int number2 = cash - number1;
					if (number2 > samples[i].limitcash)
					{
						number2 = samples[i].limitcash;
					}
					int tempmax = samples[j].inrat * number1 + samples[i].inrat * number2;
					if (tempmax > max)
					{
						max = tempmax;
						Result result1, result2;
						result1.idx = j;
						result1.number = number1;
						result1.max = max;
						result2.idx = i;
						result2.number = number2;
						result2.max = max;
						results[1] = result1;
						results[0] = result2;
					}
				}
			}
		}
	}
	if (result.max > results[0].max)
	{
		for (int i = 0; i < n; i++)
		{
			if (result.idx == i)
			{
				cout << result.number;
			}
			else
			{
				cout << 0;
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (i == results[0].idx)
			{
				cout << results[0].number << " ";
				continue;
			}
			else if (i == results[1].idx)
			{
				cout << results[1].number << " ";
				continue;
			}
			cout << 0 << " ";
			continue;
		}
	}
	// ��ȡ�������ʱ��ʱ���
	auto end = std::chrono::high_resolution_clock::now();

	// �����������ʱ��
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	// �����������ʱ�䣨�Ժ���Ϊ��λ��
	std::cout << "���������� " << duration.count() << " ����" << std::endl;

	return 0;
}