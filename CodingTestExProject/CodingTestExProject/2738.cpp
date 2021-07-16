/*
2738번 행렬덧셈

행렬 이차원 배열
1.먼저 두개의 배열을 초기화하고
해당배열에 입력된 값이 잘들어갔는지 확인
2.맞다면 더한 값을 해당 조건에 맞게 출력하기

제출 결과 시간 : 4ms 길이 : 560B 가 나왔다.
+) 시간 적은 결과는 어떻게 가능한지 더 생각해보기
*/

#include<iostream>

using namespace std;

int main()
{
	int A[100][100] = { 0,{0,} }, B[100][100] = { 0,{0,} };
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			int c;
			cin >> c;
			A[j][i] = c;
		}
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			int c;
			cin >> c;
			B[j][i] = c;
		}
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << A[j][i]+B[j][i];
			if (j != b - 1)
				cout << " ";
		}
		if(i!=a-1)
			cout << "\n";
	}
}