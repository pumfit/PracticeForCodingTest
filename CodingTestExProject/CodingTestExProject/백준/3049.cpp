/*
3049 다각형의 대각선

3각형 0 0
4각형 1 2 1
5각형 2 10 5
6각형 3 18 15
"대각선의 교차점"를 검색해보고 수학적 증명으로 nC4임을 알 수 있었다.
cout<<Factorial(N) / (Factorial(4)*Factorial(N - 4));로 처음에 구현했는데
100넣었더니 오버 플로우가 발생해서 컴비네이션을 구현했다.
삼각형으로 컴비네이션 푸는 방식을 떠올려서 해당 방식을 메모해가며 풀 수 있게 했더니
100을 넣어도 오버 플로가 발생하지 않았고 정답을 맞출 수 있었다.
*/
#include<iostream>
using namespace std;

long long memo[101][101] = { 0, };

long long Combination(int n,int r)
{
	if (memo[n][r] != 0)
		return memo[n][r];
	if (memo[n][r] == 0)
		return memo[n][r] = Combination(n - 1, r - 1) + Combination(n - 1, r );
}

int main()
{
	int	N;
	cin >> N;
	for (int i = 0; i < 101; i++)
	{
		memo[i][1] = i;
		memo[i][i] = 1;
	}
	if (N < 4)
	{
		cout << 0;
	}
	else if (N == 4)
	{
		cout << 1;
	}
	else
	{
		cout << Combination(N,4);
	}
}