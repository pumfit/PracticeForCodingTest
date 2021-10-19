/*
1018 체스판 다시 칠하기

지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M*N 크기의 보드를 찾았다. 
어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 지민이는 이 보드를 잘라서 8*8 크기의 체스판으로 만들려고 한다.

체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 
구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 
변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다. 
따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.

보드가 체스판처럼 칠해져 있다는 보장이 없어서, 
지민이는 8*8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 
당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.

첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다.
B는 검은색이며, W는 흰색이다.

오랫만에 맞춘 문제..
처음 제출에 한번 틀렸는데 첫번째에 "W"이면 chessW와 비교하도록 하였는데
생각해보니 최소값이 다른 체스판인 경우도 가능해서 둘다 체크하고 최소값을 리턴하는 방식으로 변경하여 제출하였다.

처음에 문자열 처리를 string 단위로 생각하지 않았던 것도 조금 시간이 걸린문제
string 크기를 제한할 범위를 생각하다보니 조금 어려웠다.
*/
#include<iostream>
#include<string>
using namespace std;

string chessW[8] = { {"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"}, {"WBWBWBWB"},{"BWBWBWBW"}, {"WBWBWBWB"},{"BWBWBWBW"}};
string chessB[8] = { {"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"}, {"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"}};

string chess[50];

int check(int i,int j)
{
	string s[8];
	int cntW = 0;
	int cntB = 0;

	for (int k = i; k < i+8; k++)
	{
		s[k-i] = chess[k].substr(j, 8);
		
	}
	for (int k = 0; k < 8; k++)
	{
		for (int l = 0; l < 8; l++)
		{
			if (s[k][l] != chessW[k][l])
				cntW++;
		}

	}
	for (int k = 0; k < 8; k++)
	{
		for (int l = 0; l < 8; l++)
		{
			if (s[k][l] != chessB[k][l])
				cntB++;
		}
	}

	return cntW<cntB?cntW:cntB;
}

int main()
{
	int N, M;
	int min = 64;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> chess[i];
	}

	for (int i = 0; i <= N-8; i++)
	{
		for (int j = 0; j <= M-8; j++)
		{
			int m = check(i,j);
			if (m < min)
				min = m;
		}
	}
	cout << min;
}