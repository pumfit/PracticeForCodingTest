/*
13300 방 배정

https://www.acmicpc.net/problem/13300

방 배정시 1-6학년 범위에 조심
생각해보니 배열이름이 room이 아니여야 할 것 같다.
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