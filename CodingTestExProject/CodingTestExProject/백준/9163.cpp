/*
1963 소수 경로

https://www.acmicpc.net/problem/1963

시간 초과 나지 않을까 걱정하긴 했다. 1000~9999구간의 소수 개수는 1000개 정도 이고 체크마다 1000번정도 돌아가며 한 자리가 다른 지 체크해야한다.

*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int visited[10000] = {0,};
vector<int> v;

bool IsPrimeNumber(int n)
{
	for(int  i = 2; i * i <= n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

bool CheckChangedNumber(int a,int b)
{
	int cnt = 0;
	string as = to_string(a);
	string bs = to_string(b);
	for(int i = 0; i<as.size();i++)
	{
		if(as[i]!=bs[i])
			cnt++;
	}
	return cnt==1 ? true : false;
}

void bfs(int start,int target)
{
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	
	while(!q.empty())
	{
		int c = q.front();
		q.pop();
		for(int i = 0;i<v.size();i++)
		{
			if(visited[v[i]])
				continue;
			if(CheckChangedNumber(c,v[i]))
			{
				visited[v[i]] = visited[c] + 1;
				if(v[i]==target)
					return;
				q.push(v[i]);
			}
		}
	}
	
}

int main() {
	//1000~9999
	for(int i = 1000;i<10000;i++)
	{
		if(IsPrimeNumber(i))
			v.push_back(i);
	}
	int T;
	cin>>T;
	while(T--)
	{
		int A,B;
		cin>>A>>B;
		bfs(A,B);
		cout<<visited[B]-1<<'\n';
		memset(visited,0,sizeof(visited));
	}
	return 0;
}