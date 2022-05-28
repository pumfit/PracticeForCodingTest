/*
11866 요세푸스 문제 0


# https://www.acmicpc.net/problem/11866
요세푸스 문제는 다음과 같다.
1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다.
한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다.
원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.
N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.

idx 인덱스를 나머지하여 구하기 때문에 가장 마지막 수 인 N에 대해서는 따로 예외처리를 한번 더 해준다. K만큼 인덱스를 더할때 만약 visited된 자리라면 건너뛰고 idx를 더한다.
이때 만나는 visited된 모든 자리를 넘어야하므로 while문을 사용해준다.

이전에 요세푸스 0문제를 풀면서 정리했었는데 그때 이후로 복습하는 느낌으로 진행했다. visited를 연속으로 체크하는데 있어서 한번만 체크하고 넘어가는
실수를 해 조금 걸렸지만 "배열을 통해 이미 지나간 자리는 지나간다"라는 개념으로 쉽게 풀 수 있었다.

*/

#include <iostream>
using namespace std;

int visited[1001];

int main() {
	int N, K;
	cin >> N >> K;
	int cnt = 0;
	int idx = 0;
	cout << "<";
	while (true)
	{
		if (cnt == N)
			break;
		for (int i = 0; i < K; i++)
		{
			idx++;
			if (visited[idx%N] == 1)
			{
				while (visited[idx%N] == 1)
					idx++;
			}
		}

		if (visited[idx%N] == 0)
		{
			visited[idx%N] = 1;
			if (idx%N == 0)
				cout << N;
			else
				cout << idx % N;
			if (cnt != N - 1)
				cout << ", ";
			cnt++;
		}

	}
	cout << ">";
	return 0;
}
