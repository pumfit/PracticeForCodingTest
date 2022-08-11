/*
2669 직사각형 네개의 합집합의 면적 구하기
https://www.acmicpc.net/problem/2669
*/
#include <iostream>
using namespace std;

int main() {
	int cnt = 0;
	int map[101][101] = { 0, };
	for (int i = 0; i < 4; i++)
	{
		int A, B, C, D;
		cin >> A >> B >> C >> D;
		for (int j = A; j < C; j++)
		{
			for (int k = B; k < D; k++)
			{
				map[j][k]++;
			}
		}
	}
	for (int j = 0; j < 101; j++)
	{
		for (int k = 0; k < 101; k++)
		{
			if (map[j][k])
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}