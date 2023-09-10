/*
1676 ���丮�� 0�� ����

������ ª�Ƽ� �������� �� �ϰ� �ִٰ�
�׽�Ʈ ���̽� ���� ����غ��� �����ߴ�.

���丮�� ��곻�� 10�� ����� �Ǵ� ���� �󸶳� �Ǵ��� ����Ѵ�.
�� 10, (10�� ������ƴ�) 5,(10�� ������ƴ�) 2 ����� ������ ���ϸ� �ȴ�.

���� �����ϰ� �ƴ� ��� ���ǿ��� Ż���ϰ� �ϴ� ���� �̹� ����Ǯ���� ����Ʈ �� �� ����.
*/

#include<iostream>
using namespace std;

int main()
{
	int N;
	int F = 0,T = 0;
	int ans = 0;

	cin >> N;

	while (N > 0)
	{
		int temp = N;
		while (true)
		{
			if (temp % 10 == 0)
			{
				ans++;
				temp /= 10;
			}
			else if (temp % 5 == 0)
			{
				F++;
				temp /= 5;
			}
			else if (temp % 2 == 0)
			{
				T++;
				temp /= 2;
			}
			else
			{
				break;
			}
		}
		N--;
	}
	ans += F >= T ? T : F;
	cout << ans;
}