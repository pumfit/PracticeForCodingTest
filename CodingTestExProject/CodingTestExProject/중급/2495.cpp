/*
2495 연속구간

자리수도 정해져있고 각자리수는 0~9까지인 점을 활용해서 문제를 풀어나가면 된다.
연속되는 두 수가 동일한지만 판단하고 카운트를 올리면 되기 때문에 동일한 경우엔 카운트를 올리고
아닌 경우는 max값을 판단하도록 했다.

그리고 첫 제출에서 틀렸었는데 반복문이 끝나고 나서도 max값 확인을 한번 더 해줘야한다.
39-42line을 추가해주어서 통과하였다.
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		int num[10] = { 0, };
		int max = 0,m=0;

		string N;
		cin >> N;
		for (int j = 0; j < N.length()-1; j++)
		{
			if (N[j] == N[j + 1])
			{
				m++;
			}
			else
			{
				if (m + 1 > max)
				{
					max = m + 1;
				}
				m = 0;
			}
		}
		if (m + 1 > max)
		{
			max = m + 1;
		}

		cout << max <<endl;
	}
}