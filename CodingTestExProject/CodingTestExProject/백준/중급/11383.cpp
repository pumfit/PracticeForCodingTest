#include<iostream>
#include<string>
using namespace std;

int main()
{
	int N, M;
	string S[10], doubleS[10];

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> doubleS[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (S[i][j] != doubleS[i][2 * j + 1])
			{
				cout << "Not Eyfa";
				return 0;
			}
		}
	}
	cout << "Eyfa";
}