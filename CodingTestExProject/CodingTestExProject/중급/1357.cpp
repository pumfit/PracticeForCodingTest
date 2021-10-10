/*
1357 뒤집힌 덧셈
Rev()함수를 구현해보자
*/
#include<iostream>
using namespace std;

int Rev(int n)
{
	int rev = 0;

	while (n > 0)
	{
		rev *= 10;
		rev += n % 10;
		n /= 10;
	}

	return rev;
}

int main()
{
	int x, y;
	cin >> x;
	cin >> y;

	cout << Rev(Rev(x)+Rev(y));
}
