/*
1110 ���ϱ� ����Ŭ

���ڸ� ���� �ڸ��� �����Ⱑ ������ ����
while���� ���� �ݺ������� ī��Ʈ�� �ø���
���׿����ڸ� Ȱ���Ͽ� ù° �ڸ� ���� � ���� �������� �Ǵ��ϰ�
�� ����Ŭ�� ���� ���� ���� N�� ũ�Ⱑ ������ �Ǵ��ؼ� Ż��
*/
#include <iostream>
using namespace std;

int main() {
	int N = 0, ans = 0;
	cin >> N;

	int S = N;

	while (true)
	{
		ans++;

		if (S < 10)
		{
			S = S * 10 + S;
		}
		else
		{
			int i = (S % 10 + S / 10) >= 10 ? (S % 10 + S / 10) % 10 : (S % 10 + S / 10);
			S = (S % 10) * 10 + i;
		}
		if (S == N)
		{
			break;
		}
	}
	cout << ans;
	return 0;
}