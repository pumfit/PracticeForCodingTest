/*
2491 ����

0�������� 9������ ���ڷ� �̷���� N���� ���ڰ� ������ ������ �ִ�. �� ���� �ȿ��� �����ؼ� Ŀ���ų�(���� �� ����), Ȥ�� �����ؼ� �۾�����(���� �� ����) ���� �� ���� ���̰� �� ���� ã�Ƴ��� �� ���̸� ����ϴ� ���α׷��� �ۼ��϶�.

���� ��� ���� 1, 2, 2, 4, 4, 5, 7, 7, 2 �� ��쿡�� 1 �� 2 �� 2 �� 4 �� 4 �� 5 �� 7 �� 7 �� ���� �� ������ �ǹǷ� �� ���� 8�� ����Ѵ�. 
���� 4, 1, 3, 3, 2, 2, 9, 2, 3 �� ��쿡�� 3 �� 3 �� 2 �� 2 �� ���� �� ������ �ǹǷ� �� ���� 4�� ����Ѵ�. 
�� 1, 5, 3, 6, 4, 7, 1, 3, 2, 9, 5 �� ��쿡�� 
�����ؼ� Ŀ���ų� �۾����� ������ ���̰� 3 �̻��� ��찡 �����Ƿ� 2�� ����Ͽ��� �Ѵ�.

�� ���ڸ��� DP����
96�ۿ��� �ѹ� Ʋ�Ⱦ��µ�
dp�ʱ�ȭ�� �� dp[0]= 1�� ������ �� 100�۴뿡�� �� Ʋ�ȴ�.
�ٸ� Ǯ�� �����Ѱ�쵵 Ʋ���� �̻��ϴ� ������ ���� m �ʱ�ȭ�� 0���� �Ѱ��� ������.
�̷��� �ϸ� N 1�϶� 0�� �ִ����� ���� �翬�� Ʋ����.
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[100001];
int dp[100001];
int N;

int main()
{
	cin >> N;
	int m = 1;
	dp[0] = 1;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 1; i < N; i++)
	{
		if (arr[i - 1] <= arr[i])
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			dp[i] = 1;
		}
		m = max(m, dp[i]);
	}
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i < N; i++)
	{
		if (arr[i - 1] >= arr[i])
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			dp[i] = 1;
		}
		m = max(m, dp[i]);
	}
	cout << m;
}
/*
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[100001];
int dp1 =1,dp2 = 1;
int N;

int main()
{
	int m = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 1; i < N; i++)
	{
		if (arr[i-1] <= arr[i])
		{
			dp1++;
		}
		else
		{
			dp1 = 1;
		}
		if (arr[i - 1] >= arr[i])
		{
			dp2++;
		}
		else
		{
			dp2 = 1;
		}
		m = max(m, max(dp1,dp2));
	}
	cout << m;
}
*/
