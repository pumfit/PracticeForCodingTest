/*
13300 �� ����

https://www.acmicpc.net/problem/13300

�� ������ 1-6�г� ������ ����
�����غ��� �迭�̸��� room�� �ƴϿ��� �� �� ����.
*/
#include <iostream>
using namespace std;

int room[7][2] = { 0, };

int main() {
	int N, K, answer = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int S, Y;
		cin >> S >> Y;
		room[Y][S]++;
	}
	for (int i = 1; i < 7; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			answer += room[i][j] % K == 0 ? room[i][j] / K : room[i][j] / K + 1;
		}
	}
	cout << answer;
	return 0;
}