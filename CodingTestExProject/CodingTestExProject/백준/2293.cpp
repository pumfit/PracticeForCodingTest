/*
2293 동전 1

n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 
이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 
그 경우의 수를 구하시오. 각각의 동전은 몇 개라도 사용할 수 있다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.
*/
#include<iostream>
using namespace std;

int N, K;
int arr[101];
int memo[10001];

int dp()
{
	for (int i = 0; i < N; i++)// 동전 갯수만큼 반복
	{
		for (int j = arr[i]; j <= K; j++) //j = 동전 값 ~ (합)K까지
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