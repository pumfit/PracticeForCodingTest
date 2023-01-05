/*
걸그룹 마스터 준석이
https://www.acmicpc.net/problem/16165

해시 문제
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N,M;
	cin>>N>>M;
	map<string,string> nameMap;
	map<string,vector<string>> groupMap;
	for(int i = 0; i<N; i++)
	{
		string group,name; int n;
		cin>>group>>n;
		for(int j = 0;j<n;j++)
		{
			cin>>name;
			nameMap[name] = group;
			groupMap[group].push_back(name);
		}
	}
	for(int i = 0; i<M; i++)
	{
		int n;string s;
		cin>>s; cin>>n;
		if(n==1)
		{
			cout<<nameMap[s]<<'\n';
		}else
		{
			sort(groupMap[s].begin(),groupMap[s].end());
			for(int j = 0;j<groupMap[s].size();j++)
			{
				cout<<groupMap[s][j]<<'\n';
			}
		}
	}
	return 0;
}