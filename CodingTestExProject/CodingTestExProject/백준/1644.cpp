/*
1644 �Ҽ��� ���� ��

https://www.acmicpc.net/problem/1644

�Ҽ��� ü�� N������ �Ҽ��� ���ϰ� �������͸� ���� Ǯ�� �Ǵ� ����

			if (ed == v.size())
				break;

	�ش� ������ sum�� N�̵Ǵ� �Ŀ� �־��ٰ� 96���뿡 Ʋ�Ⱦ��µ� ���ܸ� ã�Ⱑ �������.
	������ ���� 2�� ���� st == ed == 0�� ��� �ش�Ǵ� ���ǿ��� ���ܰ� �����.
	�ε��� �����̹Ƿ� �ε��� ������ �ٷ� ���� ���� üũ������ϰ� ���� ���� ��� �غ��� ���ڴٴ� ������ �� ����

+) �ش� Ǯ�̷� N�� �ִ밪�� 4,000,000�� ������ 1�� ������ 1.49s ���� �ҿ�ȴ�.
*/

#include <iostream>
#include <vector>
using namespace std;

bool CheckPrimeNum(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	int N;
	cin >> N;
	vector<int> v;
	int answer = 0;

	for (int i = 1; i <= N; i++)
	{
		if (CheckPrimeNum(i))
		{
			v.push_back(i);
			if (i == N)
				answer++;
		}
	}
	int sum = 0; int ed = 0;
	for (int st = 0; st < v.size(); st++)
	{
		while (sum <= N)
		{
			if (ed == v.size())
				break;
			if (sum == N)
			{
				answer++;
				break;
			}
			sum += v[ed];
			ed++;
		}
		if (ed == v.size())
			continue;

		sum -= v[st];
	}
	cout << answer;
	return 0;
}