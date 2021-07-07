/*
2442 별찍기5

홀수 2n-1
"출력 형식이 잘못되었습니다" 처음 떠봐서 놀랐는데
이유는 뒤에도 공백 추가했더니 생기는 결과였다.
*/
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < ( (2*n - 1) / 2 )-i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * (i+1) - 1; j++)
		{
			cout << "*";
		}
		if(i!=n-1)
			cout << "\n";
	}
}