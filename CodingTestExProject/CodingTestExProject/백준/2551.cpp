/*
2551 물통

개인적으로 너무 어려웠던 문제 DP인가 도 생각헀다가 특정한 조건이 없이
여러 경우가 가능해서 dfs,bfs로 풀어야 겠다 생각하고 방법의 분기점이 많아
bfs로 전체 탐색하는 방식을 따라야 한다는 것을 알게 되었다. 다만
어떻게 물을 옮길 것인지에 대한 구현이 어려웠다.

참고 코드
https://rebas.kr/769
정리 포스팅
https://maybemine.tistory.com/entry/BOJ2251-%EB%AC%BC%ED%86%B5-BFS PW:1116

*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int A, B, C;
int visited[201][201] = {0,};
queue<pair<int, int>> q;
vector<int> v;

void pour(int a, int b)
{
	if (!visited[a][b])
	{
		visited[a][b] = 1;
		q.push(make_pair(a, b));
	}
}

void bfs()
{
	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int z = C - x - y;
		q.pop();
		if (x == 0)
			v.push_back(z);
		// A->B 로 옮기는 경우
		int water = min(x, B - y);//넘길 물의 양 a가 b랑 합해서 넘치지 않는 경우, 넘치는 경우
		pour(x - water, y + water);
		// A->C
		water = min(x, C - z);
		pour(x - water, y);
		// B->A
		water = min(y, A - x);
		pour(x + water, y - water);
		// B->C
		water = min(y, C - z);
		pour(x, y - water);
		// C->A
		water = min(z, A - x);
		pour(x + water, y);
		// C->B
		water = min(z, B - y);
		pour(x, y + water);
	}
}

int main()
{
	cin >> A >> B >> C;
	bfs();
	sort(v.begin(), v.end());
	for (int i=0;i<v.size();i++)
		cout << v[i] << " ";
}