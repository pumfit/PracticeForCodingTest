/*
15663 N과M (9)

N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

N개의 자연수 중에서 M개를 고른 수열

https://www.acmicpc.net/problem/15663

수가 중복되는 경우를 제외해야하는데 이거를 어떻게 해야할까 고민하다가 prev를 쓰는 것 까지는 생각했는데
어떻게 구현해야할지 모르겠어서 어려웠던 문제
for문이 현재 idx에 대한 arr 내의 선택을 가지고 있으므로 여기서 선택된 값을 prev에 저장하고
이후 값과 비교해서 진행하면 되는 것이였다.

set으로 중복 거르고 풀어보았는데 해당 방식은 실패했다. 아래 참고
*/
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N, M;
int num[10] = { 0, };
int arr[10] = { 0, };
int visited[10] = { 0, };
int prevNum = 0;

void bf(int idx)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	int prev = 0;
	for (int i = 0; i < N; i++)
	{
		if (visited[i] == 0 && prev != num[i])
		{
			arr[idx] = num[i];
			prev = num[i];
			visited[i] = 1;
			bf(idx + 1);
			visited[i] = 0;
		}

	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);
	bf(0);
	return 0;
}
/*
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N,M;
int num[10] = {0,};
int arr[10] = {0,};
int visited[10] = {0,};
int prevNum = 0;
set<string> setNum;
void bf(int idx,int depth)
{
	if(depth==M)
	{
		string s ="";
		for(int i=0;i<M;i++)
		{
			s += to_string(arr[i]);
			s += ' ';
		}
		setNum.insert(s);
		return;
	}
	for(int i=0;i<N;i++)
	{
		if(visited[i]==0)
		{
			arr[idx] = num[i];
			visited[i] = 1;
			bf(idx+1,depth+1);
			visited[i] = 0;
		}

	}
}

int main() {
	cin>>N>>M;
	for(int i=0;i<N;i++)
		cin>>num[i];
	sort(num,num+N);
	bf(0,0);
	for(auto i:setNum)
		cout<<i<<'\n';
	return 0;
}
*/