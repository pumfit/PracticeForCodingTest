/*
5533 유니크

카운트를 올려서 비교하는방식으로 문제풀이를 진행했는데 전체탐색을 진행하다보니 시간적으로
8ms가 걸렸다.
			  if (a[i][k] == a[j][k] && i != j)
				{
					cnt = 1;
					break;
				}
와 같이 받아온 이차원배열을 비교하는 for문을 바로 사용하는 것이 더 좋은 풀이 인 것 같다.
*/
#include<iostream>
using namespace std;

int main()
{
	int N;
	int arr[202][3];
	int score[202] = {0,};
	cin >> N;

	for (int i=0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int n;
			cin >> n;
			arr[i][j] = n;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		int num[101] = { 0, };
		for (int j = 0; j < N; j++)
		{
			num[arr[j][i]]++;
		}
		for (int j = 0; j < N; j++)
		{
			if (num[arr[j][i]] == 1)
				score[j] += arr[j][i];
		}
	}
	for (int j = 0; j < N; j++)
	{
		cout << score[j] << endl;
	}
}