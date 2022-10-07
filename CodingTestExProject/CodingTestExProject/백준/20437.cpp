/*
* ���ڿ� ���� 2
* https://www.acmicpc.net/problem/20437
* 
* �ι�° ���ɸ� ���鼭 �����̵� ������ �������� ���� ��Ҵ�.
* ���� �Ŀ� ���׸�Ʈ ������ ��ӳ��µ� �ε��� ������ �߻��ϴ� �� �˰� 1 aaa 1 ���� ���� � �� �����غ�������
�ε����� �Ѱų� ������ �����ϴ� ���� ������. 

���׸�Ʈ ������ ��� �߻��ϴ� ���� ���� �� �˻��غôµ�
���� �ʱ�ȭ���� �ʾ� ������ ���� ���� ��쿡�� �߻��� �� �ִٴ� ���� �˰ԵǾ���.
�����غ��� ���� �������� while������ �����µ� ch �迭�� �ʱ�ȭ���� �ʰ� �־���.  ���õ� ���ɰ� ���� ���ĺ��� ������ �����ʾƼ� ������ ���� �κ��̾���.
memset(ch, 0, sizeof(ch)); �߰��ϴ� ���׸�Ʈ ������ �ذ��� �� �־���.

+) Segfault ���� �� ������ ��
1. �ε��� Ȯ�� ���ǹ��� ���  (ch[index][1] + 1 < s.size() && s[i] != s[ch[index][1]]) ������ �켱������ �����Ƿ� �迭�� ���� �Ǵ��� ���� �տ� �α�
2. �ε����� ���� ���� ��� �����Ⱚ �ȵ����� ����
(�ƴϴ��� �ʱ�ȭ�� ����� Ȯ���ϱ�)
*/
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int T;
	cin >> T;
	string s;
	int k;
	int minCnt = 2e9, maxCnt = 0;
	int ch[26][2] = { 0, };//0 - ����ȸ�� ,1 - ù �ε���
	while (T--)
	{
		cin >> s;
		cin >> k;
		for (int i = 0; i < s.size(); i++)
		{
			int index = s[i] - 'a';
			ch[index][0]++;
			if (ch[index][0] == 1)
			{
				ch[index][1] = i;
			}
			if (ch[index][0] == k)//� ���ڸ� ��Ȯ�� K���� ����
			{
				//cout<<"ù �ε��� "<<ch[index][1]<<" | "<<i<<" "<<ch[index][1]+1<<endl;
				minCnt = min(i - ch[index][1] + 1, minCnt);
				maxCnt = max(i - ch[index][1] + 1, maxCnt);
				if (ch[index][1] + 1 < s.size())
					ch[index][1]++;
				while (ch[index][1] + 1 < s.size() && s[i] != s[ch[index][1]])//ù �ε��� ��ġ�� ���� ��ġ�� �ٲ�
				{
					ch[index][1]++;
				}
				ch[index][0]--;
			}
		}

		if (minCnt == 2e9 && maxCnt == 0)
			cout << -1 << '\n';
		else
			cout << minCnt << " " << maxCnt << '\n';
		minCnt = 2e9; maxCnt = 0;
		memset(ch, 0, sizeof(ch));
	}
	return 0;
}