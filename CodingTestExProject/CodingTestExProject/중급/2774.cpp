/*2774 �Ƹ��ٿ� ��

�Ƹ��ٿ� ���� ������ �� ���� �̷�� �ִ� 10������ ���� �ٸ� ������ ������ �ǹ��Ѵ�.
�̸� �迭�� ǥ���Ͽ� ����Ǯ�̸� �����Ͽ���.
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
		int cnt = 0;
		bool arr[10] = {false,};
		cin >> N;
		while (N>0)
		{
			if(arr[N%10]==false)
				arr[N % 10] = true;
			N /= 10;
		}
		for (int j = 0; j < 10; j++)
		{
			if (arr[j] == true)
				cnt++;
		}
		cout << cnt << endl;
	}
}