/*
2863 이게 분수?

경우의 수가 0부터 3까지라서 17번 라인에 한번에 만들어 주었다. (반복문 쓰는게 더 어렵고 귀찮다고 생각해서)
분수이므로 int 가 아닌 float로 배열을 저장한다.
이때 들어오는 A,B,C,D값도 float로 설정해야한다. 계산값이 분수이므로 float로 변환되어야한다.
*/
#include<iostream>
using namespace std;

int main()
{
	float A, B, C, D;
	float arr[4] = { 0, };
	int cnt=0,max = 0;
	
	cin >> A >> B >> C >> D;

	arr[0] = A / C + B / D; 	arr[1] = C / D + A / B;		arr[2] = D / B + C / A;		arr[3] = B / A + D / C;

	max = arr[0];
	for (int i = 0; i < 4; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			cnt = i;
		}
	}
	cout << cnt;
}