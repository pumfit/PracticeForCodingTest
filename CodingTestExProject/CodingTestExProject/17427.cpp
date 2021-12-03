/*
17427 약수의 합2

문제 보고 dp 생각부터 나서
일단 합부터 계산해서 합 간의 연관성을 찾아보려는데 뚜렷하게 안보여서 일단 연속합을 계속 더하는 방식으로 풀었다.
해당 풀이에 1000000을 넣으니 2.31s로 절대 통과하지 못하는 풀이라 어떤 점화식이 있을 것 같다 까지는 생각이 들었지만 혼자서 찾지는 못 했다.
이후 찾아보니 합이 되는 약수들의 개수에서 연관성을 찾을 수 있었다.

생각해보면 1은 모든 수의 약수에 들어가므로 n의 약수의 합일때 n개가 들어간다.
1부터 n까지의 수를 i로 둘때 i=1 이면 n개 i=2 이면 n/2개 ... i 일때 n/i개 라는 것을 알 수 있다.


풀이 보면서 신기하다고 생각한 문제로
규칙을 알기만 하면 풀이는 어렵지않았던 수학 문제이다.
이런 규칙은 어떻게 찾아냈는지 신기한 기분이 들었다.
*/
#include <iostream>
using namespace std;

int main() {
	int N;
	long long sum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		sum += i * (N / i);
	}
	cout << sum;
	return 0;
}
/*
시간초과 풀이
#include <iostream>
using namespace std;

int memo[1000001]={0,};

int dp(int n)
{
	int sum =0;
	for(int i =1; i*i<=n;i++)
	{
		if(n%i==0)
		{
			sum+=i;
			if(i!=n/i)
				sum+=n/i;
		}
	}
	return sum;
}

int main() {
	int N;
	cin >> N;
	for(int i=1;i<=N;i++)
	{
		memo[i] = dp(i)+memo[i-1];
	}
	cout<<memo[N];
	return 0;
}
*/