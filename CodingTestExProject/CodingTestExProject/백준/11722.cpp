/*
11722 ���� �� �����ϴ� �κ� ����

���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ���� A = {10, 30, 10, 20, 20, 10} �� ��쿡 
���� �� �����ϴ� �κ� ������ A = {10, 30, 10, 20, 20, 10}  �̰�, ���̴� 3�̴�.

�������� dp���� �����ϸ鼭 ������ �Ǽ��ߴ� �κ��� idx 0�κκ� �ʱ�ȭ�� ���� �ʰ� �����ߴ�.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];
int answer;
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	dp[0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[j] = max(dp[i] + 1, dp[j]);
			}
			else
			{
				dp[j] = max(1, dp[j]);
			}
		}

		answer = max(answer, dp[i]);
	}
	cout << answer;
	return 0;
}