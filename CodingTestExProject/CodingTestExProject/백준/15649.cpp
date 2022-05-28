/*
15649 N과 M(1)

자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 
각 수열은 공백으로 구분해서 출력해야 한다.
수열은 사전 순으로 증가하는 순서로 출력해야 한다.

소스코드, 알고리즘 이론에 관련해서 아래 포스팅들에서 도움을 받았다.
https://st-lab.tistory.com/114,
https://cryptosalamander.tistory.com/54
*/
#include<iostream>
#include<cstring>
using namespace std;

int N, M;
int visited[9];
int arr[9];

void bf(int idx)//순서
{
	if (idx == M)//깊이가 M인 경우 탐방 중단
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++)//전체 N만큼 탐방
	{
		if (visited[i]==0)//방문 아닌 경우
		{
			visited[i] = 1;
			arr[idx] = i;
			bf(idx+1);
			visited[i] = 0;//방문 x로 변경
		}
	}
}

int main()
{
	cin >> N >> M;
	bf(0);

}