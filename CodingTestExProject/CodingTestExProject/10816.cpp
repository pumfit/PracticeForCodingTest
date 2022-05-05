/*
10816 ���� ī�� 2

���� ī��� ���� �ϳ��� ������ �ִ� ī���̴�. ����̴� ���� ī�� N���� ������ �ִ�. 
���� M���� �־����� ��, �� ���� �����ִ� ���� ī�带 ����̰� �� �� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

https://www.acmicpc.net/problem/10816

STL upper_bound,lower_bound�� ���� ��İ� ���� �ʰ� �����ϴ� ��� �� �� �غ����ϴ� ����
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