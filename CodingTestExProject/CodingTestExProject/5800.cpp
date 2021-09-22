/*
5800 ���� ���
ù° �ٿ� �ߴ� ����б��� �ִ� ���� �� K (1 �� K �� 100)�� �־�����. ���� K�� �ٿ��� �� ���� �л��� N (2 �� N �� 50)�� �� �л��� ���� ������ �־�����.
���� ������ 0���� ũ�ų� ����, 100���� �۰ų� ���� �����̰�, �������� �������� �ִ�.

������ �� ������ ������������ �������� �� ���� ū ������ ���� ���̸� ���� ��°� ���� �������� ����Ѵ�.
���� ���̸� �ݺ����� ���� �ִ밪�� �����־���.
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N[52] = {0,};

int main()
{
	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int k ;
		int max = 0;
		vector<int> arr;
		cin >> k;

		for (int j = 0; j < k; j++)
		{
			int n;
			cin >> n;
			arr.push_back(n);
		}
		sort(arr.begin(), arr.end());

		for (int j = k; j > 1; j--)
		{
			int z = arr[j-1] - arr[j-2];
			if (max < z)
				max = z;
		}

		cout << "Class " << i + 1<<endl;
		cout << "Max " << arr[k-1]<<", Min "<< arr[0]<<", Largest gap "<<max<<endl;
	}
}