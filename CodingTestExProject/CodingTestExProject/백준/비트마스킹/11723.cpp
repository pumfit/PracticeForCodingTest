/*
11723 ����

��Ʈ����ŷ���� ���� �����ϱ�

��ɾ  3,000,000������ �־ 	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); ��������ϰ�
���� �� 70�ۼ�Ʈ �뿡�� Ʋ�ȴµ� all ������ (1<<20)-1�� �����Ͽ��� Ʋ�ȴ�.

*/
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	string C; int N;
	cin >> T;
	int S = 0;
	while (T--)
	{
		cin >> C;
		if (!(C == "all" || C == "empty"))
			cin >> N;
		if (C == "add")//�߰� ���� |
		{
			if (!(S & (1 << N)))//���� �˻� ��� �ʿ����
				S |= (1 << N); // OR ����
		}
		else if (C == "remove")//���� ���� & ~
		{
			if (S & (1 << N))
				S &= ~(1 << N); //& ���� 111 ���� 100�� �����ϴ� ��� ~(100)�� 011�� 111�� & ������ �ϸ� 011�� �ȴ�.
		}
		else if (C == "check")
		{
			if (S & (1 << N))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (C == "toggle")
		{
			if (S & (1 << N))
				S &= ~(1 << N);
			else
				S |= (1 << N);
		}
		else if (C == "all")// 1<<3 ��8�̰� 1000�̴�. ���⼭ -1 �� ���ָ� 7�̹Ƿ� 111�̵ȴ�. 
		// ���� 1<<(���ϴ� �ڸ���+1) -1 ������� ��� ���Ҹ� 1��  �ʱ�ȭ�� �� �ִ�.
		{
			S = (1 << 21) - 1;
		}
		else if (C == "empty") // ������
		{
			S = 0;
		}

	}
	return 0;
}