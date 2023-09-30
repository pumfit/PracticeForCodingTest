/*
1941 소문난 칠공주
https://www.acmicpc.net/problem/1941

되게 이쁘게 섞여있는 문제
조합 + bfs 인데 풀아 자체를 생각해내기 어려웠다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

char map[6][6];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool IsLinked(vector<int> v)
{
	int checkedMap[5][5] = {0,};
	for(int i = 0;i<v.size();i++)
	{
		int x = v[i]%5;
		int y = v[i]/5;
		checkedMap[x][y] = 1;
	}
	
	int visited[5][5] = {0,};
	queue<pair<int,int>> q;
	q.push({v[0]%5,v[0]/5});
	int cnt = 0;
	
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		cnt++;
		for(int i = 0;i<4;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
		
			if(nx>=5||ny>=5||nx<0||ny<0)
				continue;
			
			if(visited[nx][ny]==1)
				continue;
			
			if(checkedMap[nx][ny]!=1)
				continue;
				
			visited[nx][ny] = 1;
			q.push({nx,ny});
		}
	}

	return cnt==8?true:false;
}

bool IsAvailable(vector<int> v)
{
	int a = 0,b = 0;
	for(int i = 0;i<v.size();i++)
	{
		int y = v[i]/5;
		int x = v[i]%5;
		if(map[y][x]=='S')
		{
			a++;
		}else{
			b++;
		}
	}
	return a>b;
}

int main() {
	string str;
	int answer = 0;
	for(int y = 0 ; y<5;y++)
	{
		cin>>str;
		for(int x = 0;x<5;x++)
		{
			map[x][y] = str[x];
		}
	}
	vector<int> v;

	for(int i = 0;i<18;i++)
		v.push_back(0);
	for(int i = 0;i<7;i++)
		v.push_back(1);
	do{
		vector<int> selected;
		for(int i = 0;i<25;i++)
		{
			if(v[i]==1)
				selected.push_back(i);
		}
		
		if(IsAvailable(selected))
		{
			if(IsLinked(selected))
				answer++;
		}
		
	}while(next_permutation(v.begin(),v.end()));
	cout<<answer;
	return 0;
}