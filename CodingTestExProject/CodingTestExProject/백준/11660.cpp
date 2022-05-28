/*
11660 구간 합 구하기 5

dp 안쓴 코드를 먼저 돌려보았을때 1퍼에서 시간초과로 통과하지 못했다.
문제 이해를 잘못해서 삽질 엄청하다가 이상해서 검색해보고 문제 파악을 잘못한 것을
알았다..좌표값 사이를 리턴하는게 아닌 사이 직사각형 범위내 합을 출력하는 것이었고 풀이를 수정했다.
시간 초과 엄청나다
*/
#include<iostream>
using namespace std;

int memo[1025][1025] = { 0, };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, T;
	cin >> N >> T;
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < N+1; j++)
		{
			int n;
			cin >> n;
			memo[i][j] = memo[i][j-1]+memo[i-1][j]-memo[i-1][j-1] + n;
		}
	}
	for (int i = 0; i < T; i++)
	{
		int sx, sy, nx, ny;
		int sum = 0;
		cin >> sy >> sx >> ny >> nx;

		cout << memo[ny][nx] - memo[sy - 1][nx] - memo[ny][sx-1] + memo[sy -1][sx - 1] << endl;;
	}
}