/*
1043 거짓말
https://www.acmicpc.net/problem/1043

파티에 참여한 인원과 연관된 인물에 대해서 체크를 하고 해당되는 인원이 없는 파티를 조사하면되는 그래프 문제이다.
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N,M;//사람의 수 N과 파티의 수 M
int visited[51];

vector<vector<int>> participants;
vector<int> linked[51];
vector<int> knowns;

int main() {
	cin>>N>>M;
	
	int answer = 0;
	int n,m;
	cin>>n;
	
	for(int i = 0;i<n;i++)
	{
		cin>>m;
		knowns.push_back(m);
	}

	for(int i = 0;i<M;i++)
	{
		cin>>n;
		vector<int> v;
		for(int j = 0;j<n;j++)
		{
			cin>>m;
			v.push_back(m);
		}
		participants.push_back(v);
        // 각 인원에 대해 참여해서 만날 수 있는 경우에 그래프 노드 생성 
		for(int j = 0;j<n-1;j++)
		{
			int x = v[j], y = v[j + 1]; 
            linked[x].push_back(y);
            linked[y].push_back(x);
		}
		
	}
	// 진실을 알고 있는 사람 기준으로 bfs 진행
	for(int i = 0; i < knowns.size(); i++)
	{
        int s = knowns[i];
        queue<int> q;
        q.push(s);
        visited[s] = 1;
 
        while(!q.empty())
        {
            int cur = q.front(); 
            q.pop();
            
            for(auto next : linked[cur]){
                if(visited[next] != 0) 
                	continue;
                q.push(next);
                visited[next] = 1;
            }
        }
    }
 
    for(int i = 0; i < M; i++){
        bool isAvailable = true;
        for(int j = 0; j < participants[i].size(); j++){
            if(visited[participants[i][j]] != 0) 
            	isAvailable = false;
        }
        if(isAvailable) 
        	answer++;
    }

    cout << answer;	

	return 0;
}