/*
10164 격자상의 경로

행의 수가 N이고 열의 수가 M인 격자의 각 칸에 1부터 N×M까지의 번호가 첫 행부터 시작하여 차례로 부여되어 있다. 
격자의 어떤 칸은 ○ 표시가 되어 있다. (단, 1번 칸과 N × M번 칸은 ○ 표시가 되어 있지 않다. 또한, ○ 표시가 되어 있는 칸은 최대 한 개이다. 즉, ○ 표시가 된 칸이 없을 수도 있다.)

입력의 첫째 줄에는 격자의 행의 수와 열의 수를 나타내는 두 정수 N과 M(1 ≤ N, M ≤ 15), 그
리고 ○로 표시된 칸의 번호를 나타내는 정수 K(K=0 또는 1 < K < N×M)가 차례로 주어지며, 
각 값은 공백으로 구분된다. K의 값이 0인 경우도 있는데, 이는 ○로 표시된 칸이 없음을 의미한다. N과 M이 동시에 1인 경우는 없다.

처음 좌표 처리를 잘못해서 자꾸 틀렸던 문제

32점 -> 24점 -> 100점  모두 ㅇ 장소 좌표 처리 문제였다.

*/
#include <iostream>
#include <cstring>
using namespace std;

int N, M, K;
int x, y;
int map[16][16] = { 0, };

int dp(int x, int y)
{
	if (map[y][x] != 0)
		return map[y][x];
	else
		return map[y][x] = dp(x, y - 1) + dp(x - 1, y);
}

int main() {
	cin >> N >> M >> K;

	y = K % M == 0 ? K / M - 1 : K / M; x = K % M == 0 ? M - 1 : K % M - 1;
	if (K == 0)
		x = 0, y = 0;

	for (int i = 0; i <= x; i++)
		map[0][i] = 1;
	for (int i = 0; i <= y; i++)
		map[i][0] = 1;
	int n1 = dp(x, y);

	memset(map, 0, sizeof(map));
	for (int i = x; i < M; i++)
		map[y][i] = 1;
	for (int i = y; i < N; i++)
		map[i][x] = 1;
	int n2 = dp(M - 1, N - 1);

	cout << n1 * n2;
	return 0;
}