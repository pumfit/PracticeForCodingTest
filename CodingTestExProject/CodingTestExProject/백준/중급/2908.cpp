/*
2908 상수
이전 문제와 비슷한 문제로 복습 겸 선택
삼항연산자 사용
*/

#include<iostream>
using namespace std;

int Rev(int n)
{
	int sum = 0;

	while (n!=0)
	{
		sum *= 10;
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	int x, y;
	cin >> x;
	cin >> y;

	cout << ((Rev(x)>Rev(y))? Rev(x): Rev(y));
}