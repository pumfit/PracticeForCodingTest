/*
2641 �ٰ����׸���

���� ���� ����
�����̵� ������ �����ϱ� �; Ǯ����ٰ� �׳� ������������.
���� for������ ��ü Ž���ؼ� �´��� �Ǵ��ϸ� �Ǵ� ����
�� �� ����ϰ� Ǯ �� ���� �� ������ �ݴ� ��쿡 ������ �ݴ�� �ȴٴ� ���� �� �̿��� Ǯ����Ѵ�.
���� �ݴ�� �����صΰ� ��� ����ߴ�.
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