/*
2529 부등호
https://www.acmicpc.net/problem/2529

string 으로 정답을 구해가는 방식을 생각 해보지 않았는데 값을 아래 방식으로 넘겨 줄  수 있었다.
자리수에 조심해야하는 문제 비교하는 수 index랑 depth 제한이 K+1 임에 조심해야한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K;
char arr[10];
int num[10];
int visited[10];

vector<string> answer;

bool CheckValue(char prev,char next,char op)
{
	if(op == '<')
	{
		if(prev<next)
			return true;
	}else{
		if(prev>next)
			return true;
	}
	return false;
}

void BT(int depth,string num)
{
	if(depth == (K+1))
	{
		answer.push_back(num);
		return;
	}
	
	for(int i = 0;i<10;i++)
	{
		if(visited[i])
			continue;
			
		if(depth == 0 || CheckValue(num[depth-1],i+'0',arr[depth-1]))
		{
			visited[i] = true;
			BT(depth+1,num + to_string(i));
			visited[i] = false;
		}
	}
	
}

int main() {
	cin>>K;
	for(int i=0;i<K;i++)
		cin>>arr[i];
	BT(0,"");
	sort(answer.begin(),answer.end());
	
	cout<<answer[answer.size()-1]<<endl;
	cout<<answer[0];

	return 0;
}