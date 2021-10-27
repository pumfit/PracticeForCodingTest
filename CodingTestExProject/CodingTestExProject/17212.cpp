/*
17212  달나라 토끼를 위한 구매대금 지불 도우미

달나라 토끼들이 사용하는 화폐는 동전뿐이다. 동전의 종류는 1원, 2원, 5원, 7원 이렇게 4종류가 있다. 
물건을 사고 동전으로 계산을 하는데 동전의 개수가 최소가 되도록 지불하지 않는 것은 불법이다. 
예를 들어, 17원을 지불할 때 7원짜리 동전 1개와 5원짜리 동전 2개로 지불해야 합법이고, 7원짜리 동전 2개와 2원짜리 동전 1개, 1원짜리 동전 1개로 지불해도 17원이 되지만, 총 동전의 개수가 4개가 되어 최소 개수가 아니므로 불법이다.

지불 금액을 입력받아 합법이 되는 동전 개수를 출력으로 내어주는 프로그램을 작성해보자.

dp에 대해 깨달음을 조금 얻은 것 같다.
직접 구현해가면서 예외 사항을 각 조건이 되는 1원,2원,5원,7원으로 처리해
그중 최소값을 dp에 저장하도록 구현하였다.
짧은 코드를 살펴보니 배수인 경우를 굳이 예외처리하지않고 fot문을 통해 arr[i] = min(arr[i-7],min(arr[i-1],min(arr[i-2],arr[i-5])))+1; 식으로 풀이하는 것을 보았고
대부분의 풀이가 재귀보다 반복문으로 전체 경우의 수를 구하는 방식을 사용한다는 것을 깨달았다.

+) 최소값을 반환하는데 algorithm의 min함수를 사용했는데 인자가 두개인 것을 생각하지 못하고 여러개 넣었다가 디버깅하면서 깨달았다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int memo[100001];
int N;

int dp(int n)
{
	if (n < 0)
		return N;
	if (memo[n] != 0)
		return memo[n];
	else
	{
		if (n % 2 == 0)
		{
			return memo[n] = min(min(min(dp(n - 1) + 1, dp(n - 2) + 1), min(dp(n - 5) + 1, dp(n - 7) + 1)), n / 2);
		}
		else if (n % 5 == 0)
		{
			return memo[n] = min(min(min(dp(n - 1) + 1, dp(n - 2) + 1), min(dp(n - 5) + 1, dp(n - 7) + 1)), n / 5);
		}
		else if (n % 7 == 0)
		{
			return memo[n] = min(min(min(dp(n - 1) + 1, dp(n - 2) + 1), min(dp(n - 5) + 1, dp(n - 7) + 1)), n / 7);
		}
		else
		{
			return memo[n] = min(min(dp(n - 1) + 1, dp(n - 2) + 1), min(dp(n - 5) + 1, dp(n - 7) + 1));
		}
	}

}

int main() {
	cin >> N;
	memo[1] = 1; memo[2] = 1; memo[3] = 2;
	cout << dp(N);
	return 0;
}