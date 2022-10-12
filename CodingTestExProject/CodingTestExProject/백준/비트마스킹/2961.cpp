/*
2961 �����̰� ���� ���ִ� ����

�ش� ������ Ǯ�� ���ؼ� �κ������� ��� ���ѵ� ���� ����� ���� ���̰� ���� ��츦
ã���� �� �� ���ٰ� �����ߴ�.

�������� �κ������� next_permutation���� ���߾��µ�

��Ʈ����ŷ�� ����� Ǯ�̸� �����غ��Ҵ�.
������ �����ߴ� ��Ʈ�� �����Ǵ��� ����ϸ� ���� �κ������� ���� �� �ִ�.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, S, B;
	int answer = 2e9;
	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		cin >> S >> B;
		v.push_back({ S,B });
	}
	int sumS = 1, sumB = 0; int sum = 0;
	for (int i = 1; i < (1 << N); i++) // �������� ���������ʴ´�.
	{
		for (int k = 0; k < N; k++)//0~(N-1) N �ڸ��� 
		{
			if (i & (1 << k))
			{
				sumS *= v[k].first;
				sumB += v[k].second;
			}
		}

		sum = sumS - sumB > 0 ? sumS - sumB : sumB - sumS;
		answer = min(answer, sum);
		sumS = 1; sumB = 0;
	}
	cout << answer;
	return 0;
}
