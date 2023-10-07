/*
1531 투명

세준이는 1×1크기의 그림으로 모자이크한 100×100크기의 그림을 가지고 있다. 어느 날 이 모자이크 중 일부 그림이 너무 보기 싫어서 N개의 불투명한 종이로 그림을 가리기 시작했다. 불투명한 종이로 가린다고 항상 그 그림이 안 보이는 것은 아니다. 그 그림의 현재 부분 위에 M개 이하의 종이가 올려져 있으면 그림은 그 부분에서 보이게 된다.

그림의 크기는 100×100이고, N개의 종이는 왼쪽 아래 모서리 좌표와 오른쪽 위 모서리 좌표가 입력으로 들어온다. 또, 종이가 가리는 영역에는 두 모서리의 좌표도 포함된다. 예를 들어, (1,1)부터 (2,2)를 가린다면, 총 4개의 그림이 가려진다. (1,1), (1,2), (2,1), (2,2).

100×100크기의 모자이크 중에 보이지 않는 그림의 개수를 세는 프로그램을 작성하시오.

https://www.acmicpc.net/problem/1531
*/
#include <iostream>
using namespace std;

int N, M;
int map[101][101] = { 0, };

void checkPixel(int x1, int y1, int x2, int y2)
{
	for (int i = y1; i <= y2; i++)
	{
		for (int j = x1; j <= x2; j++)
		{
			map[i][j]++;
		}
	}
}

int main() {
	int ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		checkPixel(x1 - 1, y1 - 1, x2 - 1, y2 - 1);
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] > M)
				ans++;
		}
	}
	cout << ans;
	return 0;
}