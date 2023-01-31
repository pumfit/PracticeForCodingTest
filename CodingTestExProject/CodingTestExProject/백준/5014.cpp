/*
5014 스타트 링크
https://www.acmicpc.net/problem/5014

10달전 풀이 틀렸길래 다시 풀어봤는데 문제 이해를 잘못했다.
"만약, U층 위, 또는 D층 아래에 해당하는 층이 없을 때는, 엘리베이터는 움직이지 않는다" 조건 맞게 고치니 통괔
*/
#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int visited[1000001] = {0,};

void bfs(int s){
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		if(x==G)
		{
			cout<<visited[x]-1;
			return;
		}
		for(int i = 0;i<2;i++)
		{
			int nx = x;
			if(i==0)
			{
				nx += U;
			}else{
				nx -= D;
			}
			if(nx<1||nx>F)
				continue;
			if(visited[nx])
				continue;
			visited[nx] = visited[x]+1;
			q.push(nx);
		}
	}
	cout<<"use the stairs";
}

int main() {

	cin>>F>>S>>G>>U>>D;

	bfs(S);
	
	return 0;
}