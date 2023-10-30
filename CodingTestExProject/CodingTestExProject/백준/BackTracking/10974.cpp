/*
10974 모든 순열
https://www.acmicpc.net/problem/10974

순열 공식
*/
#include <iostream>
using namespace std;

int N;
int visited[9] = {0,};
int arr[9] = {0,};

void dfs(int idx)
{
	if (idx == N)
	{
		for (int i = 0; i < N; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	for (int i = 1; i <= N; i++)
	{
		if(visited[i]==1)
			continue;
			
		visited[i] = 1;
		arr[idx] = i;
		dfs(idx+1);
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	dfs(0);
	return 0;
}