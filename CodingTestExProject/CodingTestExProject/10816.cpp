/*
10816 숫자 카드 2

숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 
정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.

https://www.acmicpc.net/problem/10816

STL upper_bound,lower_bound를 쓰는 방식과 쓰지 않고 구현하는 방식 둘 다 해봐야하는 문제
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[500005] = { 0, };

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int target; int cnt = 0;
		cin >> target;
		cout << upper_bound(num, num + N, target) - lower_bound(num, num + N, target) << ' ';
	}
	return 0;
}
/*
#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int num[500005] = {0,};

int lowerBound(int target)
{
	int start = 0;
	int end = N;
	while(start<end)
	{
		int mid = (start+end)/2;
		if(num[mid]<target)
		{
			start = mid+1;
		}else{
			end = mid;
		}
	}
	return start;
}

int upperBound(int target)
{
	int start = 0;
	int end = N;
	while(start<end)
	{
		int mid = (start+end)/2;
		if(num[mid]<=target)
		{
			start = mid+1;
		}else{
			end = mid;
		}
	}
	return start;
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>num[i];
	sort(num,num+N);
	cin>>M;
	for(int i=0;i<M;i++)
	{
		int target; int cnt = 0;
		cin>>target;
		cout<<upperBound(target)-lowerBound(target)<<' ';
	}
	return 0;
}
*/