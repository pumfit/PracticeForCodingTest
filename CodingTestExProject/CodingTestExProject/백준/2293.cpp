/*
2293 ���� 1

n���� ������ ������ �ִ�. ������ ������ ��Ÿ���� ��ġ�� �ٸ���. 
�� ������ ������ ����ؼ�, �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�. 
�� ����� ���� ���Ͻÿ�. ������ ������ �� ���� ����� �� �ִ�.

����� ������ ������ ������, ������ �ٸ� ���� ���� ����̴�.
*/
#include<iostream>
using namespace std;

int N, K;
int arr[101];
int memo[10001];

int dp()
{
	for (int i = 0; i < N; i++)// ���� ������ŭ �ݺ�
	{
		for (int j = arr[i]; j <= K; j++) //j = ���� �� ~ (��)K����
		{
			memo[j] += memo[j - arr[i]];
			//cout << "memo[" << j << "]" << ":" << memo[j] << " ";
		}
		//cout << endl;
	}
	return memo[K];
}

int main()
{
	cin >> N >> K;
	memo[0] = 1;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cout<<dp();
}