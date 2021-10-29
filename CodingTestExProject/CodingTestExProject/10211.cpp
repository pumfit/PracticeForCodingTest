/*

10211 Maximum Subarray



7번이나 왜맞틀한 문제.. 아주 여러번 풀어본  Maximum Subarray이지만 간과한 부분이 있었다.


먼저 들어오는 값의 범위를 간과하고 최대값 초기화를 0으로 해서 25퍼센트 대에 틀렸다.
이후 -1001으로 바꾸니 100퍼센트에서 틀려서 뭐지뭐지 하다가
dp 반복문에서 0이 아닌 1에서 부터 시작하는게 보였다. 설마..? 0의 값이 구간 최대라면 나는 이경우를 생각하지 않고 있었고
이전에 최대값 초기화를 max = dp[0] = arr[0]으로 바꿔 통과할 수 있었다.

이제부터 dp 구간 최대/최소 풀때 주의할 것
주어지는 수의 범위를 먼저 파악한다.
초기화 값 최소값/최대값 = dp[0] = arr[0] arr의 첫번째값으로 모두 초기화

항상 문제풀때 모든 경우를 포함하는지 생각하면서 코드를 작성하자
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		int m = -9999999;
		int arr[1001] = { 0, };
		int dp[1001] = { 0, };
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> arr[j];
		}
		m = dp[0] = arr[0];
		for (int j = 1; j < N; j++)
		{
			dp[j] = max(arr[j], dp[j - 1] + arr[j]);
			m = max(m, dp[j]);
		}
		cout << m << endl;
	}
	return 0;
}