/*
1654 랜선 자르기

N개 가 되는 랜선의 길이를 찾는 문제

탐색 후 해당값을 반환하는 것이 아닌 조건에 맞는 가장 큰 값을 반환해야하는 문제이다. upper_bound 구현 문제
ed 기준은 가장 큰 랜선을 기준으로 시작하면 된다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K,N;
vector<int> v;

int CheckWireCount(int maxLength)
{
	int cnt = 0;
	for(int i = 0;i<v.size();i++)
	{
		cnt += v[i]/maxLength;
	}
	return cnt;
}

int main() {
	cin>>K>>N;
	int n;
    long long st = 1;
	long long ed = 0;
    long long ans = 0;
	for(int i =0;i<K;i++)
	{
		cin>>n;
		v.push_back(n);
        if(n>ed)
            ed = n;
	}
	while(st<=ed)
	{
		long long mid = (st+ed)/2;
		int cnt = CheckWireCount(mid);
		if(cnt>=N)
		{
			st = mid+1;
            ans = max(ans,mid);
		}else
		{
			ed = mid-1;
		}
	}
    cout<<ans;
	return 0;
}