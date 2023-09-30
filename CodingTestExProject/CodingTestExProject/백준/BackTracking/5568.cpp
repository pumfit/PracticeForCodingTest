/*
5568 카드 놓기
https://www.acmicpc.net/problem/5568

backtracking 재활 훈련 bt 매개변수로 depth 가 아닌 i 넘겨줘서 값이 자꾸 이상하게 나오는데
처음에 값 나오는 거보고 ??상태되었다가 값 잘못넣은 거 보고 이마 짚은 문제
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n,k;
vector<string> v;
bool visited[11];
set<string> ans;

void bt(int depth,string str)
{

	if(depth == k)
	{
		ans.insert(str);
		return;
	}
	
	for(int i = 0 ;i <n; i++)
	{
		if(!visited[i])
		{
			visited[i] = true;
			bt(depth+1,str+v[i]);
			visited[i] = false;
		}
	}
	
}

int main() {
	cin>>n>>k;
	string str;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		v.push_back(str);
	}
		
	bt(0,"");
	cout<<ans.size();
	
	return 0;
}
