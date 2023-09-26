/*
7795 먹을 것인가 먹힐 것인가
https://www.acmicpc.net/submit/7795/67220523

정렬 이후 전체 탐색 말고 이분 탐색하면 더 빠르겠다라고 생각만하고 그냥 전체탐색으로 풀이하기
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	int N,M;
	while(T--)
	{
		int answer = 0;
		cin>>N>>M;
		int A[N],B[M];
		for(int i = 0;i<N;i++)
			cin>>A[i];
		for(int i = 0;i<M;i++)
			cin>>B[i];
		sort(B,B+M);
		for(int i = 0;i<N;i++)
		{
			for(int j = 0;j<M;j++)
			{
				if(A[i]<=B[j])
					break;
				
				answer++;
			}
		}
		cout<<answer<<'\n';
	}
	return 0;
}