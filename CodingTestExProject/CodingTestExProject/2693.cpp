/*
2693번 N번째 큰 수

T만큼 반복해서 N번째로(N은 3고정) 큰 수를 출력하는 문제
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int T;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vector<int> arr(10);
		for (int j = 0; j < 10; j++)
		{
			int N;
			cin >> N;
			arr[j] = N;
		}
		sort(arr.begin(), arr.end());
		cout << arr[7];
		if (i != T - 1)
			cout << "\n";
	}
}