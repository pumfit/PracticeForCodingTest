/*
2312 �� �����ϱ�

���� ���� N�� �־����� ��, �� ���� ���μ����� �� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���� �ѹ��� �����ڵ��ߴ�.
��� �����ָ鼭 ��µǵ��� ����Ǯ�̸� �����Ͽ���.
*/
#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		
		int k = 2;

		while (N!=1)
		{
			if (N%k == 0)
			{
				int d = 0;
				while (N%k == 0)
				{
					d++;
					N /= k;
				}
				cout << k << " " << d << endl;
			}
			else
			{
				k++;
			}
		}

	}
}