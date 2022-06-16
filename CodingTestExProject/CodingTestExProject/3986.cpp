/*
3986 ���� �ܾ�
https://www.acmicpc.net/problem/3986

���̴� �ܾ� ���� ��ġ�� ��� �׾� ���� ���ڳ���(A�� A����, B�� B����) ���� ����� �Ͽ���. 
���� ������ �������� �����鼭 �� ���ڸ� ��Ȯ�� �� ���� �ٸ� ��ġ�� �ִ� ���� ���ڿ� ¦ ������ �ִٸ�, �� �ܾ�� '���� �ܾ�'�̴�. ���̰� '���� �ܾ�' ������ ���� ���� ��������.


������ ���ù��� ��ȣ ����ó�� �´� ¦�� ã���ִ� ���� ��� �ȴ�.
top�� ���� ��쿡 �̾��ֱ⸸ �ϸ� �Ǵ� ������ �� ����.
���� ������ ����ִٸ� ���� �ܾ �ȴ�.

���� ������ Ǯ��
			if (stk.size() && stk.top() == index) 
				stk.pop();
			else 
				stk.push(index);
������ ������� �ʴٴ� ���� stk.size()�� �Ǵ��ؼ� ������ �޾��ִ� ���ǹ��� �������� �����ʴ´�.
*/
#include <iostream>
#include <stack>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	int answer = 0;
	while (T--)
	{
		string str;
		cin >> str;
		stack<int> s;
		for (int i = 0; i < str.size(); i++)
		{
			if (s.empty())
				s.push(str[i]);
			else
			{
				if (s.top() == str[i])
				{
					s.pop();
				}
				else
				{
					s.push(str[i]);
				}
			}
		}
		if (s.empty())
			answer++;
	}
	cout << answer;
	return 0;
}