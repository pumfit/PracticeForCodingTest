/*
1021 회전하는 큐

지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다. 지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다.

지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.

첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
큐에 처음에 포함되어 있던 수 N이 주어진다. 그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다. (이 위치는 가장 처음 큐에서의 위치이다.) 이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.

https://www.acmicpc.net/problem/1021

덱을 사용하여 문제에서 주어진 대로 진행하고 둘중 더 작은 경우를 구하는 방식으로 진행했다.
해당 풀이 말고 인덱스를 구한 뒤 현재 위치와의 차이를 구해 푸는 방식도 있다.
*/
#include <iostream>
#include <deque>
using namespace std;

int main() {
	deque<int> d;
	int arr[51] = { 0, };
	int answer = 0;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		d.push_back(i + 1);
	for (int i = 0; i < M; i++)
		cin >> arr[i];
	for (int i = 0; i < M; i++)
	{
		int cntA = 0, cntB = 0;
		deque<int> tempA = d;
		deque<int> tempB = d;
		while (arr[i] != tempA.front())
		{
			int x = tempA.front();
			tempA.pop_front();
			tempA.push_back(x);
			cntA++;
		}
		while (arr[i] != tempB.front())
		{
			int x = tempB.back();
			tempB.pop_back();
			tempB.push_front(x);
			cntB++;
		}
		if (cntA > cntB) {
			d = tempB;
			answer += cntB;
		}
		else {
			d = tempA;
			answer += cntA;
		}
		d.pop_front();
	}
	cout << answer;
	return 0;
}