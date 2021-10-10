/*
1712 손익분기점

손익분기점을 넘기는 문제인데 맨 처음 BF로 풀다가 시간초과가 났다.
문제에 주요 포인트는 변화하는 값이므로 증가값 : C-B가 A를 넘을 때를 찾으면 된다.
만약 B-C가 0이거나 그보다 작다면 +가 되지않으므로 -1를 출력한다.
*/
#include <iostream>
using namespace std;

int main() {
	long long A, B, C;
	cin >> A >> B >> C;

	int i = C - B;

	if (i <= 0)
	{
		cout << -1;
	}
	else
	{
		cout << A / i + 1;
	}

}