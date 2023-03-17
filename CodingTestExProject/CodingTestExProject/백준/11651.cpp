/*
11651 좌표 정렬하기2

좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

https://www.acmicpc.net/problem/11651
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 비교 함수
bool cmp(pair<int,int>& A, pair<int,int>& B)
{
	if(A.second<B.second) // y가 증가하는 순으로
	{
		return true;
	}
	else if(A.second==B.second) // 같은 경우에는 x 가 증가하는 순으로
	{
		return A.first<B.first;
	}else
	{
		return false;
	}
	 
}

int main() {
	int N;
	int x,y;
	vector<pair<int,int>> v;
	cin>>N;
	for(int i = 0;i<N;i++)
	{
		cin>>x>>y;
		v.push_back({x,y});
	}
	sort(v.begin(),v.end(),cmp);
	for(int i = 0;i<N;i++)
		cout<<v[i].first<<" "<<v[i].second<<"\n";
	return 0;
}