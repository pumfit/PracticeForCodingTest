/*
2641 다각형그리기

쉬운 구현 문제
슬라이딩 윈도우 문제일까 싶어서 풀어보려다가 그냥 구현문제였다.
이중 for문으로 전체 탐색해서 맞는지 판단하면 되는 문제
좀 더 깔끔하게 풀 수 있을 것 같은데 반대 경우에 순서도 반대로 된다는 점을 잘 이용해 풀어야한다.
나는 반대로 저장해두고 계속 사용했다.
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[51];
	int reverseArr[51];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		int reverse = (arr[i] + 2) % 4 == 0 ? 4 : (arr[i] + 2) % 4;
		reverseArr[N - i - 1] = reverse;
	}
	int T;
	cin >> T;
	int testArr[101][51];

	int cnt = 0;
	vector<string> v;
	while (T--)
	{
		for (int i = 0; i < N; i++)
		{
			cin >> testArr[T][i];

		}

		for (int i = 0; i < N; i++)
		{
			int A = 0;
			for (int j = 0; j < N; j++)
			{
				if (testArr[T][j] == arr[(i + j) % N])
					A++;
				else
					break;
			}
			if (A == N)
			{
				string s = "";
				for (int j = 0; j < N; j++)
				{
					s += (testArr[T][j] + '0');
					s += " ";
				}
				v.push_back(s);
				cnt++;
			}
		}
		for (int i = 0; i < N; i++)
		{
			int B = 0;
			for (int j = 0; j < N; j++)
			{

				if (testArr[T][j] == reverseArr[(i + j) % N])
					B++;
				else
					break;

			}
			if (B == N)
			{
				string s = "";

				for (int j = 0; j < N; j++)
				{
					s += (testArr[T][j] + '0');
					s += " ";
				}
				v.push_back(s);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	return 0;
}