/*
1522 문자열 교환

https://www.acmicpc.net/problem/1522

어떻게 교환 횟수를 구할 수 있는지 고민 많이 한 문제 
전체 탐색이 필수적이겠다 생각하고 범위를 생각해보니 전체 a의 개수만큼 비교를 하고 b인 경우엔 교체 회수로 카운트해주면 된다.

+) 슬라이딩 윈도우로 2중 for문을 피할 수 있는 문제 
정해진 간격 cntA만큼 비교하면 되므로 i ~ i + cntA-1  사이 값을 모두 다시 구하는 것이아니라 양끝 값만 체크하면되는 기법이다.

슬라이딩 윈도우
https://wikidocs.net/154706
*/
#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int cntA = 0, cntB = 0;
	int size = s.size();

	// 문자열에 포함된 전체 a의 개수와 b의 개수를 구한다.
	for (int i = 0; i < size; i++)
	{
		if (s[i] == 'a')
		{
			cntA++;
		}
	}
	for (int i = 0; i < cntA; i++)
	{
		if (s[i] == 'b')
		{
			cntB++;
		}
	}
	// 초기값을 b의 개수로 초기화한다.
	int MinCnt = cntB;

	// 배열을 순회하면서 
	for (int i = 1; i < size; i++)
	{
		if (s[i - 1] == 'b')
		{
			cntB--;
		}
		if (s[(i + cntA - 1) % size] == 'b')
		{
			cntB++;
		}
		MinCnt = min(cntB, MinCnt);
	}
	cout << MinCnt;
	return 0;
}