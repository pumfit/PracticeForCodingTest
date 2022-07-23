/*
* 1967 트리의 지름 

OOB 때문에 미쳐버리는 줄 알았던 문제

처음엔 정말 무식하게 전체노드에서 가중치 최대 합들을 찾아 최대값을 출력했다.
해당 풀이도 체점결과가 100까지 가는 데 런타임에러로  OutOfBounds가 나왔고

이후 고민후 다른 풀이도 보니까 임의의 노드에서 가장 먼 노드를 찾고 해당 노드에서 가장 먼 노드까지의 거리가 지름임을 알게되었다.

테케나 다른 풀이, 질문을 봐도 모르다가 입력 케이스에 대해 다시 봤는데
12가 들어오고 n-1개가 들어오는데 범위를 0 부터 N으로 지정해두고 있었다...이부분 수정해주니까 통과했다
런타임에러만 4번 제출한 문제

트리의 특징 + DFS 관련해서 좀 더 문제풀어보고 감 잡으면 좋을 것 같다
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N = 0;
int answer = 0;
int maxNode = 0;
int maxCost = 0;

vector<pair<int, int>> tree[10005];
int visited[10005] = { 0, };

void DFS(int n, int sum)
{
	if (visited[n])
		return;
	if (sum > maxCost)
	{
		maxCost = sum;
		maxNode = n;
	}
	visited[n] = 1;
	for (int i = 0; i < tree[n].size(); i++)
	{
		int next = tree[n][i].first;
		int cost = tree[n][i].second;
		DFS(next, sum + cost);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int S, E, C;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> S >> E >> C;
		tree[S].push_back({ E,C });
		tree[E].push_back({ S,C });
	}

	DFS(1, 0);

	maxCost = 0;
	memset(visited, 0, sizeof(visited));

	DFS(maxNode, 0);

	cout << maxCost;
	return 0;
}