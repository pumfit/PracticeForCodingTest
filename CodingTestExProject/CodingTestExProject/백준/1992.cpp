/*
1992 쿼드트리

흑백 영상을 압축하여 표현하는 데이터 구조로 쿼드 트리(Quad Tree)라는 방법이 있다. 흰 점을 나타내는 0과 검은 점을 나타내는 1로만 이루어진 영상(2차원 배열)에서 같은 숫자의 점들이 한 곳에 많이 몰려있으면, 쿼드 트리에서는 이를 압축하여 간단히 표현할 수 있다.

주어진 영상이 모두 0으로만 되어 있으면 압축 결과는 "0"이 되고, 모두 1로만 되어 있으면 압축 결과는 "1"이 된다. 만약 0과 1이 섞여 있으면 전체를 한 번에 나타내지를 못하고, 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래, 이렇게 4개의 영상으로 나누어 압축하게 되며, 이 4개의 영역을 압축한 결과를 차례대로 괄호 안에 묶어서 표현한다

	check(sx + N / 2, sy, N / 2);
	check(sx, sy + N / 2, N / 2);
이 부분 경계를 반대로 호출해서 답이 이상하게 나오는데 왜 그런 건지 못찾았던게 시간 걸린 이유

- char 배열 쓰지 않고 string 배열으로 풀기
- isSame 선언해서 쓰지않고 조건문 안에서 재귀를 실행해도 된다.
*/
#include <iostream>
using namespace std;

char map[65][65];

void check(int sx, int sy, int N) {

	char n = map[sy][sx];
	bool isSame = true;
	for (int i = sy; i < sy + N; i++)
	{
		for (int j = sx; j < sx + N; j++)
		{
			if (map[i][j] != n)
			{
				isSame = false;
				break;
			}
		}
		if (!isSame)
			break;
	}
	if (isSame)
	{
		cout << n;
		return;
	}
	cout << "(";
	check(sx, sy, N / 2);
	check(sx + N / 2, sy, N / 2);
	check(sx, sy + N / 2, N / 2);
	check(sx + N / 2, sy + N / 2, N / 2);
	cout << ")";
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			map[i][j] = s[j];
		}
	}
	check(0, 0, N);
	return 0;
}