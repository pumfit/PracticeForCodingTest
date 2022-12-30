/*
2295 세 수의 합
https://www.acmicpc.net/submit/2295/53278054

이분탐색 강의:
https://youtu.be/3TkaOKHxHnI

강의 내 힌트를 확인 하고 O(N^2logN)에 해당되는 풀이로 문제풀이를 진행했다.  a[i]+a[j] 를 배열로 두고 a[l] - a[k] 값이 있는 지 판단하는 방식으로 구현하면 O(N^2logN)이 된다.

a[i]+a[j]+a[k] = a[l] 이 경우 x, y, z, k가 서로 같아도 된다. 이때, k번째 수를 출력하면 된다.

처음풀이의 경우 저 조건을 모르고 두 합을 구한 two 의 두번째 for문 조건을 i = j+1 로 해서 58퍼 대에서 틀렸다.
같은 값을 포함해도 되므로 i = j 로 바꾼 후 통과했다.


*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	int n,k;
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cin>>k;
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	vector<int> two;
	for(int i = 0;i<v.size()-1;i++)
	{
		for(int j =i;j<v.size();j++)
		{
			two.push_back(v[i]+v[j]);
		}
	}
	sort(two.begin(),two.end());
	for(int i = v.size()-1;i>=0;i--)
	{
		for(int j = 0;j<i;j++)
		{
			if(binary_search(two.begin(),two.end(),v[i]-v[j]))
			{
				cout<<v[i];
				return 0;
			}
		}
	}
	return 0;
}