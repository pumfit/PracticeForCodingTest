/*
2693�� N��° ū ��

T��ŭ �ݺ��ؼ� N��°��(N�� 3����) ū ���� ����ϴ� ����
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