/*
17626 Four Squares 

라그랑주는 1770년에 모든 자연수는 넷 혹은 그 이하의 제곱수의 합으로 표현할 수 있다고 증명하였다. 
어떤 자연수는 복수의 방법으로 표현된다. 예를 들면, 26은 52과 12의 합이다
또한 42 + 32 + 12으로 표현할 수도 있다. 
역사적으로 암산의 명수들에게 공통적으로 주어지는 문제가 
바로 자연수를 넷 혹은 그 이하의 제곱수 합으로 나타내라는 것이었다. 

1900년대 초반에 한 암산가가 15663 = 1252 + 62 + 12 + 12라는 해를 구하는데 8초가 걸렸다는 보고가 있다.
좀 더 어려운 문제에 대해서는 56초가 걸렸다: 11339 = 1052 + 152 + 82 + 52.

자연수 n이 주어질 때, n을 최소 개수의 제곱수 합으로 표현하는 컴퓨터 프로그램을 작성하시오.

 처음 보자마자 느낀건 dp문제인가..?
 50,000 이상의 제곱으로 대략 230을 잡아 제곱 배열을 만들었다.

1. N이 제곱인가 제곱이면 1
2. N보다 작은 제곱으로 나누어 떨어지는가? 나누어 떨어지면 나머지 수
3. N - N보다 작은 제곱 + 1
4. 제곱들의 합인 경우 (어떻게 )
*/
#include<iostream>
#include<algorithm>
using namespace std;

int squares[231] = {0,};
int memo[50001];

int dp(int n)
{
	cout << n << endl;
	int minSquare = 0,idx =0;
	for (int i = 0; minSquare <= n; ++i)
	{
		minSquare = squares[i];
		idx = i;
	}
	
	minSquare = squares[idx - 1];
	if (memo[n] != 0)
		return memo[n];
	else if (minSquare == n)
		return memo[n] = 1;
	else
		return memo[n] = min((dp(n - minSquare) + 1),dp(n-1)+1);
}
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i < 231; i++)
	{
		squares[i] = i * i;
		for (int j = 0; j < i; j++)
		{
			if (i*i + j * j > 50001)
				break;
				memo[i*i + j * j] = 2;
		}
		memo[i*i] = 1; memo[i*i + 1] = 2;
	}
		
	memo[1] = 1; memo[2] = 2; memo[3] = 3;
	cout << dp(N);

}