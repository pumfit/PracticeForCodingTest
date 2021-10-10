/*
2720 세탁소 사장 동혁

거스름돈의 개수를 거슬러 주는 프로그래밍을 하는 문제이다.

+) 쉬운 문제라서 아래 영상으로 나온 Don't Look Back In Anger 들으면서 
노래 끝나기전에 제출까지 마쳤다. 그렇게 하라고 넣어둔 영상같다.
*/
#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		cout << N / 25 << " ";
		N %= 25;
		cout << N / 10 << " ";
		N %= 10;
		cout << N / 5 << " ";
		cout << N % 5 << endl;
	}
}