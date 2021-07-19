/*
1110 더하기 사이클

두자리 수라서 자리수 나누기가 쉬웠던 문제
while문을 통해 반복적으로 카운트를 올리고
삼항연산자를 활용하여 첫째 자리 수가 어떤 수가 들어오는지 판단하고
이 사이클을 돌린 수가 들어온 N의 크기가 같은지 판단해서 탈출
*/
#include <iostream>
using namespace std;

int main() {
	int N = 0, ans = 0;
	cin >> N;

	int S = N;

	while (true)
	{
		ans++;

		if (S < 10)
		{
			S = S * 10 + S;
		}
		else
		{
			int i = (S % 10 + S / 10) >= 10 ? (S % 10 + S / 10) % 10 : (S % 10 + S / 10);
			S = (S % 10) * 10 + i;
		}
		if (S == N)
		{
			break;
		}
	}
	cout << ans;
	return 0;
}