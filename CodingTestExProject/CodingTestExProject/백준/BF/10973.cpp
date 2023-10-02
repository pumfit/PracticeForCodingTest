/*
10973 이전 순열
https://www.acmicpc.net/problem/10973
시간 초과 풀이

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,n;
vector<int> origin;

bool IsTargetArray(vector<int> v)
{
	for(int i = 0;i<N;i++)
	{
		if(v[i]!=origin[i])
			return false;
	}
	return true;
}

int main() {
	cin>>N;
	vector<int> v(N);
	for(int i = 0;i<N;i++)
		v[i] = i + 1;
	for(int i = 0;i<N;i++)
	{
		cin>>n;
		origin.push_back(n);
	}
	string answer = "";
	do{
		if(IsTargetArray(v))
		{
			break;
		}else{
			answer = "";
			for(int i = 0;i<v.size();i++)
			{
				answer += to_string(v[i])+" ";
			}
		}
	}while(next_permutation(v.begin(),v.end()));
	if(answer == "")
		cout<<"-1";
	else
		cout<<answer;

	return 0;
}