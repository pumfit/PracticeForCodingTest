/*
12101 1,2,3 더하기 2

정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.
정수 n과 k가 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법 중에서 k번째로 오는 식을 구하는 프로그램을 작성하시오.
첫째 줄에 정수 n과 k가 주어진다. n은 양수이며 11보다 작고, k는 231-1보다 작거나 같은 자연수이다.

백트래킹 좀 더 공부하고자 도전해본 문제 생각 보다 쉽게 풀었긴한데 예외 처리가 어려웠던 문제이다.

1.depth 사실 depth보다 idx가 맞는데 어쩌다보니 배열의idx와 겹펴서 K의 깊이로 썼다. 맞는 경우 사전식으로 나열되는데 이걸 증가하는 방식으로 처리했다.
2.아닌 경우에 -1 출력 이걸 어떻게 할까 고민을 했는데 그냥 check를 하는 방식으로 마지막에 아니면 -1출력을 했다.

풀고 나서 더 좋은 풀이가 있을 것 같다는 생각이 들었다.
+) 그런데 찾아보니 대부분이 이와 비슷한 방식으로 풀이를 진행한 걸 알 수 있었다.
*/
#include <iostream>
using namespace std;

int N, K;
int arr[101];
int depth = 0;
bool isCheck = false;

void dfs(int idx, int sum)
{
	if (sum > N)
		return;
	if (sum == N)
	{
		depth++;
		if (depth == K)
		{
			isCheck = true;
			for (int i = 0; i < idx; i++)
			{
				if (i == idx - 1)
					cout << arr[i];
				else
					cout << arr[i] << "+";
			}
		}
		return;
	}
	for (int i = 1; i <= 3; i++)
	{
		arr[idx] = i;
		dfs(idx + 1, sum + i);
	}
}

int main() {
	cin >> N >> K;
	dfs(0, 0);
	if (!isCheck)
		cout << -1;
	return 0;
}