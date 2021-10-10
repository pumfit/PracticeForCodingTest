#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

vector<int> graph[101];
bool visited[101];

bool isTrim(int x, int y, int A, int B)
{
	if (x == A && y == B)
		return true;
	else if (x == B && y == A)
		return true;
	return false;
}

int dfs(int N, int A, int B)
{
	int sum = 1;
	for (int i = 0; i < graph[N].size(); i++)
	{
		if (!visited[graph[N][i]] && !isTrim(N, graph[N][i], A, B))
		{
			visited[graph[N][i]] = true;
			sum += dfs(graph[N][i], A, B);
		}
	}
	return sum;
}

int solution(int n, vector<vector<int>> wires) {
	int answer = 101;
	int A = 0, B = 0;
	for (int i = 0; i < wires.size(); i++)
	{
		graph[wires[i][0]].push_back(wires[i][1]);
		graph[wires[i][1]].push_back(wires[i][0]);
	}
	//끊을 와이어를 하나 선택
	for (int i = 0; i < wires.size(); i++)
	{
		memset(visited, false, sizeof(visited));
		A = wires[i][0];
		B = wires[i][1]; //각각 출발 dfs
		visited[A] = true; visited[B] = true;
		int one = dfs(A, A, B);
		int two = dfs(B, A, B);
		int c = one - two >= 0 ? one - two : two - one;
		if (answer > c)
			answer = c;
	}

	return answer;
}