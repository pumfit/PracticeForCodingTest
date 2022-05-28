/*
2164 카드2

https://www.acmicpc.net/problem/2164
N장의 카드가 있다. 각각의 카드는 차례로 1부터 N까지의 번호가 붙어 있으며, 1번 카드가 제일 위에, N번 카드가 제일 아래인 상태로 순서대로 카드가 놓여 있다.
이제 다음과 같은 동작을 카드가 한 장 남을 때까지 반복하게 된다. 우선, 제일 위에 있는 카드를 바닥에 버린다. 그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.

큐 성질을 이용하여 풀면 되는 문제
*/
#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		q.push(i);
	while (q.size() > 1) {
		q.pop();
		int tmp = q.front();
		q.push(tmp);
		q.pop();
	}
	cout << q.front();
}