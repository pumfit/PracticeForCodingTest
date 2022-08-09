/*
2668 숫자고르기
https://www.acmicpc.net/problem/2668

세로 두 줄, 가로로 N개의 칸으로 이루어진 표가 있다. 첫째 줄의 각 칸에는 정수 1, 2, …, N이 차례대로 들어 있고 둘째 줄의 각 칸에는 1이상 N이하인 정수가 들어 있다. 첫째 줄에서 숫자를 적절히 뽑으면, 그 뽑힌 정수들이 이루는 집합과, 뽑힌 정수들의 바로 밑의 둘째 줄에 들어있는 정수들이 이루는 집합이 일치한다. 
이러한 조건을 만족시키도록 정수들을 뽑되, 최대로 많이 뽑는 방법을 찾는 프로그램을 작성하시오.

1~ N까지 사이클 가지는 지 판단하는 문제 사이클을 가진다면 답으로 포함하면 된다.

*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int cnt = 0;
int arr[101] = { 0, };
int visited[101] = { 0, };
vector<int> v;

bool DFS(int s, int i)
{
	if (visited[i])
	{
		if (s == i)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		visited[i] = 1;
		return DFS(s, arr[i]);
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		if (DFS(i, i))
		{
			v.push_back(i);
			cnt++;
		}
		memset(visited, 0, sizeof(visited));
	}
	cout << cnt << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
	return 0;
}