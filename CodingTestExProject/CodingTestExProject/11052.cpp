/*
11052 ī�� �����ϱ�

BackTracking���� Ǯ��ǰڴ�!�ߴٰ� �ð��ʰ� ���� ����
N = 1000�̶� �ܰ���� ������ ���� ���ķδ� Ǯ�̰� �Ұ����� �� ���Ҵ�. �ð��ʰ� ������ ���ؼ� �� �ƴ� �͵� �߿�

DP�� �ش� ������ Ǯ����ϰ� ����for���� ����ؼ� ���� ����ؾ��Ѵ�.
dp �⺻ ������ ���������� Ǯ�鼭 DP���� ���� �𸣰ڴ� ���� �� DP�� Ǯ����ϴ��� �����غ���
����� DP������ Ǯ��� �� �� ����.
*/

#include <iostream>
using namespace std;

int N;
int arr[1001] = { 0, };
int dp[1001] = { 0, };

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	arr[0] = dp[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		}
	}
	cout << dp[N];
	return 0;
}

/*
#include <iostream>
using namespace std;

int N;
int arr[1001];
int answer = 0;

void bt(int sum,int money)
{
	if(sum>N)
		return;
	if(sum==N)
	{
		answer = max(money,answer);
		return;
	}
	for(int i=0;i<N;i++)
	{
		bt(i+1+sum,money+arr[i]);
	}
}

int main() {
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>arr[i];
	bt(0,0);
	cout<<answer;
	return 0;
}
*/