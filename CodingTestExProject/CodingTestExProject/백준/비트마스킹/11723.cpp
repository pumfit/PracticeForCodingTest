/*
11723 집합

비트마스킹으로 집합 연산하기

명령어가  3,000,000개까지 있어서 	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 꼭해줘야하고
제출 후 70퍼센트 대에서 틀렸는데 all 연산을 (1<<20)-1로 진행하여서 틀렸다.

*/
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	string C; int N;
	cin >> T;
	int S = 0;
	while (T--)
	{
		cin >> C;
		if (!(C == "all" || C == "empty"))
			cin >> N;
		if (C == "add")//추가 연산 |
		{
			if (!(S & (1 << N)))//조건 검사 사실 필요없음
				S |= (1 << N); // OR 연산
		}
		else if (C == "remove")//제거 연산 & ~
		{
			if (S & (1 << N))
				S &= ~(1 << N); //& 연산 111 에서 100을 제거하는 경우 ~(100)인 011과 111를 & 연산을 하면 011이 된다.
		}
		else if (C == "check")
		{
			if (S & (1 << N))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (C == "toggle")
		{
			if (S & (1 << N))
				S &= ~(1 << N);
			else
				S |= (1 << N);
		}
		else if (C == "all")// 1<<3 은8이고 1000이다. 여기서 -1 을 해주면 7이므로 111이된다. 
		// 따라서 1<<(원하는 자리수+1) -1 계산으로 모든 원소를 1로  초기화할 수 있다.
		{
			S = (1 << 21) - 1;
		}
		else if (C == "empty") // 공집합
		{
			S = 0;
		}

	}
	return 0;
}