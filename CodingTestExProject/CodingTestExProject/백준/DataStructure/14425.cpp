/*
14425 문자열 집합

https://www.acmicpc.net/problem/14425
*/
#include <iostream>
#include <vector>
#include<set>
using namespace std;

int N,M;
set<string> s;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>N>>M;
	string str;
	int answer = 0;
	for(int i = 0;i<N;i++)
	{
		cin>>str;
		s.insert(str);
	}
	for(int i = 0;i<M;i++)
	{
		cin>>str;
		v.push_back(str);
	}
	for(int i = 0;i<M;i++)
	{
		if(s.find(v[i])!=s.end())
			answer++;
	}
	cout<<answer;
	return 0;
}