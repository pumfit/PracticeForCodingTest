/*
5397 Ű�ΰ�

â���̴� �������� ��й�ȣ�� ��ġ�� ���ؼ� �����̰� ����ϴ� ��ǻ�Ϳ� Ű�ΰŸ� ��ġ�ߴ�. 
��ĥ�� ��ٸ� ���� â���̴� �����̰� ��й�ȣ â�� �Է��ϴ� ���ڸ� ���´�.

Ű�ΰŴ� ����ڰ� Ű���带 ���� ����� ��� ����Ѵ�. 
����, �����̰� ��й�ȣ�� �Է��� ��, ȭ��ǥ�� �齺���̽��� �Է��ص� ��Ȯ�� ��й�ȣ�� �˾Ƴ� �� �ִ�.

�����̰� ��й�ȣ â���� �Է��� Ű�� �־����� ��, �������� ��й�ȣ�� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�. 
�����̴� Ű����� �Է��� Ű�� ���ĺ� �빮��, �ҹ���, ����, �齺���̽�, ȭ��ǥ�̴�.

https://www.acmicpc.net/problem/5397

iterator ����ó���� ����� �������� ��� ��Ÿ�� ������ �ߴµ� BOJ�� ������ ���� �ʾƼ� �ظ̴�.
������ ���  ���� ����Ǳ� ������ %--�� �غ� ��� ��Ÿ�ӿ����� ���� erase�� str.begin()���� Ȯ���� ���־� ����ó���� ���־� ����ߴ�.
*/
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		vector<char> l;
		list<char> str;
		for (int j = 0; j < s.size(); j++)
		{
			l.push_back(s[j]);
		}
		list<char>::iterator iter = str.end();
		for (int j = 0; j < l.size(); j++)
		{
			if (l[j] == '<')
			{
				if (iter != str.begin())
					iter--;
			}
			else if (l[j] == '>')
			{
				if (iter != str.end())
					iter++;
			}
			else if (l[j] == '-')
			{
				if (iter != str.begin())
					iter = str.erase(--iter);
			}
			else
			{
				str.insert(iter, s[j]);
			}
		}
		for (auto i : str)
			cout << i;
		cout << endl;
	}
	return 0;
}