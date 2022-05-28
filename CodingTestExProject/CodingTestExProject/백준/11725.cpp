/*
11725 트리의 부모 찾기

트리 개념 + 시간초과

시간초과 에서 '\n' 사용하기 + ios_base::sync_with_stdio(flase); cin.tie(NULL); cout.tie(NULL);
트리의 개념에 대해서 좀 더 공부하고 트리와 순회 문제를 더 풀어보는 게 좋을 것 같다.
+)
해당 풀이는 dfs풀이 방식인데 bfs로도 풀어봐야겠다.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr[100001];
int parent[100001] = { 0, };
int N;

void dfs(int n)
{
	for (int i = 0; i < arr[n].size(); i++) //n과 연결된 모든 노드
	{
		int next = arr[n][i];//n과 연결된 노드
		if (parent[n] == next) //n의 부모가 이미 결정된 경우
			continue;
		parent[next] = n;//연결된 노드의 부모를 n으로 한 뒤 다음으로 넘어간다.
		dfs(next);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int A, B;
		cin >> A >> B;
		arr[A].push_back(B);//정점을 양방향 그래프로 연결
		arr[B].push_back(A);
	}
	dfs(1);//1번 노드부터 dfs 순회
	for (int i = 2; i <= N; i++)//2번 노드 부터 출력
		cout << parent[i] << '\n';
	return 0;
}