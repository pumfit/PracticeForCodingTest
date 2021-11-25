/*
1149 RGB�Ÿ�

RGB�Ÿ����� ���� N�� �ִ�. �Ÿ��� �������� ��Ÿ�� �� �ְ�, 1�� ������ N�� ���� ������� �ִ�.

���� ����, �ʷ�, �Ķ� �� �ϳ��� ������ ĥ�ؾ� �Ѵ�. ������ ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� �־����� ��, �Ʒ� ��Ģ�� �����ϸ鼭 ��� ���� ĥ�ϴ� ����� �ּڰ��� ���غ���.

1�� ���� ���� 2�� ���� ���� ���� �ʾƾ� �Ѵ�.
N�� ���� ���� N-1�� ���� ���� ���� �ʾƾ� �Ѵ�.
i(2 �� i �� N-1)�� ���� ���� i-1��, i+1�� ���� ���� ���� �ʾƾ� �Ѵ�.

ó���� dfs�� Ǯ�ٰ� n=1000�� ���� �ð��ʰ��� �� �� ���Ƽ� �ٸ� ����� �����غ��Ұ� �賶���� �賶����,��繮���� ��������. 
dp �� Ǯ���� ������ �� �ִ°���� ���� �ΰ����� ������ dp�� ��ü ����ϵ��� �Ͽ���.

*/
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int m = 1001 * 1001;
int arr[1001][3];
int minArr[1001][3];

int dp(int n, int i)
{
	if (minArr[n][i] != 0)
		return minArr[n][i];
	if (i == 0)
	{
		return minArr[n][0] = min(dp(n - 1, 1), dp(n - 1, 2)) + arr[n][i];
	}
	else if (i == 1)
	{
		return minArr[n][1] = min(dp(n - 1, 0), dp(n - 1, 2)) + arr[n][i];
	}
	else if (i == 2)
	{
		return minArr[n][2] = min(dp(n - 1, 0), dp(n - 1, 1)) + arr[n][i];
	}

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	minArr[0][0] = arr[0][0]; minArr[0][1] = arr[0][1]; minArr[0][2] = arr[0][2];
	cout << min(dp(N, 0), min(dp(N, 1), dp(N, 2))) << endl;

	return 0;
}