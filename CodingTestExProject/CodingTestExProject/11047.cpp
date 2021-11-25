/*

11047 동전 0

준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)
둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)


대표적인 그리디 문제
동전 개수의 최소를 구하는 문제이므로 가장 큰 동전 단위부터 나눌 수 있는지 확인해가도록 코드를 작성했다.
주어진 동전이 배수기에 그리디가 가능하다! 아니라면 다른 경우가 있을 수 있다.

*/
#include <iostream>
using namespace std;

int N, K;
int arr[10];
int minSum = 0;

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = N - 1; i >= 0; i--)
	{
		if (arr[i] <= K)
		{
			minSum += K / arr[i];
			K %= arr[i];
		}
		if (K == 0)
			break;
	}
	cout << minSum;
	return 0;
}