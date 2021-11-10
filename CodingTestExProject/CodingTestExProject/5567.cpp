/*

5567 결혼식

상근이는 자신의 결혼식에 학교 동기 중 자신의 친구와 친구의 친구를 초대하기로 했다. 상근이의 동기는 모두 N명이고,

이 학생들의 학번은 모두 1부터 N까지이다. 상근이의 학번은 1이다.

상근이는 동기들의 친구 관계를 모두 조사한 리스트를 가지고 있다.

이 리스트를 바탕으로 결혼식에 초대할 사람의 수를 구하는 프로그램을 작성하시오.



처음보자마자 완전 이중연결리스트 bfs 문제

생각했던건 3단계이하까지 구해주지 않아도 되니 조건문을 if(visitList[y]==0&&visitList[x]<3)로 하여 bfs를 실행했다.

제출하기전 테케가 답이 3인데 4가 나왔는데 범위에 1(자신)을 포함해서 였다.

다른 문제들 처럼 답에서 -1해주면 두번째 테케가 통과되지 않으므로 반복문에서 i가 2부터 시작되어야 한다.



https://www.acmicpc.net/source/35222975

갯수 구할때 bfs나와서 반복문 쓰지 말고 bfs내부에서 구해서 시간 단축하기

*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[501];
int visitList[501];

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			if (visitList[y] == 0 && visitList[x] < 3)
			{
				visitList[y] = visitList[x] + 1;
				q.push(y);
			}
		}
	}
}

int main() {
	int N, M;
	int cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}
	bfs(1);
	for (int i = 2; i < N + 1; i++)
	{
		if (visitList[i] > 0 && visitList[i] < 3)
		{
			cnt++;
		}

	}
	cout << cnt;
	return 0;
}