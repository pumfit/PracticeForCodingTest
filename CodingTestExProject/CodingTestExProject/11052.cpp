/*
11052 카드 구매하기

BackTracking으로 풀면되겠다!했다가 시간초과 받은 문제
N = 1000이라 단계수가 많아져 테케 이후로는 풀이가 불가능한 것 같았다. 시간초과 이유에 대해서 잘 아는 것도 중요

DP로 해당 문제를 풀어야하고 이중for문을 사용해서 값을 계산해야한다.
dp 기본 문제인 느낌이지만 풀면서 DP인지 정말 모르겠는 느낌 왜 DP로 풀어야하는지 생각해보고
비슷한 DP문제를 풀어야 할 것 같다.
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