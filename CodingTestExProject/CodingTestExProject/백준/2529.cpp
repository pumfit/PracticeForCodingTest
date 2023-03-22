/*
2529 부등호
https://www.acmicpc.net/problem/2529

다시보기

백트래킹 복습하기 + 다른 유형 확인하기
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char arr[10];
int N;

void dfs(int depth,int prev,int visited[],vector<int>& v)
{
	if(depth==(N+1))
	{
		for(int i = 0;i<v.size();i++)
			cout<<v[i];
		cout<<endl;
		return;
	}
	
	for(int i = 0;i<10;i++)
	{
		if(visited[i])
			continue;
			
		if(depth==0)
		{
			v.push_back(i);
			visited[i] = 1;
			dfs(depth+1,i,visited,v);
			visited[i] = 0;
			v.pop_back();
			
		}
			
		if(arr[depth-1]=='<')
		{
			if(prev<i)
			{
				visited[i] = 1;
				v.push_back(i);
				dfs(depth+1,i,visited,v);
				v.pop_back();
				visited[i] = 0;
			}else{
				return;
			}
		}else if(arr[depth-1]=='>')
		{
			if(prev>i)
			{
				visited[i] = 1;
				v.push_back(i);
				dfs(depth+1,i,visited,v);
				v.pop_back();
				visited[i] = 0;
			}else{
				return;
			}
		}
	}
}

int main() {
	
	cin>>N;
	int visited[10] = {0,};
	for(int i = 0;i<N;i++)
		cin>>arr[i];
	vector<int> v;
	dfs(0,-1,visited,v);

	return 0;
}
