/*
1158 요세푸스 문제

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.

쉬울 줄 알았는데 어려웠던 문제
처음에 벡터로 풀려고 시도했다가 실패했다. 해당 문제풀이 유형이 많은데 정리하고 다시 풀어봐야할 것 같다.
큐를 이용한 풀이가 직관적이라 해당 풀이를 참고했다.
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, K;
	queue<int> q;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		q.push(i);
	cout << "<";
	while (!q.empty())
	{
		for (int i = 0; i < K - 1; i++)//K-1만큼 순서를 넘긴다
		{
			q.push(q.front());
			q.pop();
		}
		if (q.size() == 1) {
			cout << q.front() << ">";
			q.pop();
		}
		else {
			cout << q.front() << ", ";
			q.pop();
		}

	}
	return 0;
}