/*
2954 â������ �ϱ���

â���̰� �ϱ��忡 �ۼ��� ������ ���� �������� �ٲپ� ����ϴ� ����.

�ϱ�� ����('a','e','i','o','u')�� ������ 'p'�� �ϳ� ����, �� ������ �ϳ� �� ����.
���� ���, "kemija" �� "kepemipijapa"�� �ǰ�, "paprika"�� "papapripikapa"�� �ȴ�.

�̶� ���忡 ������ ���µ� ������ ������ ���ڿ��� ��� ��������
std::getline()�� ����Ѵ�.

*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	string ans = "";

	getline(cin, s);

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] != 'a'&&s[i] != 'e'&&s[i] != 'i'&&s[i] != 'o'&&s[i] != 'u')
		{
			ans += s[i];
		}
		else
		{
			ans += s[i];
			i+=2;
		}
	}

	cout << ans;
}