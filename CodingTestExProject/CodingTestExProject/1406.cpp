/*
1406 ������

�� �ٷ� �� ������ �����͸� �����Ϸ��� �Ѵ�. �� ������� ���� �ҹ��ڸ��� ����� �� �ִ� �������, �ִ� 600,000���ڱ��� �Է��� �� �ִ�.

�� �����⿡�� 'Ŀ��'��� ���� �ִµ�, Ŀ���� ������ �� ��(ù ��° ������ ����), ������ �� ��(������ ������ ������), �Ǵ� ���� �߰� ������ ��(��� ���ӵ� �� ���� ����)�� ��ġ�� �� �ִ�. �� ���̰� L�� ���ڿ��� ���� �����⿡ �ԷµǾ� ������, Ŀ���� ��ġ�� �� �ִ� ���� L+1���� ��찡 �ִ�.

�� �����Ⱑ �����ϴ� ��ɾ�� ������ ����.
...

https://www.acmicpc.net/problem/1406

���� ���� ����Ʈ�� �̷���� stl list������ �����غ��Ҵ�.
���� iterator�� ��� ��Ŀ� ���� �� �� ���� �� �־���. ������ ���õ� ���ǵ��� iter�� ���� �������� ������ �ɾ� �������ָ� ���� ���۵Ǿ���.
���� ������ �κ��� erase()�Լ� ���µ� �ش� �Լ��� ���ϰ����� iterator�� ������ ���� ���� iter���� ����������Ѵ�.
https://hugssy.tistory.com/217

*/
#include <iostream>
#include <list>
using namespace std;

int main() {
	list<char> l;
	string s; int n;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		l.push_back(s[i]);
	cin >> n;
	list<char>::iterator iter = l.end();
	for (int i = 0; i < n; i++)
	{
		char command;
		cin >> command;
		if (command == 'L')
		{
			if (iter != l.begin())
				iter--;
		}
		else if (command == 'D')
		{
			if (iter != l.end())
				iter++;
		}
		else if (command == 'B')
		{
			if (iter != l.begin())
			{
				iter = l.erase(--iter);
			}

		}
		else if (command == 'P')
		{
			char c;
			cin >> c;
			l.insert(iter, c);
		}
	}
	for (auto c : l)
		cout << c;

	return 0;
}